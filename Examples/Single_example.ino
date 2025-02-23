#include <My_ADS_1115.h>

My_ADS_1115 ads;

void setup() {
    Serial.begin(115200);
    ads.begin(RANGE_4_096V, SPS_128, SINGLE_SHOT_MODE);

    // Read all single-ended channels
    for (uint8_t i = 0; i < 4; i++) {
        int16_t value = ads.readChannel(i);
        Serial.print("AIN");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(value);
    }
}

void loop() {
}
