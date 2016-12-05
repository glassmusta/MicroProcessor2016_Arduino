const int sensor_pin[4] = {2, 3, 4, 5}; //적외선 센서 핀번호
const int E1 = 6;   //왼쪽 모터 전압
const int M1 = 7;
const int E2 = 8;   //오른쪽 모터 전압
const int M2 = 9;
const int SW = 18;
int sw_flag = 0;
void setup()
{
  pinMode(M1, OUTPUT);  //LEFT MOTOR핀 출력으로 설정
  pinMode(M2, OUTPUT);  //RIGHT MOTOR핀 출력으로 설정
  pinMode(SW, INPUT);
  for (int i = 0 ; i < 4 ; i++)
    pinMode(sensor_pin[i], INPUT);
  analogWrite(E1, 0);   //E1 정지
  analogWrite(E2, 0);   //E2 정지
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  delay(1000);
//  while (1) {
//    if (digitalRead(SW) == LOW) break;
//  }
}
void loop()
{
  if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) // O X X X
  {
    analogWrite(E1, 160);
    analogWrite(E2, 0);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) // X X X O
  {
    analogWrite(E1, 0);
    analogWrite(E2, 160);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) // O X X O
  {
    analogWrite(E1, 160);
    analogWrite(E2, 160);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) { // O O X X
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, 100);
    analogWrite(E2, 100);
    delay(225);
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) { // X X O O
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 100);
    analogWrite(E2, 100);
    delay(225);
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == LOW) { // O X O X
    analogWrite(E1, 160);
    analogWrite(E2, 0);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) { // X O X O
    analogWrite(E1, 0);
    analogWrite(E2, 160);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) // X O O O
  {
    analogWrite(E1, 0);
    analogWrite(E2, 160);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) // O X O O
  {
    analogWrite(E1, 0);
    analogWrite(E2, 160);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) // O O X O
  {
    analogWrite(E1, 160);
    analogWrite(E2, 0);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == LOW) // O O O X
  {
    analogWrite(E1, 160);
    analogWrite(E2, 0);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) // O O O O
  {
    analogWrite(E1, 160);
    analogWrite(E2, 160);
  }
  if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) // X X X X
  {
    analogWrite(E1, 0);
    analogWrite(E2, 0);
  }
  //알고리즘 끝
  delay(50);

}


