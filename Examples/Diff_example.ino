#include <My_ADS_1115.h>

My_ADS_1115 ads;

void setup() {
    Serial.begin(115200);
    ads.begin(RANGE_4_096V, SPS_128, SINGLE_SHOT_MODE);

    // Read differential channels
    Serial.print("AIN0-AIN1: ");
    Serial.println(ads.readChannel(0)); // MUX 0
    Serial.print("AIN2-AIN3: ");
    Serial.println(ads.readChannel(1)); // MUX 1
}

void loop() {
}
