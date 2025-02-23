#ifndef MY_ADS_1115_H
#define MY_ADS_1115_H

#include <Wire.h>

#define ADS1115_ADDRESS 0x48  // Default I2C address

// Enum for setting sample rate
typedef enum {
  SPS_8 = 0x0000,
  SPS_16 = 0x0020,
  SPS_32 = 0x0040,
  SPS_64 = 0x0060,
  SPS_128 = 0x0080,
  SPS_250 = 0x00A0,
  SPS_475 = 0x00C0,
  SPS_860 = 0x00E0
} SampleRate;

// Enum for setting voltage range (PGA)
typedef enum {
  RANGE_6_144V = 0x0000,
  RANGE_4_096V = 0x0200,
  RANGE_2_048V = 0x0400,  // (default)
  RANGE_1_024V = 0x0600,
  RANGE_0_512V = 0x0800,
  RANGE_0_256V = 0x0A00
} ADCRange;

// Enum for setting mode (Bit 8)
typedef enum {
  CONTINUOUS_MODE = 0x0000,
  SINGLE_SHOT_MODE = 0x0100
} ADCMode;

class My_ADS_1115 {
public:
  My_ADS_1115();
  void begin(ADCRange range, SampleRate rate, ADCMode mode);
  void configureADC(uint8_t channel);
  int16_t readADC();
  void readAllChannels();
private:
  SampleRate currentSampleRate;
  ADCRange currentRange;
  ADCMode currentMode;
  uint16_t muxSettings[4] = {0x4000, 0x5000, 0x6000, 0x7000};
};

#endif
