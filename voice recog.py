# import speech_recognition as sr

# recording = sr.Recognizer()

# with sr.Microphone() as source:
#     recording.adjust_for_ambient_noise(source)
#     print("Please Say something:")
#     audio = recording.listen(source)

# try:
#     print("You said: \n" + recording.recognize_google(audio))
# except Exception as e:
#     print(e)


# import pyfirmata 
from socket import timeout
from pyfirmata import Arduino, util
import time

board = Arduino('COM3')

it = util.Iterator(board)
it.start()

sampleWindow = 50
leftLedPin=12
rightLedPin=13
sensorA=0
sensorB=0
sensorC=0
sensorD=0
#board.analog[1].enable_reporting()
#print(board.analog[1].read())
analog_input1 = board.get_pin('a:0:i')
analog_value1 = analog_input1.read()
print(analog_value1)
time.sleep(0.5)
analog_input2 = board.get_pin('a:1:i')
analog_input3 = board.get_pin('a:2:i')
analog_input4 = board.get_pin('a:3:i')

while True:
    startMillis = time.time()

    peakToPeakA = 0
    maxA = 0
    minA = 1024

    peakToPeakB = 0
    maxB = 0
    minB = 1024

    peakToPeakC = 0
    maxC = 0
    minC = 1024

    peakToPeakD = 0
    maxD = 0
    minD = 1024

    while (time.time() - startMillis < sampleWindow):
        #sensorA = board.analog[0].read()
        #print(sensorA)
        sensorB = analog_input2.read()
        sensorC = analog_input3.read()
        sensorD = analog_input4.read()

        if (sensorA < 1024):
            if (sensorA > maxA):
                maxA = sensorA
            elif (sensorA < minA):
                minA = sensorA

        if (sensorB < 1024):
            if (sensorB > maxB):
                maxB = sensorB
            elif (sensorB < minB):
                minB = sensorB

        if (sensorC < 1024):
            if (sensorC > maxC):
                maxC = sensorC
            elif (sensorC < minC):
                minC = sensorC

        if (sensorD < 1024):
            if (sensorD > maxD):
                maxD = sensorD
            elif (sensorD < minD):
                minD = sensorD

    peakToPeakA = maxA - minA
    voltA = (peakToPeakA * 5.0) / 1024

    peakToPeakB = maxB - minB
    voltB = (peakToPeakB * 5.0) / 1024

    peakToPeakC = maxC - minC
    voltC = (peakToPeakC * 5.0) / 1024

    peakToPeakD = maxD - minD
    voltD = (peakToPeakD * 5.0) / 1024   
            
    if(voltA + voltB + voltC + voltD > 0.09):
        if(voltA > voltB and voltA > voltC and voltA > voltD):
            board.digital[leftLedPin],write(0)
            board.digital[rightLedPin],write(1)
            # digitalWrite(leftLedPin, LOW)
            # digitalWrite(rightLedPin, HIGH)  
            print("A  voltA ->",voltA,"  voltB -> ",voltB, "voltC -> ",voltC,"  voltD ->", voltD)

        elif (voltB > voltA and voltB > voltC  and voltB > voltD):
            board.digital[leftLedPin],write(1)
            board.digital[rightLedPin],write(0)
            # digitalWrite(leftLedPin, HIGH)
            # digitalWrite(rightLedPin,   LOW)
            print("B  voltA ->",voltA,"  voltB -> ",voltB, "voltC -> ",voltC,"  voltD ->", voltD)
            
        elif(voltC > voltA and voltC > voltB  and voltC > voltD):
            print("C  voltA ->",voltA,"  voltB -> ",voltB, "voltC -> ",voltC,"  voltD ->", voltD)
    
        else:
            print("D  voltA ->",voltA,"  voltB -> ",voltB, "voltC -> ",voltC,"  voltD ->", voltD)
    time.sleep(0.1)