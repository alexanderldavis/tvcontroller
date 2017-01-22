# The AMAZON ECHO (Alexa) TV Controller

[INTRO -- This is an intro I wrote while procrastinating on a project, so feel free to skip it!]
We humans (for we are humans--right?), are on the verge of a massive revolution. I'm sure I'm hardly the only one who was enchanted by the Orwellian prospect of a humanity entirely dependent on technology, and while some may cite Karel Čapek's R.U.R to suggest the deleterious impact of robots on humanity, I stubbornly submit the same text as evidence to suggest the benefits of a robot revolution. Humanity's definition of itself is far too narrow, and the declaration of sentiency for man-made items should not be restricted to offspring.
While we are not quite at the point of Westworld-ian technology (I side with Ford's vision of humanity, BTW), I enjoy engaging in these debates!

Anyhoo, I am interested in participating in the eventual creation of this sentiency, and I believe it begins with having a robot turn on and off a TV!

Ever since I purchased an Amazon Echo (www.amazon.com) for my dorm room (late 2015), I set out to find ways to grant her more control over aspects of life in the room. This ambitious goal began with simple lights operating on WeMo Switch (www.belkin.com) hardware, as well as hands-free control of basic functions of my Mac, including sleep and wake functions. 

In my quest to make the Alexa an unrivaled master of a kingdom that sprawls 3 meters x 5 meters, I have come to the realization that limitations imposed by the archaic Internet security technicians at my school significantly impact my ability to connect devices to the Internet of Things. Registering the Alexa was difficult enough, I finally had to put her on the phone to explain what she was to the registration technician. I have therefore began to research ways to have her control other devices remotely (or at least without too much reliance on WiFi).

So it begins....

# The Plan
I write into this empty void to help me organize my thoughts. The first step of this project is to create a program for the Arduino to recieve and transmit code to the TV from the remote. Transmitter and reciever code is provided on the public domain by AdaFruit (www.adafruit.com) and (www.ladyada.net). To allow me to code the buttons quickly, I will write a small Python program to let me change the inputted Raw data from the receiver to match the format requirements for the transmitter .ino code.
(i.e.:
  from '57964 usec, 9280 usec'
  to '	delayMicroseconds(57964);
	      pulseIR(9280);
     ')
TODO!!!

# The Agenda
TODO!!!
