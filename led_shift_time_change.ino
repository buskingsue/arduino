const int leds[] = {3, 4, 5};  // LED 핀 배열
// → 3, 4, 5번 핀에 연결된 LED 배열을 정의합니다.

const int numLeds = sizeof(leds) / sizeof(leds[0]);
// → LED 개수를 자동으로 계산합니다.

int shiftIndex = 0;         // 현재 켜질 LED 인덱스
int shiftDirection = 1;     // LED 이동 방향 (1: 오른쪽, -1: 왼쪽)

unsigned long previousMillis = 0;   // 마지막 LED 갱신 시각

int currentInterval = 1000;          // 현재 인터벌 시간 (ms)
// → LED가 켜질 간격 (초기값은 1000ms)

int intervalDirection = -1;         // 간격 변화 방향 (-1: 점점 빨라짐, 1: 점점 느려짐)

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);  // 모든 LED 핀을 출력 모드로 설정
  }
}

void loop() {
  unsigned long currentMillis = millis();  // 현재 시간 측정

  if (currentMillis - previousMillis >= currentInterval) {
    previousMillis = currentMillis;  // 시간 갱신

    // 모든 LED 끄기
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

    // 현재 인덱스 LED 켜기
    digitalWrite(leds[shiftIndex], HIGH);

    // 인덱스 이동
    shiftIndex += shiftDirection;

    // 끝에 도달하면 방향 반전
    if (shiftIndex == numLeds - 1 || shiftIndex == 0) {
      shiftDirection = -shiftDirection;
    }

    // 속도 조절 (인터벌 변화)
    currentInterval += intervalDirection * 50;
    // → 50ms씩 빨라지거나 느려집니다.

    // 인터벌이 0ms보다 작거나 1000ms보다 크면 방향 반전
    if (currentInterval <= 10 || currentInterval >= 1000) {
      intervalDirection = -intervalDirection;
    }
  }
}
