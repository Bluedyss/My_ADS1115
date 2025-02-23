#include <My_ADS_1115.h>

// Initialize ADS1115 with default address (0x48)
My_ADS_1115 ads(0x48);

void setup() {
  Serial.begin(115200);

  // Initialize ADS1115 with:
  // - Voltage range: ±4.096V
  // - Sample rate: 128 SPS
  // - Mode: Single-shot
  ads.begin(RANGE_4_096V, SPS_128, SINGLE_SHOT_MODE);

  /*
  === CONFIGURATION OPTIONS ===
  
  Voltage Range (PGA):
  RANGE_6_144V  → ±6.144V
  RANGE_4_096V  → ±4.096V (Default)
  RANGE_2_048V  → ±2.048V
  RANGE_1_024V  → ±1.024V
  RANGE_0_512V  → ±0.512V
  RANGE_0_256V  → ±0.256V

  Sample Rate:
  SPS_8   → 8 SPS
  SPS_16  → 16 SPS
  SPS_32  → 32 SPS
  SPS_64  → 64 SPS
  SPS_128 → 128 SPS (Default)
  SPS_250 → 250 SPS
  SPS_475 → 475 SPS
  SPS_860 → 860 SPS

  Mode:
  SINGLE_SHOT_MODE  → Reads one sample per request (Default)
  CONTINUOUS_MODE   → Continuously updates data
  */

  /*
  === I2C ADDRESS CONFIGURATION ===
  Default address: 0x48
  Possible addresses: 0x48, 0x49, 0x4A, 0x4B

  Change Address Example:
  My_ADS_1115 ads(0x49);
  ads.begin(RANGE_2_048V, SPS_250, CONTINUOUS_MODE);
  */
}

void loop() {
  Serial.print("AIN0: ");
  Serial.println(ads.readChannel(0));

  Serial.print("AIN1: ");
  Serial.println(ads.readChannel(1));

  Serial.print("AIN2: ");
  Serial.println(ads.readChannel(2));

  Serial.print("AIN3: ");
  Serial.println(ads.readChannel(3));

  Serial.println("------------------");
  delay(1000);
}
