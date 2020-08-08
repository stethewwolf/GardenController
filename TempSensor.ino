//https://github.com/winlinvip/SimpleDHT
#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 3
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

float stored_temperature = -1;
float stored_humidity = -1;

void dht_init(){
  // wait to allow the sensor to perform first sample
  delay(2000);

  // init stored values
  dht_update_values();
}

void dht_update_values(){
  byte temperature = 0;
  byte humidity = 0;
  
  int read_status = dht11.read(&temperature, &humidity, NULL);
  if (read_status == SimpleDHTErrSuccess) {
    stored_temperature = (float)temperature;
    stored_humidity = (float)humidity;
  }
}

float dht_read_temperature(){
  dht_update_values();
  return stored_temperature;
}

float dht_read_humidity(){
  dht_update_values();
  return stored_humidity;
}
