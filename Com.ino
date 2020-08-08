const long serial_baudrate = 115200;
const bool echo_enabled = true;

void com_init(){
  Serial.begin(serial_baudrate);
}

/* 
 *  COMMANDS
 *   - 1 : temp
 *   - 2 : humi
 *   - 3 : hidx
*/

enum commands {
  cmd_get_temperature, // 0
  cmd_get_humidity, // 1
  cmd_get_light, // 2
  cmd_get_pump_state, // 3
  cmd_set_pump_on, // 4
  cmd_set_pump_off, // 5
};

// Function that executes whatever received
void com_cycle() {
  if (Serial.available()){
    int cmd = Serial.parseInt();

    if (echo_enabled == true){
      delay(50);
      Serial.print(cmd);  
      Serial.print(':');
    }

    switch (cmd){
      case cmd_get_temperature:
        Serial.print(dht_read_temperature());
        break;
      case cmd_get_humidity:
        Serial.print(dht_read_humidity());
        break;
      case cmd_get_light:
        Serial.print(light_get_value());
        break;
      case cmd_get_pump_state:
        Serial.print(get_pup_state());
        break;
      case cmd_set_pump_on:
        set_pump_state(HIGH);
        Serial.print(get_pup_state());
        break;
      case cmd_set_pump_off:
        set_pump_state(LOW);
        Serial.print(get_pup_state());
        break;
      default:
        Serial.print('.');
        break;
    }
    
    if (echo_enabled == true){
      Serial.print('\n');
      Serial.print('\r');
    }
  }
}
