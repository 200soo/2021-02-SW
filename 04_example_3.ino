#define PIN_LED 13
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);   //PIN_LED를 출력모드로 설정
  Serial.begin(115200); //시리얼 포트를 115200 bps 속도로 초기화
  while (!Serial){
    ; //장치 초기화 완료까지 대기
  }
  Serial.println("Hello World!"); //시리얼 포트에 Hello World! 출력
  count = toggle = 0; //전역변수 count, toggle을 0으로 초기화
  digitalWrite(PIN_LED, toggle); //LED 전원 끄기(toggle=0)
}

void loop() {
  Serial.println(++count);  //count 값을 1만큼 증가시키고, 시리얼 포트에 출력

  //toggle을 toggle_state 함수에 넣고 돌려 나온 새로운 값으로 갱신
  //toggle(갱신) = toggle_state(기존)
  toggle = toggle_state(toggle);
  
  digitalWrite(PIN_LED, toggle); //LED 상태를 toggle 값에 따라 갱신(0 또는 1)
  delay(1000); //1초 대기 (1초=1000ms)
}

//사용자 정의 함수 이름(지역변수 명명)
//기존의 toggle을 넣고 새로운 toggle로 반환하는 함수
int toggle_state(int toggle) {
  if(toggle == 0){
    toggle = 1;
  } else {
    toggle = 0;
  }
  return toggle;
}
