const int sensor_pin[4] = {46, 47, 48, 49}; //적외선 센서 핀번호
const int E1 = 2;   //왼쪽 모터 전압
const int M1 = 3;
const int E2 = 4;   //오른쪽 모터 전압
const int M2 = 5;
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
  while (1) {
    if (digitalRead(SW) == LOW) break;
  }
}
void loop()
{
  if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[3]) == HIGH) { // X ? ? O
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 189);
    analogWrite(E2, 252);
    while (digitalRead(sensor_pin[0]) != HIGH) {
      delay(1);
      if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) break;
    } 
  }
  else if (digitalRead(sensor_pin[3]) == LOW && digitalRead(sensor_pin[0]) == HIGH) { // O ? ? X
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, 254);
    analogWrite(E2, 189);
    while (digitalRead(sensor_pin[3]) != HIGH) {
      delay(1);
      if(digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW)   break;
    }
  }
  else if (digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[0]) == HIGH) // O X ? ?
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 0);
    analogWrite(E2, 252);
  }
  else if (digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) // ? ? X O
  { 
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 189);
    analogWrite(E2, 0);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) // O ? ? O
  {
    analogWrite(E1, 189);
    analogWrite(E2, 252);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) // X X X X
  {
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    while(1){
      delay(1);
      if(digitalRead(sensor_pin[0]) == HIGH || digitalRead(sensor_pin[1]) == HIGH || digitalRead(sensor_pin[2]) == HIGH || digitalRead(sensor_pin[3]) == HIGH) break;
    }
  }
}




