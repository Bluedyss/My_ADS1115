# My_ADS_1115 Arduino Library

A simple library for interfacing with the ADS1115 ADC using I2C.

## Features
- Configure voltage range, sample rate, and mode.
- Read from all four channels.
- Uses I2C communication.

## Installation
1. Download the ZIP file.
2. Extract it to your Arduino `libraries` folder.
3. Restart the Arduino IDE.

## Usage

### Example Code

```cpp
#include "My_ADS_1115.h"

My_ADS_1115 ads;

void setup() {
  Serial.begin(115200);
  ads.begin(RANGE_4_096V, SPS_128, CONTINUOUS_MODE);
}

void loop() {
  ads.readAllChannels();
  delay(1000);
}
```

## Settings

### Sample Rate (SPS):
- `SPS_8`, `SPS_16`, `SPS_32`, `SPS_64`, `SPS_128`, `SPS_250`, `SPS_475`, `SPS_860`

### Voltage Range (PGA):
- `RANGE_6_144V`, `RANGE_4_096V`, `RANGE_2_048V`, `RANGE_1_024V`, `RANGE_0_512V`, `RANGE_0_256V`

### Modes:
- `CONTINUOUS_MODE` - Continuously measures ADC values.
- `SINGLE_SHOT_MODE` - Takes a single measurement and stops.
