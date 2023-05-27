/*
 * gesture control program for controlling certain functions in windows pc
 * Code by BalaAppu
 * Website: www.electronicshub.org
 */
    
const int trigPin2 = 6;  // the number of the trigger output pin ( sensor 2 ) 
const int echoPin2 = 5;  // the number of the echo input pin ( sensor 2 ) 

////////////////////////////////// variables used for distance calculation 
long duration;                               
int distance1, distance2; 
float r;
unsigned long temp=0;
int temp1=0;
int l=0;
////////////////////////////////

void find_distance (void);

// this function returns the value in cm.
/*we should not trigger the both ultrasonic sensor at the same time. 
it might cause error result due to the intraction of the both soundswaves.*/ 
void find_distance (void)                   
{ 
 
  /////////////////////////////////////////upper part for left sensor and lower part for right sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration = pulseIn(echoPin2, HIGH, 5000);
  r = 3.4 * duration / 2;     
  distance2 = r / 100.00;
  delay(200);
}

void setup() 
{
  Serial.begin(9600);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  delay (1200);
    
}

void loop()
{
  find_distance(); // this function will stores the current distance measured by the ultrasonic sensor in the global variable "distance1 and distance2"
                   // no matter what, the program has to call this "find_distance" function continuously to get the distance value at all time.
  
  if(distance2<=35 && distance2>=15) // once if we placed our hands in front of the right sensor in the range between 15 to 35cm this condition becomes true.
  { 
    temp=millis();                   // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while(millis()<=(temp+300))      // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
    find_distance();
    if(distance2<=35 && distance2>=15) // this condition will true if we place our hand in front of the right sensor for more then 300 milli seconds. 
    {
     temp=distance2;                         // store the current position of our hand in the variable temp. 
     while(distance2<=50 || distance2==0)    // this loop will run untill we removes our hand in front of the right sensor.
     {
       find_distance();                      // call this function continuously to get the live data. 
       if((temp+10)<distance2)                // this condition becomes true if we moves our hand away from the right sensor (**but in front of it ). here " temp+6 " is for calibration.
       {
       Serial.println("up");               // send "down" serially.
       delay(1000);
       }
       else if((temp-10)>distance2)           // this condition becomes true if we moves our hand closer to the right sensor.
       {
        Serial.println("down");                // send "up" serially.
       delay(1000);
       }
       else {}
     }
    }
  }
}
