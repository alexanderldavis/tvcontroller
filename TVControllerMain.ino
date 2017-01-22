 int IRledPin =  13;    // LED connected to digital pin 13
 const int buttonPin = 10;

 //Volume Controls
 int volumeLevel = 0;

 //Input Controls
 int inputLevel = 0;
 //Key: 0=TV, 1=Wii, 2=AppleTV, 3=FireTV, 4=XBOX, 5=PC, 6=USB
 

 void setup() {
   // initialize the IR digital pin as an output:
   pinMode(IRledPin, OUTPUT);
   pinMode(buttonPin, INPUT);    

   Serial.begin(9600);
 }

 void loop() {
   int val = Serial.read();
   //Main TV Controls
   if (val == '1') {
    PowerButton();
   }
   if (val == '2') {
    inputButton();
   }
   if (val == '3') {
    upButton();
   }
   if (val == '4') {
    downButton();
   }
   if (val == '5') {
    leftButton();
   }
   if (val == '6') {
    rightButton();
   }
   if (val == '7') {
    volIncreaseButton();
   }
   if (val == '8') {
    volDecreaseButton();
   }
   if (val == '9') {
    //NAVIGATE TO APPLETV
    if (inputLevel == '0') {
      inputButton();
      inputButton();
      inputButton();
    }
    if (inputLevel == '1') {
      inputButton();
      inputButton();
    }
    if (inputLevel == '2') {
      
    }
    if (inputLevel == '3') {
      inputButton();
      upButton();
    }
    if (inputLevel == '4') {
      inputButton();
      upButton();
      upButton();
    }
    if (inputLevel == '5') {
      inputButton();
      upButton();
      upButton();
      upButton();
    }
    if (inputLevel == '6') {
      inputButton();
      upButton();
      upButton();
      upButton();
      upButton();
    }
   }
   

   //Main Apple TV Controls
   
 }
void pulseIR(long microsecs) {
   // we'll count down from the number of microseconds we are told to wait

   cli();  // this turns off any background interrupts

   while (microsecs > 0) {
     // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds(10);         // hang out for 10 microseconds
    digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
    delayMicroseconds(10);         // hang out for 10 microseconds

    // so 26 microseconds altogether
    microsecs -= 26;
   }

   sei();  // this turns them back on
 }
void volDecreaseButton() {
  delayMicroseconds(10888);
  pulseIR(9280);
  delayMicroseconds(4580);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(620);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(40980);
  pulseIR(9220);
  delayMicroseconds(2360);
  pulseIR(620);
  delayMicroseconds(33024);
  pulseIR(9260);
  delayMicroseconds(2340);
  pulseIR(620);
}


void volIncreaseButton() {
  delayMicroseconds(4272);
  pulseIR(9300);
  delayMicroseconds(4560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(520);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1640);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(40940);
  pulseIR(9320);
  delayMicroseconds(2280);
  pulseIR(640);
  delayMicroseconds(33004);
  pulseIR(9320);
  delayMicroseconds(2260);
  pulseIR(640);
}


void rightButton() {
  delayMicroseconds(31108);
  pulseIR(9280);
  delayMicroseconds(4580);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(580);
  delayMicroseconds(1720);
  pulseIR(580);
  delayMicroseconds(1720);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(40960);
  pulseIR(9300);
  delayMicroseconds(2300);
  pulseIR(600);
}


void leftButton() {
  delayMicroseconds(50452);
  pulseIR(9320);
  delayMicroseconds(4540);
  pulseIR(660);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(660);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(500);
  pulseIR(660);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1640);
  pulseIR(640);
  delayMicroseconds(40940);
  pulseIR(9320);
  delayMicroseconds(2280);
  pulseIR(640);
  delayMicroseconds(32984);
  pulseIR(9340);
  delayMicroseconds(2260);
  pulseIR(640);
}


void downButton() {
  delayMicroseconds(43864);
  pulseIR(9300);
  delayMicroseconds(4560);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(40940);
  pulseIR(9300);
  delayMicroseconds(2300);
  pulseIR(620);
}



void upButton() {
  delayMicroseconds(53328);
  pulseIR(9300);
  delayMicroseconds(4560);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(1700);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(1700);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(40960);
  pulseIR(9280);
  delayMicroseconds(2300);
  pulseIR(620);
  delayMicroseconds(33024);
  pulseIR(9220);
  delayMicroseconds(2360);
  pulseIR(620);
}


 void inputButton() {
  // Code for Input Button
  delayMicroseconds(59920);
  pulseIR(9300);
  delayMicroseconds(4580);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(640);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1700);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(40960);
  pulseIR(9300);
  delayMicroseconds(2300);
  pulseIR(600);  
 }


 void PowerButton() {
   // Code for Power Button
  
  delayMicroseconds(57964);
  pulseIR(9280);
  delayMicroseconds(4580);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(600);
  delayMicroseconds(1700);
  pulseIR(600);
  delayMicroseconds(1700);
  pulseIR(600);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1660);
  pulseIR(620);
  delayMicroseconds(540);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(620);
  delayMicroseconds(1680);
  pulseIR(600);
  delayMicroseconds(40960);
  pulseIR(9300);
  delayMicroseconds(2300);
  pulseIR(620);
 } 
