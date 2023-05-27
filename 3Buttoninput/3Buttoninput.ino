const int buttonPin01 = 6;
const int buttonPin02 = 7;
const int buttonPin03 = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);
  pinMode(buttonPin03, INPUT);

  digitalWrite(buttonPin01, HIGH);
  digitalWrite(buttonPin02, HIGH);
  digitalWrite(buttonPin03, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin01)== LOW){
    Serial.println("10");
    delay(200);
    }
    if(digitalRead(buttonPin02)== LOW){
    Serial.println("15");
    delay(200);
    }
    if(digitalRead(buttonPin03)== LOW){
    Serial.println("20");
    delay(200);
    }
}
