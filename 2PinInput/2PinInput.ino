const int buttonPin01 = 6;
const int buttonPin02 = 7;

void setup()
{
  Serial.begin(9600);

  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);

  digitalWrite(buttonPin01, HIGH);
  digitalWrite(buttonPin02, HIGH);
}
void loop() 
    {
     if(digitalWrite(buttonPin01) == LOW)
      {
      Serial.println("LEFT");
      }
     if(digitalWrite(buttonPin02) == LOW)
     {
       Serial.println("RIGHT");
      }  
   }
  
