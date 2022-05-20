const int sampleWindow = 50;
unsigned int sensorA;
unsigned int sensorB;
unsigned int sensorC;
int leftLedPin=12;
int rightLedPin=13;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
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

  unsigned int peakToPeakC = 0; 
  unsigned int maxC = 0;
  unsigned int minC = 1024;
  double voltsC;

  while (millis() - startMillis < sampleWindow)
  {
    sensorA = analogRead(A0);
    sensorB = analogRead(A1);
    sensorC = analogRead(A2);
    //Serial.print("sensor c -> ");
    //Serial.println(sensorC);
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

    if (sensorC < 1024) 
    {
      if (sensorC > maxC)
      {
        maxC = sensorC; 
      }
      else if (sensorC < minC)
      {
        minC = sensorC;
      }
    }
  }

  peakToPeakA = maxA - minA; 
  double voltA = (peakToPeakA * 5.0) / 1024; 

  peakToPeakB = maxB - minB; 
  double voltB = (peakToPeakB * 5.0) / 1024;

  peakToPeakC = maxC - minC; 
  double voltC = (peakToPeakC * 5.0) / 1024; 
  /*
  Serial.print("voltA -> ");
  Serial.print(voltA);
  Serial.print("   voltB -> ");
  Serial.print(voltB);
  Serial.print("   voltC -> ");
  Serial.println(voltC);
  */
  
  if(abs(voltA - voltB)>0.1 and abs(voltB - voltC) > 0.01 and abs(voltA - voltC) > 0.01) {
    if(voltA > voltB and voltA > voltC){
      digitalWrite(leftLedPin, LOW);
      digitalWrite(rightLedPin, HIGH);  
      //Serial.print("right   v -> ");
     // Serial.print(voltA - voltB);
      
      Serial.print("   voltA -> ");
      Serial.print(voltA);
      Serial.print("   voltB -> ");
      Serial.println(voltB);
      Serial.print("   voltC -> ");
      Serial.println(voltC);
    } else if (voltB > voltA and voltB > voltC) {
      digitalWrite(leftLedPin, HIGH);
      digitalWrite(rightLedPin,   LOW);
      //Serial.print("left   v -> ");
      //Serial.print(voltB - voltA);

      Serial.print("   voltA -> ");
      Serial.print(voltA);
      Serial.print("   voltB -> ");
      Serial.println(voltB);
      Serial.print("   voltC -> ");
      Serial.println(voltC);
    }
    else if(voltC > voltA and voltC > voltB)
    {
      //digitalWrite(leftLedPin, HIGH);
      //digitalWrite(rightLedPin, LOW);
      Serial.print("front   v -> ");
      Serial.print(voltB - voltA);

      Serial.print("   voltA -> ");
      Serial.print(voltA);
      Serial.print("   voltB -> ");
      Serial.println(voltB);
      Serial.print("   voltC -> ");
      Serial.println(voltC);
    }
  }
}