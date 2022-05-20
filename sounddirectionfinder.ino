int leftLedPin=13;
int rightLedPin=12;
int rightSensorPin=8;
int leftSensorPin=7;
int rightVal = 0;
int leftVal = 0;
int mx;
int flagl=0;
int flagr=0;
unsigned long time;
unsigned long rt=0;
unsigned long lt=0;

void setup()
{
  pinMode(leftLedPin, OUTPUT);
  pinMode(rightLedPin, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  Serial.begin (9600);
  //time = micros();
}
  
void loop ()
{
  time = micros();
  rightVal =digitalRead(rightSensorPin);
  leftVal =digitalRead(leftSensorPin);
  if(rightVal==1 and flagr==0)
  {
    rt=time;
    flagr=1;
  }
  if(leftVal==1 and flagl==0)
  {
    lt=time;
    flagl=1;
  }
  Serial.print("rt");
  Serial.println(rt);
  Serial.print("lt");
  Serial.println(lt);
  /*if(rt < lt) 
  {
     Serial.println("right");
     delay(2400);
  }
  else if (rt > lt) 
  {
    Serial.println("left");
    delay(2400);
  }
  else 
  {
      Serial.println("no sound");
  }*/
  //Serial.print("right");
  //Serial.print(rt);
  //Serial.print("---");
  //Serial.println(rightVal);
  //Serial.print("left");
  //Serial.print(lt);
  //Serial.print("---");
  //Serial.println(leftVal);
  //Serial.println(time);
  /*if(rt<lt and abs(rt-lt)<
  {
   Serial.println("right"); 
  }
  if(rt>lt)
  {
    Serial.println("left");
  }*/
  /*Serial.print("left");
  Serial.println(leftVal);
  delay(100);
  Serial.print("right");
  Serial.println(rightVal);*/
  
}