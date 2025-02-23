#include "My_ADS_1115.h"

My_ADS_1115::My_ADS_1115(uint8_t address) {
  _address = address;
}

void My_ADS_1115::begin(ADCRange range, SampleRate rate, ADCMode mode) {
  _range = range;
  _rate = rate;
  _mode = mode;
  Wire.begin();
}

void My_ADS_1115::configureADC(ADS_MUX mux) {
  uint16_t config = 0x8000;  // Start single conversion

  // Set MUX
  config |= mux;

  // Set gain
  config |= _range;

  // Set mode
  config |= _mode;

  // Set sample rate
  config |= _rate;

  // Disable comparator
  config |= 0x0003;

  Wire.beginTransmission(_address);
  Wire.write(0x01);
  Wire.write(config >> 8);
  Wire.write(config & 0xFF);
  Wire.endTransmission();
}

int16_t My_ADS_1115::readADC() {
  Wire.beginTransmission(_address);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(_address, (uint8_t)2);

  if (Wire.available() == 2) {
    return (Wire.read() << 8) | Wire.read();
  }
  return 0;
}

int16_t My_ADS_1115::readChannel(uint8_t channel) {
  if (channel > 3) return 0;
  ADS_MUX mux = (ADS_MUX)(ADS_MUX_AIN0_GND + (channel * 0x1000));
  configureADC(mux);
  delay(10);
  return readADC();
}

int16_t My_ADS_1115::readDifferential(ADS_MUX mux) {
  configureADC(mux);
  delay(10);
  return readADC();
}

