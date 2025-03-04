#include <My_ADS_1115.h>

My_ADS_1115 ads;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    
    ads.address(0x48); // Default I2C address

    // ADS1115 supports 4 different I²C addresses based on the ADDR pin connection:
    // 0x48 ,0x49 ,0x4A ,0x4B
    
    ads.begin(RANGE_6_144V, SPS_128, SINGLE_SHOT_MODE);

    // ===== Available Configurations =====
    // Voltage Ranges (PGA - Programmable Gain Amplifier):
    // RANGE_6_144V  -> ±6.144V (default)
    // RANGE_4_096V  -> ±4.096V
    // RANGE_2_048V  -> ±2.048V
    // RANGE_1_024V  -> ±1.024V
    // RANGE_0_512V  -> ±0.512V
    // RANGE_0_256V  -> ±0.256V

    // Sample Rates:
    // SPS_8   -> 8 Samples per second
    // SPS_16  -> 16 SPS
    // SPS_32  -> 32 SPS
    // SPS_64  -> 64 SPS
    // SPS_128 -> 128 SPS (default)
    // SPS_250 -> 250 SPS
    // SPS_475 -> 475 SPS
    // SPS_860 -> 860 SPS

    // Operating Modes:
    // SINGLE_SHOT_MODE   -> Each read starts a new conversion
    // CONTINUOUS_MODE    -> ADC continuously converts values
}

void loop() {
    for (int i = 0; i < 4; i++) {
        int16_t value = ads.readChannel(i);
        Serial.print("AIN");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(value);
    }
    delay(1000);
}
