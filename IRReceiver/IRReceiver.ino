
#define IRpin_PIN      PIND
#define IRpin          2
#define MAXPULSE 65000
#define RESOLUTION 20 
uint16_t pulses[100][2];  // pair is high and low pulse 
uint8_t currentpulse = 0; // index for pulses we're storing
 
void setup(void) {
  Serial.begin(9600);
  Serial.println("Ready to decode IR!");
}
 
void loop(void) {
  uint16_t highpulse, lowpulse;  // temporary storage timing
  highpulse = lowpulse = 0; // start out with no pulse length
    while (IRpin_PIN & (1 << IRpin)) {
     highpulse++;
     delayMicroseconds(RESOLUTION);
    if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
       printpulses();
       currentpulse=0;
       return;
     }
  }
  pulses[currentpulse][0] = highpulse;
   while (! (IRpin_PIN & _BV(IRpin))) {
     // pin is still LOW
     lowpulse++;
     delayMicroseconds(RESOLUTION);
     if ((lowpulse >= MAXPULSE)  && (currentpulse != 0)) {
       printpulses();
       currentpulse=0;
       return;
     }
  }
  pulses[currentpulse][1] = lowpulse;
  currentpulse++;
}
 
void printpulses(void) {
  Serial.println("void buttonName() {");
  for (uint8_t i = 0; i < currentpulse; i++) {
    Serial.print("\tdelayMicroseconds(");
    Serial.print(pulses[i][0] * RESOLUTION, DEC);
    Serial.print(")\n");
    Serial.print("\tpulseIR(");
    Serial.print(pulses[i][1] * RESOLUTION, DEC);
    Serial.print(");\n");
  }
  Serial.println("}");
}
//OLD CODE:
//void printpulses(void) {
//  Serial.println("\n\r\n\rReceived: \n\rOFF \tON");
//  for (uint8_t i = 0; i < currentpulse; i++) {
//    Serial.print(pulses[i][0] * RESOLUTION, DEC);
//    Serial.print(" usec, ");
//    Serial.print(pulses[i][1] * RESOLUTION, DEC);
//    Serial.println(" usec");
//  }
//}

