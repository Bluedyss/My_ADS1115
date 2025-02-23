# My_ADS_1115 Library

## Overview
The **My_ADS_1115** library provides an easy-to-use interface for the ADS1115 16-bit ADC. It supports both single-ended and differential readings, configurable sampling rates, input voltage ranges, and operation modes.

## Features
- Read from single-ended or differential inputs
- Adjustable I²C address
- Configurable sample rate, input voltage range, and mode
- Supports continuous and single-shot operation
- Simple API for integration into Arduino projects

## Installation
1. Download the repository as a ZIP file.
2. Extract and place the `My_ADS_1115` folder inside your Arduino `libraries` directory.
3. Restart the Arduino IDE.

## I²C Address Configuration
The ADS1115 supports 4 different I²C addresses based on the ADDR pin connection:

| ADDR Pin | I²C Address |
|----------|------------|
| GND      | 0x48 (default) |
| VDD      | 0x49 |
| SDA      | 0x4A |
| SCL      | 0x4B |

Example usage:
```cpp
ads.address(0x49);  // Set I²C address to 0x49
```

## API Usage
### Initialize the ADS1115
```cpp
#include <My_ADS_1115.h>

My_ADS_1115 ads;

void setup() {
    Serial.begin(115200);
    ads.begin(RANGE_4_096V, SPS_128, SINGLE_SHOT_MODE);
    ads.address(0x48);  // Set the I²C address (default: 0x48)
}
```

### Read from a single-ended channel
```cpp
int16_t value = ads.readChannel(0);  // Read from AIN0
Serial.println(value);
```

### Read from a differential channel
```cpp
int16_t value = ads.readDifferential(0, 1);  // Read AIN0 - AIN1
Serial.println(value);
```

## Configuration Options
### Input Voltage Range (PGA)
| Setting         | Full-Scale Voltage |
|----------------|-------------------|
| RANGE_6_144V   | ±6.144V |
| RANGE_4_096V   | ±4.096V |
| RANGE_2_048V   | ±2.048V (default) |
| RANGE_1_024V   | ±1.024V |
| RANGE_0_512V   | ±0.512V |
| RANGE_0_256V   | ±0.256V |

### Sample Rate
| Setting  | Samples per Second (SPS) |
|----------|-------------------------|
| SPS_8    | 8 |
| SPS_16   | 16 |
| SPS_32   | 32 |
| SPS_64   | 64 |
| SPS_128  | 128 (default) |
| SPS_250  | 250 |
| SPS_475  | 475 |
| SPS_860  | 860 |

### Operation Mode
| Mode               | Description |
|--------------------|-------------|
| CONTINUOUS_MODE    | Continuously converts samples |
| SINGLE_SHOT_MODE   | Takes one sample and enters low-power mode (default) |

## Examples
### Single-ended Read Example
Check `examples/Single_example.ino` for reading single-ended channels.

### Differential Read Example
Check `examples/Diff_example.ino` for differential readings.

## License
This library is released under the MIT License.


