#include <SoftwareSerial.h>
#include <SPI.h>

// Defined all the pins needed
#define RX_PIN 30
#define TX_PIN 31

#define IMU_INT_PIN 2
#define IMU_CS_PIN 3

#define MEM_CS_PIN 4
#define MEM_HOLD_PIN 6
#define MEM_WP_PIN 5

#define SPI_SCK_PIN 13
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 12

#define SWITCH_PIN 9
#define D8_PIN 8
#define D7_PIN 7

// Function definitions
void initSPI();
void writeCommand(int cs, uint8_t command);
void writeByte(int cs, uint16_t data);
uint8_t readByte(int cs, uint8_t addr);

// Define states
bool pcConnected = false;

// Define variables
uint8_t fifoData[140 * 7];
uint16_t numEntries;

uint32_t address = 0x00000000;
uint32_t addressTemp = 0;

void setup() {
  delay(20);

  Serial.begin(57600);

  // Initialize the pins
  pinMode(IMU_INT_PIN, INPUT);
  pinMode(IMU_CS_PIN, OUTPUT);
  digitalWrite(IMU_CS_PIN, HIGH);
  pinMode(MEM_CS_PIN, OUTPUT);
  digitalWrite(MEM_CS_PIN, HIGH);
  pinMode(MEM_HOLD_PIN, OUTPUT);
  digitalWrite(MEM_HOLD_PIN, HIGH);
  pinMode(MEM_WP_PIN, OUTPUT);
  digitalWrite(MEM_WP_PIN, HIGH);
  pinMode(SWITCH_PIN, INPUT);
  pinMode(D8_PIN, OUTPUT);
  digitalWrite(D8_PIN, HIGH);
  pinMode(D7_PIN, OUTPUT);
  digitalWrite(D7_PIN, LOW);

  initSPI();

  // Initialize the IMU
  // Set the gyro and accel to write to FIFO at 52 Hz
  writeByte(IMU_CS_PIN, 0x0933);
  
  // Configure INT1 to trigger on FIFO full and COUNTER_BDR_IA
  writeByte(IMU_CS_PIN, 0x0D60);

  // Configure the batch counter to toggle at 128
  writeByte(IMU_CS_PIN, 0x0B00);
  writeByte(IMU_CS_PIN, 0x0C40);

  // Configure the gyro and accel to poll at 52 Hz
  writeByte(IMU_CS_PIN, 0x1030);
  writeByte(IMU_CS_PIN, 0x1130);

  // Enable the timestamp counter
  writeByte(IMU_CS_PIN, 0x1920);

  if (digitalRead(SWITCH_PIN) == HIGH) {
    pcConnected = true;
  } else {
    pcConnected = false;

    int status = readByte(MEM_CS_PIN, 0x05);
    while (status & 0x01) {
      status = readByte(MEM_CS_PIN, 0x05);
    }

    // Erase the memory
    writeCommand(MEM_CS_PIN, 0x06);

    status = readByte(MEM_CS_PIN, 0x05);
    while (!(status & 0x02)) {
      status = readByte(MEM_CS_PIN, 0x05);
    }

    digitalWrite(MEM_CS_PIN, LOW);
    SPI.transfer(0x52);
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    digitalWrite(MEM_CS_PIN, HIGH);

    status = readByte(MEM_CS_PIN, 0x05);
    while (status & 0x01) {
      status = readByte(MEM_CS_PIN, 0x05);
    }

    delay(2000);
  }

  // Set the FIFO to FIFO mode
  writeByte(IMU_CS_PIN, 0x0A80);  // Reset the FIFO first
  writeByte(IMU_CS_PIN, 0x0A81);

  address = 0x00000000;
}

void loop() {
  if (!pcConnected) {
    while (1) {
      // Check the interrupt pin
      if (digitalRead(IMU_INT_PIN) == HIGH) {
        // Get the number of entries in the FIFO
        uint8_t fifoEntries;
        fifoEntries = readByte(IMU_CS_PIN, 0xBA);

        // Serial.println(fifoEntries);

        int j = 0;
        for (int i = 0; i < fifoEntries; ++i) {
          fifoData[j++] = readByte(IMU_CS_PIN, 0xF8); // Tag byte
          fifoData[j++] = readByte(IMU_CS_PIN, 0xFA); // Upper x byte
          fifoData[j++] = readByte(IMU_CS_PIN, 0xF9); // Lower x byte
          fifoData[j++] = readByte(IMU_CS_PIN, 0xFC); // Upper y byte
          fifoData[j++] = readByte(IMU_CS_PIN, 0xFB); // Lower y byte
          fifoData[j++] = readByte(IMU_CS_PIN, 0xFE); // Upper z byte
          fifoData[j++] = readByte(IMU_CS_PIN, 0xFD); // Lower z byte
        }

        ++numEntries;

        // DEBUG INFO - Prints the IMU information
        // j = 0;
        // for (int i = 0; i < 136; i++) {
        //   uint8_t t = fifoData[j++];
        //   int16_t d;
        //   if ((t & 0xF8) == 16) {
        //     // Serial.print("  ");
        //     Serial.print(t, DEC);
        //     Serial.print("  ");
        //     d = (fifoData[j++] << 8) | fifoData[j++];
        //     Serial.print((d * 0.061 * 9.80665 / 1000) * 0.101971621, DEC);
        //     Serial.print("  ");
        //     d = (fifoData[j++] << 8) | fifoData[j++];
        //     Serial.print((d * 0.061 * 9.80665 / 1000) * 0.101971621, DEC);
        //     Serial.print("  ");
        //     d = (fifoData[j++] << 8) | fifoData[j++];
        //     Serial.print((d * 0.061 * 9.80665 / 1000) * 0.101971621, DEC);
        //     // Serial.print(" g");
        //     Serial.print("\r\n   ");
        //   } else if ((t & 0xF8) == 32) {
        //     uint32_t time = 0;
        //     Serial.print(t, DEC);
        //     Serial.print("  ");
        //     time = ((fifoData[j + 2] << 24) | (fifoData[j + 3] << 16) | (fifoData[j] << 8) | fifoData[j + 1]);
        //     j += 6;
        //     Serial.print(time, DEC);
        //     Serial.print("\r\n   ");
        //     // Serial.print(" us\r\n");
        //   } else if((t & 0xF8) == 8) {
        //     Serial.print(t, DEC);
        //     Serial.print("  ");
        //     d = (fifoData[j++] << 8) | fifoData[j++];
        //     Serial.print((d * 0.017453293 * 8.75 / 1000) * 57.2958, DEC);
        //     Serial.print("  ");
        //     d = (fifoData[j++] << 8) | fifoData[j++];
        //     Serial.print((d * 0.017453293 * 8.75 / 1000) * 57.2958, DEC);
        //     Serial.print("  ");
        //     d = (fifoData[j++] << 8) | fifoData[j++];
        //     Serial.print((d * 0.017453293 * 8.75 / 1000) * 57.2958, DEC);
        //     // Serial.print(" deg/s");
        //     Serial.print("\r\n   ");
        //   } else {
        //     Serial.println(fifoData[j]);
        //     j += 6;
        //   }
        // }

        // Reset the FIFO buffer
        writeByte(IMU_CS_PIN, 0x0A80);
        writeByte(IMU_CS_PIN, 0x0A81);

        // Set the write enable latch
        writeCommand(MEM_CS_PIN, 0x06);

        // Write the data to memory
        digitalWrite(MEM_CS_PIN, LOW);
        SPI.transfer(0x02);
        SPI.transfer(0x00);
        SPI.transfer(0x00);
        SPI.transfer(0x00);
        SPI.transfer16(numEntries);
        digitalWrite(MEM_CS_PIN, HIGH);

        // Check that the memory isn't busy everytime before writing
        int status = 0;
        status = readByte(MEM_CS_PIN, 0x05);
        while (status & 0x01) {
          status = readByte(MEM_CS_PIN, 0x05);
        }

        // Set the write enable latch
        writeCommand(MEM_CS_PIN, 0x06);

        address += 0x100;
        addressTemp = address >> 16;
        // Write to the first block of memory
        digitalWrite(MEM_CS_PIN, LOW);
        SPI.transfer(0x02);
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address >> 8;
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address;
        SPI.transfer((uint8_t)addressTemp);

        // OLD CODE CHANGED TO LINE BELOW
        // for (int i = 0; i < 256; ++i) {
        //   SPI.transfer(fifoData[i]);
        // }

        SPI.transfer(&fifoData[0], 256);

        digitalWrite(MEM_CS_PIN, HIGH);

        delay(5);

        status = readByte(MEM_CS_PIN, 0x05);
        while (status & 0x01) {
          status = readByte(MEM_CS_PIN, 0x05);
        }

        // Set the write enable latch
        writeCommand(MEM_CS_PIN, 0x06);

        address += 0x100;
        addressTemp = address >> 16;
        // Write to the second block of memory
        digitalWrite(MEM_CS_PIN, LOW);
        SPI.transfer(0x02);
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address >> 8;
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address;
        SPI.transfer((uint8_t)addressTemp);

        // for (int i = 0; i < 256; ++i) {
        //   SPI.transfer(fifoData[i + 256]);
        // }

        SPI.transfer(&fifoData[256], 256);

        digitalWrite(MEM_CS_PIN, HIGH);

        delay(5);

        status = readByte(MEM_CS_PIN, 0x05);
        while (status & 0x01) {
          status = readByte(MEM_CS_PIN, 0x05);
        }

        // Set the write enable latch
        writeCommand(MEM_CS_PIN, 0x06);

        address += 0x100;
        addressTemp = address >> 16;
        // Write to the third free block for the next entry block
        digitalWrite(MEM_CS_PIN, LOW);
        SPI.transfer(0x02);
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address >> 8;
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address;
        SPI.transfer((uint8_t)addressTemp);

        // for (int i = 0; i < 256; ++i) {
        //   SPI.transfer(fifoData[i + 512]);
        // }

        SPI.transfer(&fifoData[512], 256);

        digitalWrite(MEM_CS_PIN, HIGH);

        delay(5);

        status = readByte(MEM_CS_PIN, 0x05);
        while (status & 0x01) {
          status = readByte(MEM_CS_PIN, 0x05);
        }

        // Set the write enable latch
        writeCommand(MEM_CS_PIN, 0x06);

        address += 0x100;
        addressTemp = address >> 16;
        // Write to the third.5 free block for the next entry block
        digitalWrite(MEM_CS_PIN, LOW);
        SPI.transfer(0x02);
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address >> 8;
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address;
        SPI.transfer((uint8_t)addressTemp);

        // for (int i = 0; i < 184; ++i) {
        //   SPI.transfer(fifoData[i + 768]);
        // }

        SPI.transfer(&fifoData[768], 184);

        digitalWrite(MEM_CS_PIN, HIGH);

        delay(5);
      }
    }
  } else {
    while (1) {
      uint8_t fifoEntries;

      int status = readByte(MEM_CS_PIN, 0x05);
      while (status & 0x01) {
        status = readByte(MEM_CS_PIN, 0x05);
      }

      // Get the number of entries in the memory
      digitalWrite(MEM_CS_PIN, LOW);
      SPI.transfer(0x03);
      SPI.transfer(0x00);
      SPI.transfer(0x00);
      SPI.transfer(0x00);
      fifoEntries = SPI.transfer16(0x00);
      digitalWrite(MEM_CS_PIN, HIGH);

      // Grab all the information in the one continuous read
      address = 0x100;
      while(1) {
        // Read the first data block
        addressTemp = address >> 16;
        // Write to the first free block for the next entry block
        digitalWrite(MEM_CS_PIN, LOW);
        SPI.transfer(0x03);
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address >> 8;
        SPI.transfer((uint8_t)addressTemp);
        addressTemp = address;
        SPI.transfer((uint8_t)addressTemp);

        uint16_t temp;
        bool brk = false;
        int k = 0;
        for (int j = 0; j < 476; ++j) {
          temp = SPI.transfer16(0x00);
          // Serial.println(temp);
          fifoData[k++] = temp >> 8;
          fifoData[k++] = temp;
        }

        digitalWrite(MEM_CS_PIN, HIGH);

        address += 0x400;
        Serial.println("\n\n");
        // Print what was read
        int j = 0;
        for (int i = 0; i < 136; i++) {
          uint8_t t = fifoData[j++];
          int16_t d;
          if ((t & 0xF8) == 16) {
            // Serial.print("  ");
            Serial.print(t, DEC);
            Serial.print("  ");
            d = (fifoData[j++] << 8) | fifoData[j++];
            Serial.print((d * 0.061 * 9.80665 / 1000) * 0.101971621, DEC);
            Serial.print("  ");
            d = (fifoData[j++] << 8) | fifoData[j++];
            Serial.print((d * 0.061 * 9.80665 / 1000) * 0.101971621, DEC);
            Serial.print("  ");
            d = (fifoData[j++] << 8) | fifoData[j++];
            Serial.print((d * 0.061 * 9.80665 / 1000) * 0.101971621, DEC);
            // Serial.print(" g");
            Serial.print("\r\n   ");
          } else if ((t & 0xF8) == 32) {
            uint32_t time = 0;
            Serial.print(t, DEC);
            Serial.print("  ");
            time = ((fifoData[j + 2] << 24) | (fifoData[j + 3] << 16) | (fifoData[j] << 8) | fifoData[j + 1]);
            j += 6;
            Serial.print(time, DEC);
            Serial.print("\r\n   ");
            // Serial.print(" us\r\n");
          } else if((t & 0xF8) == 8) {
            Serial.print(t, DEC);
            Serial.print("  ");
            d = (fifoData[j++] << 8) | fifoData[j++];
            Serial.print((d * 0.017453293 * 8.75 / 1000) * 57.2958, DEC);
            Serial.print("  ");
            d = (fifoData[j++] << 8) | fifoData[j++];
            Serial.print((d * 0.017453293 * 8.75 / 1000) * 57.2958, DEC);
            Serial.print("  ");
            d = (fifoData[j++] << 8) | fifoData[j++];
            Serial.print((d * 0.017453293 * 8.75 / 1000) * 57.2958, DEC);
            // Serial.print(" deg/s");
            Serial.print("\r\n   ");
          } else {
            // Serial.println(fifoData[j]);
            Serial.println(" ");
            if (fifoData[j] == 0xFF && fifoData[j + 1] == 0xFF && fifoData[j + 2] == 0xFF && fifoData[j + 3] == 0xFF && fifoData[j + 4] == 0xFF && fifoData[j + 5] == 0xFF && fifoData[j + 6] == 0xFF) {
              brk = true;
              break;
            }

            j += 6;
          }
        }

        if (brk == true) {
          Serial.println("DONE");
          break;
        }
      }
      for (;;);
    }
  }
}



void initSPI() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));

  pinMode(SPI_SCK_PIN, OUTPUT);
  digitalWrite(SPI_SCK_PIN, LOW);

  pinMode(SPI_MOSI_PIN, OUTPUT);
  digitalWrite(SPI_MOSI_PIN, HIGH);

  pinMode(SPI_MISO_PIN, INPUT);
}

void writeCommand(int cs, uint8_t command) {
  digitalWrite(cs, LOW);
  SPI.transfer(command);
  digitalWrite(cs, HIGH);
}

void writeByte(int cs, uint16_t data) {
  digitalWrite(cs, LOW);
  SPI.transfer16(data);
  digitalWrite(cs, HIGH);
}

uint8_t readByte(int cs, uint8_t addr) {
  uint8_t result = 0;
  digitalWrite(cs, LOW);
  SPI.transfer(addr);
  result = SPI.transfer(0x00);
  digitalWrite(cs, HIGH);
  return result;
}