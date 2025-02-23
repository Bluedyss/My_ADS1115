#ifndef MY_ADS_1115_H
#define MY_ADS_1115_H

#include <Wire.h>

#define DEFAULT_ADS1115_ADDRESS 0x48  // Default I2C address

// Enum for setting sample rate
typedef enum {
  SPS_8 = 0x0000,
  SPS_16 = 0x0020,
  SPS_32 = 0x0040,
  SPS_64 = 0x0060,
  SPS_128 = 0x0080,  // Default
  SPS_250 = 0x00A0,
  SPS_475 = 0x00C0,
  SPS_860 = 0x00E0
} SampleRate;

// Enum for setting voltage range (PGA)
typedef enum {
  RANGE_6_144V = 0x0000,
  RANGE_4_096V = 0x0200,
  RANGE_2_048V = 0x0400,  // Default
  RANGE_1_024V = 0x0600,
  RANGE_0_512V = 0x0800,
  RANGE_0_256V = 0x0A00
} ADCRange;

// Enum for setting mode
typedef enum {
  SINGLE_SHOT_MODE = 0x0100,
  CONTINUOUS_MODE = 0x0000
} ADCMode;

// Enum for MUX settings
typedef enum {
  ADS_MUX_AIN0_AIN1 = 0x0000,
  ADS_MUX_AIN0_AIN3 = 0x1000,
  ADS_MUX_AIN1_AIN3 = 0x2000,
  ADS_MUX_AIN2_AIN3 = 0x3000,
  ADS_MUX_AIN0_GND  = 0x4000,
  ADS_MUX_AIN1_GND  = 0x5000,
  ADS_MUX_AIN2_GND  = 0x6000,
  ADS_MUX_AIN3_GND  = 0x7000
} ADS_MUX;

class My_ADS_1115 {
public:
  My_ADS_1115(uint8_t address = DEFAULT_ADS1115_ADDRESS);
  void begin(ADCRange range, SampleRate rate, ADCMode mode);
  int16_t readChannel(uint8_t channel);
  int16_t readDifferential(ADS_MUX mux);
  
private:
  uint8_t _address;
  ADCRange _range;
  SampleRate _rate;
  ADCMode _mode;
  void configureADC(ADS_MUX mux);
  int16_t readADC();
};

#endif
