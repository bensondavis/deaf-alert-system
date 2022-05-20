const int sampleWindow = 50;
unsigned int sensorA;
unsigned int sensorB;
int leftLedPin=12;
int rightLedPin=13;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600); 
}

void loop() {
  unsigned long startMillis = millis(); 
 
  unsigned int peakToPeakA = 0;
  unsigned int maxA = 0;
  unsigned int minA = 1024;
  double voltsA;

  unsigned int peakToPeakB = 0; 
  unsigned int maxB = 0;
  unsigned int minB = 1024;
  double voltsB;

  while (millis() - startMillis < sampleWindow)
  {
    sensorA = analogRead(A0);
    sensorB = analogRead(A1);

    if (sensorA < 1024)
    {
      if (sensorA > maxA)
      {
        maxA = sensorA; 
      }
      else if (sensorA < minA)
      {
        minA = sensorA; 
      }
    }
   
    if (sensorB < 1024) 
    {
      if (sensorB > maxB)
      {
        maxB = sensorB; 
      }
      else if (sensorB < minB)
      {
        minB = sensorB;
      }
    }
  }

  peakToPeakA = maxA - minA; 
  double voltA = (peakToPeakA * 5.0) / 1024; 

  peakToPeakB = maxB - minB; 
  double voltB = (peakToPeakB * 5.0) / 1024; 

  if(abs(voltA - voltB) > 0.01) {
    if(voltA > voltB ){
      digitalWrite(leftLedPin, LOW);
      digitalWrite(rightLedPin, HIGH);  
      Serial.print("right   v -> ");
      Serial.print(voltA - voltB);
      
      Serial.print("   voltA -> ");
      Serial.print(voltA);
      Serial.print("   voltB -> ");
      Serial.println(voltB);
    } else if (voltA == voltB) {
      digitalWrite(leftLedPin, HIGH);
      digitalWrite(rightLedPin,   HIGH);
      Serial.print("both   v -> ");
      Serial.print(voltA - voltB);

      Serial.print("   voltA -> ");
      Serial.print(voltA);
      Serial.print("   voltB -> ");
      Serial.println(voltB);
    }
    else
    {
      digitalWrite(leftLedPin, HIGH);
      digitalWrite(rightLedPin, LOW);
      Serial.print("left   v -> ");
      Serial.print(voltB - voltA);

      Serial.print("   voltA -> ");
      Serial.print(voltA);
      Serial.print("   voltB -> ");
      Serial.println(voltB);
    }
  }
}