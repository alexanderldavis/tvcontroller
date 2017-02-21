# The AMAZON ECHO (Alexa) TV Controller

This is a simple homeassistant (HASS)-based, light-weight configuration for Raspberry Pi that allow custom-built Alexa commands to control a TV. The TV controller itself is run through an Arduino that is connected to an infared transmitter.

_Check out this_ [wiki](https://github.com/alexanderldavis/tvcontroller/wiki/Installing-HASS-on-Base-Computer-(Instead-of-Raspberry-Pi)) _if you are interested in this project and don't have a Raspberry Pi or you want to implement a similar setup on a "normal" machine. For convienence, this is not suggested, as then the commands will only work when the "normal" machine is online. This may limit functionality, as the HASS server may suffer from interruptions._

## Replication Instructions
If anybody is interested in installing their own version of this little project, feel free to follow these instructions! I found most of this information online, so be sure to ask Gewgle for instructions if you question my methods! If you are new to Arduino and Rasberry Pi, welcome! (so am I!) You may want to complete some (also fun) smaller projects. This one is not difficult by any means, but I may not be the most verbose teacher. There are other tutorials that will be easier to start with (and will explain basic commands more better).

These instructions are composed of five parts:
* Enable Home Assistant on a Raspberry Pi
* Setup ArduinoSerial on Home Assistant
* Control TV with Home Assistant
* Control Home Assistant with Alexa
* Control TV with Alexa

Along the way, I will link to wikis that could help people troubleshoot their issues. My base computer is a MacBook Pro (named Roxana after the murderous wife of Alexander the Great), but all of the following instructions _should_ work on any OS and base hardware. Open an issue and report your software if you find this is not the case!

#### Required Components:
* Amazon Echo/Amazon Echo Dot/[Amazon Echosim.io](https://echosim.io/) (More on the latter in the wiki (TODO))
* Raspberry Pi 3 (I have not tested on the Raspberry Pi 2, 1 or zero, though with a litte research I'm sure it would work similarly)
* Arduino Uno Rev 3 (Again, not tested on any other iteration of Arduino, yet!)
* Arduino Breadboard (not entirely necessary, but it makes your life easier!)
* Arduino Cables
* Arduino [3-prong IR reciever and transmitter](https://www.amazon.com/AIRSUNNY-three-Infrared-Emission-Receiver/dp/B00EFOQEUM/ref=sr_1_1?ie=UTF8&qid=1487019069&sr=8-1&keywords=ir+receiver+arduino)
*These are all available on Amazon, but are found cheaper on eBay. Proceed with caution on eBay, as lower-priced components are generally less reputable!

#### Required Software (Quick Note):
* Raspberry Pi must have the [latest version of Raspbian Jessie](https://www.raspberrypi.org/downloads/raspbian/) (not Lite!) Find installation instructions on the Raspberry Pi website!

*QUICK NOTE: Be sure to follow all instruction of setup for the Raspbian image! You will want to change your password once you logon for the first time. Follow [this tutorial](http://www.macworld.co.uk/how-to/mac/how-to-set-up-raspberry-pi-3-with-mac-3637490/) if this is your first time initializing a Raspbian image.*

### (1) Prepare Raspberry Pi

Once you have a Raspberry Pi 3 running the latest version of Raspbian Jessie powered up and ready, plug in a keyboard and mouse. Then, take an HDMI cable and connect the Pi to a monitor. Navigate to the terminal icon (top right of screen) and click it to open a new session. Once inside the terminal, type ```ifconfig``` to get a list of wireless connections. If you are connected to the internet, it should look something like this:
```
eth0      Link encap:Ethernet  HWaddr [REDACTED]  
          inet6 addr: [REDACTED] Scope:Link
          UP BROADCAST MULTICAST  MTU:1500  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)

lo        Link encap:Local Loopback  
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:65536  Metric:1
          RX packets:688539 errors:0 dropped:0 overruns:0 frame:0
          TX packets:688539 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1 
          RX bytes:53382983 (50.9 MiB)  TX bytes:53382983 (50.9 MiB)

wlan0     Link encap:Ethernet  HWaddr [REDACTED]  
          inet addr:172.27.45.145  Bcast:[REDACTED]  Mask:[REDACTED]	<-- IP address here
          inet6 addr: [REDACTED] Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:5294913 errors:0 dropped:253818 overruns:0 frame:0
          TX packets:2686711 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:1061822341 (1012.6 MiB)  TX bytes:242953170 (231.6 MiB)
```
Under the ```wlan0``` category, search for your Raspberry Pi's IP address. In my case, this happens to be 172.27.45.145.
Note: Everytime the Raspberry Pi is restarted, if you haven't specified a static IP slot for the Rasberry Pi, this IP address could change. You will therefore see reduced functionality (or none at all). If possible, go into your router to add the Raspberry Pi to a static IP. If this is not possible, you may have to repeat this step in the future if you happen to unplug the Raspberry Pi!

Write down this IP address for safekeeping. You may now disconnect everything from the Raspberry Pi (except for the power!). Now, go to your base computer (Mac, PC, etc) and open a terminal/command prompt window. Here, type ```ssh pi@[insert IP here]``` without the brackets. For example, my command would be ```ssh pi@172.27.45.145```. The terminal may ask you to confirm the authenticity of the Raspberry Pi. This is normal, and once you type ```yes``` and hit return, you will not be asked this again.Your terminal will prompt you for the password you set up during the Raspberry Pi installation process. (If you did not set up a password, the default is ```raspberry```, though I urge you to change it ASAP!).

Now that you have "secure shelled" (ssh) into the raspberry pi, you should see this: ```pi@raspberrypi:~ $ ``` if you have completed everything correctly!

### (2) Install HomeAssistant (HASS) onto Raspberry Pi
The following instructions come from the HomeAssistant documentation provided [here](https://home-assistant.io/getting-started/installation-raspberry-pi-all-in-one/). I would recommend reading through it once. It provides a lot of good information about the setup process. Once you have read through the documentation, return to your ssh connection in the terminal window and run the following command (THIS WILL TAKE 30min-2hr based on WiFi connection. While it is running, you may use your computer for other tasks): 
```
$ curl -O https://raw.githubusercontent.com/home-assistant/fabric-home-assistant/master/hass_rpi_installer.sh && sudo chown pi:pi hass_rpi_installer.sh && bash hass_rpi_installer.sh
```
You may proceed with the Arduino instructions below while you wait. You will be prompted for a password near the end of the installation, so be sure to check the terminal window regularly. It should be going through installation scripts.

Skip ahead while you wait, and come back here once the setup is done.

---------------------------------------------------------------------
Once the installation is complete, type ```sudo shutdown -h now``` into your ssh connection. This will terminate the Raspberry Pi. Unplug it and plug it back in and allow it to fully reboot. Return to your base computer terminal, and ssh into it with the same command as above. Then, go to any browser on your base machine and type ```http://[your_raspberry_pi_ip]:8123```. Again, for mine this would be ```http://172.27.45.145:8123```. You should see the HomeAssistant frontend UI appear. If you do not see it, wait 20 seconds and try again. The first time it loads, the Rasberry Pi may take more time to fully boot the UI.

Once you see it, congrats! You are ready for step 4! If you have any smart home devices (WeMo, Nest, Apple TVs, etc...) they may be showing up on the UI! If you don't see anything except the blue bar at the top, don't fret! You will soon!

---------------------------------------------------------------------

### (3) Setup Arduino
Assemble the Arduino as shown in the diagram below (FIG1), and plug the Arduino into your base computer. Be sure you have the [Arduino IDE](https://www.arduino.cc/en/main/software) installed on your base machine.
![Arduino Reciever](https://raw.githubusercontent.com/alexanderldavis/tvcontroller/master/Images/irreceiver_bb.png)
(FIG1: Assembly of the Arduino IR receiver. This receiver will allow you to identify your remote's code and prep the raw data for your transmitter code.) 

Next, download the files [IRReceiver.ino](https://github.com/alexanderldavis/tvcontroller/blob/master/IRReceiver.ino) and [TVControllerMainBlank.ino](https://github.com/alexanderldavis/tvcontroller/blob/master/TVControllerMainBlank.ino) to your base computer (not the Raspberry Pi).

Open IRReceiver.ino in the Arduino IDE, download to Arduino and run it. Open your Serial Monitor and press a button on your remote once. It will output the code in the right format.

The format will be:
```arduino
void name() {
	delayMicroseconds(57964);
	pulseIR(9280);
	delayMicroseconds(4580);
	pulseIR(600);
    ...
}
```

Copy the code from the Serial Monitor and paste it into the TVControllerMainBlank.ino code at the bottom of the file. Then rename the function name ```void [put new name here] ()``` and take that name, scroll up the TVController MainBlank code, and paste it in the ```void loop()```.

Example: Your first button is the TV Power button. Paste the code in the TVControllerMainBlank code at the very bottom (read inline comments). Rename the function.

(at bottom of file:)
Change from

```
void name() { 
	... 
}

```

to

```
void powerButton() {
	... 
}
```

Take this new function name, scroll up to the ```void loop() {``` code at the top of the page, and paste the function name in one of the ```if (val == '1') { ... }``` positions.

(at top of file:)
change from
```
if (val == 1) {
}
```
to
```
if (val == 1) {powerButton();}
```

Repeat these steps for each button you wish to code. Note: This worked for my TV and my Apple TV. It did not work with my Alexa remote, other remotes because they are not IR. Ensure your remote is an IR remote before trying this code! (It seems obvious, but I got caught up in my initial tests!)

The [TVControllerMain.ino](https://github.com/alexanderldavis/tvcontroller/blob/master/TVControllerMain.ino) that I have uploaded shows the proper format for my remote.

Once the TVControllerMainBlank code is ready, it's time to start transmitting the code!

Assemble these pieces as shown in the diagram below (FIG2). Plug Arduino into your computer.

(FIG2)
![Arduino Transmitter](https://raw.githubusercontent.com/alexanderldavis/tvcontroller/master/Images/irtransmitter_bb.png)


Then, upload TVControllerMainBlank.ino to Arduino. Once it compiles, you can unplug your Arduino from your base computer. The Arduino is set up. 

*QUICK NOTE: For aesthetic purposes, you can also simply plug the IR transmitter bulb directly into the Arduino. Just be sure the positive (longer leg) is in port 13, and the negative (shorter leg) is in GRND (ground).*


### (3) Enable Arduino-Serial
To control the arduino from the command line, we use a tool called [arduino-serial](https://github.com/todbot/arduino-serial). This treats the arduino like a serial connection, which we can manipulate from the command line.

Return to the SSH connection in your base computer's terminal. Now, type ```sudo su -s /bin/bash homeassistant``` to change to the homeassistant user. Next, type ```cd``` to get you to the home directory of the homeassistant user. Clone arduino-serial to your directory by typing ```git clone https://github.com/todbot/arduino-serial.git```. Then cd into the created folder by typing ```cd arduino-serial```. Type ```make``` to make the C++, and then type ```./arduino-serial``` to return to the directory.

You can now type ```exit``` to return to your pi user. Next, plug your arduino into your raspberry pi and type ```ls /dev/ttyACM*``` to see all connections. (On mac or windows, this command is ```ls /dev/tty.*``` You should see a connection name like ```/dev/ttyACM0```returned to the screen. Keep this connection name for safe keeping.

### (4) Connect Arduino-Serial to HASS
Next, you will want to download the configuration.yaml file I provide above. You should then fill in all of the [REDACTED] fields with your information. This includes latitude, longitude, elevation, and an api_password of your choice.

Next, scroll down to the "# TV Controller" handle near the bottom. It should look like this:
```
switch:
 platform: command_line
 switches:
   television:
     command_on: "~/arduino-serial/arduino-serial -b 9600 -p /dev/ttyACM0 -s 1"
     command_off: "~/arduino-serial/arduino-serial -b 9600 -p /dev/ttyACM0 -s 1"
     value_template: '{{ return_value == "1" }}'
     friendly_name: TV
```
In the command_on and command_off categories, change my /dev/ttyACM0 to the /dev/tty address you wrote down earlier. Change them for both command_off and command_on categories!
DON'T FORGET TO UPDATE THE REDACTED CATEGORIES, OR ELSE THE PARSER WILL HAVE DIFFICULTIES WITH YOUR FILES!!!

Save the configuration.yaml file and open a NEW terminal window on your base computer. Now, type ```scp ~/[location_of_the_file]/configutation.yaml pi@[your_pi_address]:~/Desktop/``` and enter your Raspberry Pi's password when prompted. Then, return to the SSH terminal window on your base computer and type ```sudo mv ~/Desktop/configuration.yaml ~/../homeassistant/.homeassistant/```. This will copy your updated .yaml file into your homeassistant directory. Next, type ```sudo systemctl restart home-assistant.service``` to restart the homeassistant service. Barring any issues, you should be able to refresh your browser window and see a switch called "TV". When you press the lightning icon, your TV should turn on! No more looking for the remote! Hourra!

If you have any issues, you can type ```cat ~/../homeassistant/.homeassistant/home-assistant.log``` to see a console log of any issues. This can help diagnose issues with your homeassistant software going forward.

### (5) Connect Alexa to HASS
TODO: I will add to these instructions as I continue to figure them out! I think the next steps will involve creating a personal Skill for the Alexa.


## About The Project
[This is an intro I wrote while procrastinating on a project, so feel free to skip it!]
We humans (for we are humans--right?), are on the verge of a massive revolution. I'm sure I'm hardly the only one who was enchanted by the Orwellian prospect of a humanity entirely dependent on technology, and while some may cite Karel Čapek's R.U.R to suggest the deleterious impact of robots on humanity, I stubbornly submit the same text as evidence to suggest the benefits of a robot revolution. Humanity's definition of itself is far too narrow, and the declaration of sentiency for man-made items should not be restricted to offspring.
While we are not quite at the point of Westworld-ian technology (I side with Ford's vision of humanity, BTW), I enjoy engaging in these debates!

Anyhoo, I am interested in participating in the eventual creation of this sentiency, and I believe it begins with having a robot turn on and off a TV!

Ever since I purchased an Amazon Echo (www.amazon.com) for my dorm room (late 2015), I set out to find ways to grant her more control over aspects of life in the room. This ambitious goal began with simple lights operating on WeMo Switch (www.belkin.com) hardware, as well as hands-free control of basic functions of my Mac, including sleep and wake functions. 

In my quest to make the Alexa an unrivaled master of a kingdom that sprawls 3 meters x 5 meters, I have come to the realization that limitations imposed by the archaic Internet security technicians at my school significantly impact my ability to connect devices to the Internet of Things. Registering the Alexa was difficult enough, I finally had to put her on the phone to explain what she was to the registration technician. I have therefore began to research ways to have her control other devices remotely (or at least without too much reliance on WiFi).

So it begins....
