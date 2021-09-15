#define PIN_LED 7
unsigned int toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  toggle = 1;
}

void loop() {
  digitalWrite(PIN_LED, toggle);
  delay(1000);
  for (int i = 0; i < 10; i++){
    toggle = toggle_state(toggle);
    digitalWrite(PIN_LED, toggle);
    delay(100);
  }
  toggle = toggle_state(toggle);
  while(1){
      digitalWrite(PIN_LED, toggle);
  }
}

int toggle_state(int toggle) {
  if(toggle == 0){
    toggle = 1;
  } else {
    toggle = 0;
  }
  return toggle;
}
