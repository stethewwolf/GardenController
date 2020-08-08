
#define SMS1PIN A1
#define SMS2PIN A2

void sms_init(){
  // 
}

int sms_get_value1(){
  int raw_sensor_value = analogRead(SMS1PIN);

  return map(raw_sensor_value, 0, 1023, 100, 1);
}

int sms_get_value2(){
  int raw_sensor_value = analogRead(SMS2PIN);
  return map(raw_sensor_value, 0, 1023, 100, 1);
}
