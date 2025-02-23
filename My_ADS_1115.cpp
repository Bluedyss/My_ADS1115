#include "My_ADS_1115.h"

My_ADS_1115::My_ADS_1115() {}

void My_ADS_1115::begin(ADCRange range, SampleRate rate, ADCMode mode) {
  currentRange = range;
  currentSampleRate = rate;
  currentMode = mode;
  Wire.begin();
}

void My_ADS_1115::configureADC(uint8_t channel) {
  uint16_t config = 0x8583;

  // Set mode (Bit 8)
  config &= ~(0x0100);
  config |= currentMode;

  // Set sample rate (Bits 7-5)
  config &= ~(0x00E0);
  config |= currentSampleRate;

  // Set voltage range (Bits 11-9)
  config &= ~(0x0E00);
  config |= currentRange;

  // Set MUX channel selection (Bits 14-12)
  config &= ~(0x7000);
  config |= muxSettings[channel];

  // Write configuration to ADS1115
  Wire.beginTransmission(ADS1115_ADDRESS);
  Wire.write(0x01);
  Wire.write(config >> 8);
  Wire.write(config & 0xFF);
  Wire.endTransmission();
}

int16_t My_ADS_1115::readADC() {
  Wire.beginTransmission(ADS1115_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(ADS1115_ADDRESS, 2);

  if (Wire.available() == 2) {
    return (Wire.read() << 8) | Wire.read();
  }
  return 0;
}

void My_ADS_1115::readAllChannels() {
  for (int i = 0; i < 4; i++) {
    configureADC(i);
    delay(100);
    Serial.print("AIN");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(readADC());
  }
  Serial.println();
}
