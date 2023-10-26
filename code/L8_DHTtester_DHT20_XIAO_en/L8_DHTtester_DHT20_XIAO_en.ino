#include "DHT.h"
#define DHTTYPE DHT20   // DHT 20
DHT dht(DHTTYPE); 
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug Serial
#else
#define debug  Serial
#endif

void setup() {
    debug.begin(115200);
    debug.println("DHTxx test!");
    Wire.begin();
    dht.begin();
}

void loop() {
    float temp_hum_val[2] = {0};
    if (!dht.readTempAndHumidity(temp_hum_val)) {
        debug.print("Humidity: ");
        debug.print(temp_hum_val[0]);
        debug.print(" %\t");
        debug.print("Temperature: ");
        debug.print(temp_hum_val[1]);
        debug.println(" *C");
    } else {
        debug.println("Failed to get temprature and humidity value.");
    }

    delay(1500);
}