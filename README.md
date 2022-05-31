# Intelligent Home Security

## Functionalitati si descriere 

Scopul proiectului este de a realiza un sistem inteligent de protectie a locuintei, atat pentru incidentele survenite (incendiu, scurgeri de gaze etc.), cat si pentru detectia unei persoane sau a unui zgomot.

In realizarea proiectului au fost folositi 3 senzori: un senzor MQ-2 pentru detectia fumului, un senzor ultrasonic pentru distanta si un senzor pentru sunet, precum si 3 led-uri (rosu, verde, albastru), un buzzer si un pushbutton.

Proiectul este activat la apasarea butonului, moment in care led-ul albastru este aprins. Atunci cand oricare dintre cei senzori este activat, alarma porneste (sunetul buzzer-ului), led-ul rosu fiind de asemenea aprins.

Pentru a se opri alarma (sau pentru a se reactiva programul), trebuie reapasat din nou butonul.

Link pentru prezentarea in intregime a functionalitatii proiectului: https://youtu.be/uuXfNJtDX2g

## Implementare

Implementarea a fost realizata folosind 3 senzori anterior mentionati, o placuta Arduino, 3 led-uri, un breadboard, un minibreadboard, un buzzer si un pushbutton, putand fi vizibili in schema electrica.

In codul programului, am realizat 3 functii separate: pushButtonDetected() folosita pentru apasarea butonului, soundDetectedRoutine() folosita pentru detectia sunetului, myDelay(int val) folosita pentru "timp mort" DEOARECE functia DELAY() nu poate primi ca parametru o variabila.

Pentru senzorul de fum, am folosit o variabila smokeThreshold cu scopul de prag, variabila ce poate fi modificata prin modificarea fizica a potentiometrului.
De asemenea, daca se doreste, se poate alege software o valoare fixa peste care smokeLevel sa produca activarea alarmei.

Implementarea a fost realizata folosind analogRead si digitalWrite din biblioteca Arduino.
https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/
https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial
Citirea senzorilor de fum si ultrasonic au fost facute folosind analogRead, iar in functie de valorile acestora, alarma trebuia/nu pornita.

Pentru senzorul de sunet si pentru buton, au fost folositi pini de intrerupere.
https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
https://forum.arduino.cc/t/how-to-digitalpintointerrupt/562135



## Imagini
![Imagine](/1.jpg)
![Imagine2](/2.png)
![SchemaElectrica](/schemaelectrica.jpg)

## Proiecte similare: 
https://create.arduino.cc/projecthub/Aritro/smoke-detection-using-mq-2-gas-sensor-79c54a
https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
https://create.arduino.cc/projecthub/iotboys/control-led-by-clap-using-arduino-and-sound-sensor-e31809
https://www.optimusdigital.ro/ro/senzori-de-gaze/107-modul-senzor-gas-mq-2.html?search_query=senzor+de+fum+&results=5
https://www.optimusdigital.ro/en/others/108-sound-sensor-module.html

