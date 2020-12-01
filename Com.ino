const int FW_VERSION = 12;

const long serial_baudrate = 115200;
const bool echo_enabled = false;

void com_init(){
  Serial.begin(serial_baudrate);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  establishContact();  // send a byte to establish contact until receiver responds
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print("-1");   // send an initial string
    
    if (echo_enabled == true){
      Serial.print('\n');
      Serial.print('\r');
    }
    
    delay(300);
  }
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
  cmd_get_sms1, // 6
  cmd_get_version, // 7
};

// Function that executes whatever received
void com_cycle() {
  if (Serial.available()>0){
    String scmd = Serial.readStringUntil('\n');

    int cmd = scmd.toInt();
      
    if (echo_enabled == true){
      delay(50);
      Serial.print('\n');
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
        Serial.print(get_pump_state());
        break;
      case cmd_set_pump_on:
        Serial.print(set_pump_state(HIGH));
        break;
      case cmd_set_pump_off:
        Serial.print(set_pump_state(LOW));
        break;
      case cmd_get_sms1:
        Serial.print(sms_get_value1());
        break;
      case cmd_get_version:
        Serial.print(FW_VERSION);
        break;
      default:
        Serial.print('.');
        break;
    }

    Serial.print('\n');
    
    if (echo_enabled == true){
      Serial.print('\r');
    }
  }
}
