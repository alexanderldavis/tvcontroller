 int IRledPin =  13;    // LED connected to digital pin 13
 const int buttonPin = 10;
 int previousButtonState = 0;
 int buttonState = 0;

 // The setup() method runs once, when the sketch starts

 void setup()   {
   // initialize the IR digital pin as an output:
   pinMode(IRledPin, OUTPUT);
   pinMode(buttonPin, INPUT);    

   Serial.begin(9600);
 }

 void loop()                    
 {
   buttonState = digitalRead(buttonPin);
   if(buttonState != previousButtonState){
    if(buttonState == HIGH){ //Sends the code every time the button is pressed.
      SendChannelUpCode();
    }
   }
   previousButtonState = buttonState;
 }

 // This procedure sends a 38KHz pulse to the IRledPin
 // for a certain # of microseconds. We'll use this whenever we need to send codes
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

 void SendChannelUpCode() {
   // This is the code for the CHANNEL + for the TV COMCAST
  
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
