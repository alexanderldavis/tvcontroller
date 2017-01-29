# The AMAZON ECHO (Alexa) TV Controller

## The Intro
[This is an intro I wrote while procrastinating on a project, so feel free to skip it!]
We humans (for we are humans--right?), are on the verge of a massive revolution. I'm sure I'm hardly the only one who was enchanted by the Orwellian prospect of a humanity entirely dependent on technology, and while some may cite Karel Čapek's R.U.R to suggest the deleterious impact of robots on humanity, I stubbornly submit the same text as evidence to suggest the benefits of a robot revolution. Humanity's definition of itself is far too narrow, and the declaration of sentiency for man-made items should not be restricted to offspring.
While we are not quite at the point of Westworld-ian technology (I side with Ford's vision of humanity, BTW), I enjoy engaging in these debates!

Anyhoo, I am interested in participating in the eventual creation of this sentiency, and I believe it begins with having a robot turn on and off a TV!

Ever since I purchased an Amazon Echo (www.amazon.com) for my dorm room (late 2015), I set out to find ways to grant her more control over aspects of life in the room. This ambitious goal began with simple lights operating on WeMo Switch (www.belkin.com) hardware, as well as hands-free control of basic functions of my Mac, including sleep and wake functions. 

In my quest to make the Alexa an unrivaled master of a kingdom that sprawls 3 meters x 5 meters, I have come to the realization that limitations imposed by the archaic Internet security technicians at my school significantly impact my ability to connect devices to the Internet of Things. Registering the Alexa was difficult enough, I finally had to put her on the phone to explain what she was to the registration technician. I have therefore began to research ways to have her control other devices remotely (or at least without too much reliance on WiFi).

So it begins....

## The Plan
I write into this empty void to help me organize my thoughts. The first step of this project is to create a program for the Arduino to recieve and transmit code to the TV from the remote. Transmitter and reciever code is provided on the public domain by AdaFruit (www.adafruit.com) and (www.ladyada.net). To allow me to code the buttons quickly, I will write a small Python program to let me change the inputted Raw data from the receiver to match the format requirements for the transmitter .ino code.
(i.e.:
  from '57964 usec, 9280 usec'
  to '	delayMicroseconds(57964);
	      pulseIR(9280);
     ')
Update (later that day): I also edited the IRReciever.ino code so that it outputs the raw data in the format required by the Transmitter code.

## The Agenda
PART 1: CONTROL TV FROM COMMAND LINE
	STEP 1: Capture and convert all IR codes from TV remote and Apple TV remote using modified public domain code from IRReceiver.
	STEP 2: Add these codes as functions in the TVControllerMain.ino file, and code each button to a different Serial port. (i.e. to turn on TV, use './arduino-serial -b 9600 -p /dev/tty.usbmodemFD121 -s 1' as a command-line prompt.
	STEP 3: Make aliases in .bash_profile for each of these, (i.e. alias tv = "./arduino-serial -b 9600 -p /dev/tty.usbmodemFD121 -s a"), so that the commands are simplified and available from command line.

PART 2: TRANSITION CODE TO RASPBERRY PI
	TODO!!!
    
## Replication instructions
If anybody is interested in installing their own version of this little project, feel free to follow these instructions! I found most of this information online, so be sure to ask Gewgle for instructions if you question my methods! If you are new to Arduino, welcome! You may want to complete some (also fun) smaller projects. This one is not difficult by any means, but I may not be the most verbose teacher. There are other tutorials that will be easier to start with (and will explain basic better).

### Control TV from Command Line

#### 1. Find materials 
Acquire monies to purchase an Arduino UNO Rev3, a breadboard, cables, a 3-prong IR reciever made for Arduino, and an IR transmitter made for Arduino. (All of these are found on Amazon, but found cheaper on eBay).

#### 2. Assembly
Assemble these pieces as shown in the diagram below (FIG1). Plug Arduino into your computer.

(FIG1)
![Arduino Reciever](https://raw.githubusercontent.com/alexanderldavis/tvcontroller/master/Images/irreceiver_bb.png)
(Assembly of the Arduino IR receiver. This receiver will allow you to identify your remote's code and prep the raw data for your transmitter code.) 

### 3. Download code
Scroll up on this page and download the files IRReceiver.ino and TVControllerMainBlank.ino.


Open IRReceiver.ino in the Arduino IDE, download to Arduino and run it. Open your Serial Monitor and press a button on your remote once. It will output the code in the right format.

The format will be:
``` void name() {
	delayMicroseconds(57964);
	pulseIR(9280);
	delayMicroseconds(4580);
	pulseIR(600);
    ...
}```

Copy the code from the Serial Monitor and paste it into the TVControllerMainBlank.ino code at the bottom of the file. Then rename the function name "void [put new name here] ()" and take that name, scroll up the TVController MainBlank code, and paste it in the void loop().

Example: Your first button is the TV Power button. Paste the code in the TVControllerMainBlank code at the very bottom (read inline comments). Rename the function.

(at bottom of file:)
change from
```void name() { ... }```
to
```void powerButton() {
	... 
}```.

Take this new function name, scroll up to the ```void loop() {``` code at the top of the page, and paste the function name in one of the ```if (val == '1') { ... }``` positions.

(at top of file:)
change from
```if (val == 1) {}```
to
```if (val == 1) {powerButton();}```.

Repeat these steps for each button you wish to code. Note: This worked for my TV and my Apple TV. It did not work with my Alexa remote, other remotes because they are not IR. Ensure your remote is an IR remote before trying this code! (It seems obvious, but I got caught up in my initial tests!)

Once the TVControllerMainBlank code is ready, it's time to start transmitting the code!

#### 4. Assembly (pt2)
Assemble these pieces as shown in the diagram below (FIG2). Plug Arduino into your computer.

(FIG2)
![Arduino Transmitter](https://raw.githubusercontent.com/alexanderldavis/tvcontroller/master/Images/irtransmitter_bb.png)

Upload TVControllerMainBlank.ino to Arduino.

#### 5. Enable Arduino-Serial
Download the Zip of [arduino-serial](https://github.com/todbot/arduino-serial) (https://github.com/todbot/arduino-serial).

Unzip the file in your desktop/documents directory. Go to your terminal, navigate to the directory and use command ```make arduino-serial``` to compile the file, then use command ```ls /dev/tty.*``` to find all serial ports available. It should look like: ```/dev/tty.Bluetooth-Incoming-Port	/dev/tty.usbmodemFD121``` (with Arduino plugged in). Copy the second serial port (in this case ```/dev/tty.usbmodemFD121```) and put it aside for safekeeping.

Go back to terminal and type ```./arduino-serial -b 9600 -p /dev/tty.usbmodemFD121 -s 1```, replacing my ```/dev/tty.usbmodemFD121``` with your copied serial port. Press enter and voila! Barring any major issues your Arduino will transmit the 'on' code for your TV and you can watch some HBO! Change the number at the end of the terminal invocation to invoke different buttons. For example, if you 'Input' button is in your code in the second button function slot, you can change delete the 1 and insert a 2 to send the 'Input' code! You can create bash files/aliases in your .bash_profile to make shortcuts for this. For example, I can type 'tv' into my command line to toggle the tv, tv_up to change volume, etc..

TODO[Wishlist]=Create shortcut in TVControllerMain code to increase volume in increments of 10, instead of individual units (takes too long!) (Maybe see how a button long press is transmitted)

### Connect Alexa to Raspberry Pi
I will add to these instructions as I continue to figure them out! I think the next steps will involve creating a personal Skill for the Alexa.

