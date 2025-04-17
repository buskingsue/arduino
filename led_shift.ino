const int leds[] = {3, 4, 5};  // LED 핀 번호 배열 선언
// → 3번, 4번, 5번 핀에 각각 LED가 연결되어 있다고 정의합니다.

const int numLeds = sizeof(leds) / sizeof(leds[0]);  
// → LED의 개수를 계산합니다 (배열 크기 나누기 하나의 요소 크기)

int shiftIndex = 0;        // 현재 켜질 LED 인덱스
// → 어느 LED가 켜져야 하는지를 나타내는 변수입니다.

int shiftDirection = 1;    // 1이면 오른쪽, -1이면 왼쪽
// → 불빛이 이동하는 방향을 결정합니다.

unsigned long previousMillis = 0;  
// → 이전에 LED를 바꾼 시점을 저장하는 변수입니다.

const int interval = 200;  // LED 전환 주기 (200ms)
// → LED가 움직이는 속도를 설정합니다.

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);  
    // → 각 LED 핀을 출력 모드로 설정합니다.
  }
}

void loop() {
  unsigned long currentMillis = millis();
  // → 현재 시간을 밀리초 단위로 가져옵니다.

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    // → 지정된 시간이 지났으면 다음으로 넘어갑니다.

    // 모든 LED 끄기
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
      // → 모든 LED를 먼저 끕니다.
    }

    // 현재 위치의 LED 켜기
    digitalWrite(leds[shiftIndex], HIGH);
    // → 현재 인덱스에 해당하는 LED만 켭니다.

    // 다음 인덱스로 이동
    shiftIndex += shiftDirection;
    // → 불빛을 다음 LED로 이동합니다.

    // 양 끝에 도달하면 방향 반전
    if (shiftIndex == numLeds - 1 || shiftIndex == 0) {
      shiftDirection = -shiftDirection;
      // → 끝에 닿으면 방향을 반대로 바꿉니다.
    }
  }
}
