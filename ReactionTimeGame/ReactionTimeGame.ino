
int Led1 = 5;
int Led2 = 18;
int bt1 = 22;
int bt2 = 23;
int val1 = 0;
int val2 = 0;
int tim = 0;
int pb = 0;

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(34));
  Serial.begin(115200);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("pro začátek stiskněte jakékoloiv tlačítko");
  Serial.print("\n");
  while (true){
    val1 = digitalRead(bt1);
    val2 = digitalRead(bt2);
    if (val1 == 0){
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      delay(500);
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      val1 =1;
      break;
    }
    if (val2 == 0){
      digitalWrite(Led2, HIGH);
      digitalWrite(Led1, HIGH);
      delay(500);
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      val1 =1;
      break;
    }
  }
  int rd = random(1,3);
  Serial.print("za 3 sekndy se rosvítí LED");
  Serial.print("\n");
  delay(3000);
  if (rd == 1){
    while (true) {
    val1 = digitalRead(bt1);
    digitalWrite(Led1, HIGH);
    tim = tim + 10;
    delay(10);
    if (val1 == 0){
      digitalWrite(Led1, LOW);
      val1 =0;
      break;      
      }
    }
  }
  if (rd == 2){
    while (true) {
    val2 = digitalRead(bt2);
    digitalWrite(Led2, HIGH);
    tim = tim + 10;
    delay(10);
    if (val2 == 0){
      digitalWrite(Led2, LOW);
      val2 = 0;
      break;      
      }
    }
  }
  if (pb > tim){
    pb = tim;
  }
  if (pb == 0){
    pb = tim;
  }
  Serial.print(tim);
  Serial.print("\n");
  Serial.print("***** > ");
  Serial.print(pb);
  Serial.print(" < *****");
  Serial.print("\n");
  delay(100);
  tim = 0;
  rd = 0;
}
