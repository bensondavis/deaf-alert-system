import speech_recognition as sr

recording = sr.Recognizer()

# for index, name in enumerate(sr.Microphone.list_microphone_names()):
#     print("Microphone with name \"{1}\" found for `Microphone(device_index={0})`".format(index, name))

with sr.Microphone() as source:
    recording.adjust_for_ambient_noise(source)
    print("Please Say something:")
    audio = recording.listen(source)

try:
    print("You said: \n" + recording.recognize_google(audio))
except Exception as e:
    print(e)