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

```cpp#include <ADS1115.h>

ADS1115 ads;

void setup() {
    Serial.begin(115200);
    
    // Initialize ADS1115 with selected voltage range, sample rate, and mode
    ads.begin(RANGE_4_096V, SPS_128, SINGLE_SHOT_MODE);
    
    // ads.begin(RANGE_6_144V, SPS_860, CONTINUOUS_MODE); // Alternative option

    /*
      Available sample rate (SPS) options:
      SPS_8    = 8 SPS
      SPS_16   = 16 SPS
      SPS_32   = 32 SPS
      SPS_64   = 64 SPS
      SPS_128  = 128 SPS (default)
      SPS_250  = 250 SPS
      SPS_475  = 475 SPS
      SPS_860  = 860 SPS (fastest)

      Available voltage range (RANGE) options:
      RANGE_6_144V = ±6.144V
      RANGE_4_096V = ±4.096V
      RANGE_2_048V = ±2.048V (default)
      RANGE_1_024V = ±1.024V
      RANGE_0_512V = ±0.512V
      RANGE_0_256V = ±0.256V

      Available ADC modes:
      CONTINUOUS_MODE  = The ADC continuously converts data in the background.
      SINGLE_SHOT_MODE = The ADC takes a single measurement when requested, then powers down to save energy.
    */
}

void loop() {
    ads.readAllChannels();

    for (int i = 0; i < 4; i++) {
        Serial.print("AIN");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(ads.getValue(i));
    }

    Serial.println();
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
