#define PUMP_PIN 3
int pump_state;

void pump_ctrl_init(){
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN,LOW);
}

int get_pup_state(){
  return digitalRead(PUMP_PIN);
}

void set_pump_state(int state){
    digitalWrite(PUMP_PIN,state);
}
