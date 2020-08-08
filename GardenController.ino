// LED on pin 13
const int ledActive = 13; 

void setup() {
  pinMode(ledActive, OUTPUT);
  digitalWrite(ledActive, LOW);
  
  // init com
  com_init();

  // init temperature sensor 
  dht_init();

  light_init();

  pump_ctrl_init();

  sms_init();

  digitalWrite(ledActive, HIGH);
}

void loop() {
  com_cycle();
}
