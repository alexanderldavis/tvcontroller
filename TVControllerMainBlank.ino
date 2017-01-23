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
    //Name of the first button function
    //Example: PowerButton();
   }
   if (val == '2') {
    //Name of the second button function
   }
   if (val == '3') {
    //Name of the third button function
   }
   // To add more buttons, just follow the pattern and keep incrementing val == '3' by one # every time!
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

////////////// Place the IRReceiver Serial Monitor Output here: (rename the 'name' of the functions) //////////


//Place code here 


////Sample code:
//void volDecreaseButton() {
//  delayMicroseconds(10888);
//  pulseIR(9280);
//  delayMicroseconds(4580);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(600);
//  delayMicroseconds(1680);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(620);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1660);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1660);
//  pulseIR(620);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(560);
//  pulseIR(600);
//  delayMicroseconds(540);
//  pulseIR(620);
//  delayMicroseconds(540);
//  pulseIR(620);
//  delayMicroseconds(540);
//  pulseIR(620);
//  delayMicroseconds(540);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(600);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(620);
//  delayMicroseconds(1680);
//  pulseIR(600);
//  delayMicroseconds(40980);
//  pulseIR(9220);
//  delayMicroseconds(2360);
//  pulseIR(620);
//  delayMicroseconds(33024);
//  pulseIR(9260);
//  delayMicroseconds(2340);
//  pulseIR(620);
//}
