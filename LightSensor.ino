
#define LIGHT_PIN A0

void light_init(){
  // use analog input 
}

int light_get_value(){
  int raw_sensor_value = analogRead(LIGHT_PIN);

  return map(raw_sensor_value, 0, 1023, 100, 1);
}
