//      1
//     ---
//  2 |   | 3
//    | 4 |
//     ---
//  5 |   | 6
//    |   |
//     ---
//      7
//int pin_1 = 13;
//int pin_2 = 12;
//int pin_3 = 14;
//int pin_4 = 27;
//int pin_5 = 26;
//int pin_6 = 25;
//int pin_7 = 33;
//int pin_8 = 32; //Punkt
//
//int D1 = 35;
//int D2 = 34;
//int D3 = 39;
//int D4 = 36;

//uint8_t is same as byte, an "int" is an unsigned 16 bit variable (uses two bytes of memory).
//better to use const byte led = 13, then the compiler knows that it's a byte type and tells you if you do something stupid with it.
//const byte X = 4 is same as #define X 4

//If you are running out of ram, it may be in part due to not having constants in PROGMEM.
//For example, if you do this: Serial.print("Sensor control - Main Menu");
//that string is copied into SRAM and wastes it. If you do this instead:
//Serial.print(F("Sensor control - Main Menu")); or Serial.print_P(PSTR("Sensor control - Main Menu"));
//the string will be copied from program memory directly to the output and not use any SRAM.
//Another way to save SRAM is to use MALLOC() and FREE() to dynamically allocate and de-allocate buffers on the fly,
//rather than having several defined all the time. Or, use one common buffer among all functions that need it.
//I'll bet though you will gain the most savings by moving all your constants into PROGMEM where possible.

const byte pins[12] = {13, 12, 14, 27, 26, 25, 33, 32, 35, 34, 39, 36};
const byte rows[4] = {35, 34, 39, 36};
const byte cols[8] = {13, 12, 14, 27, 26, 25, 33, 32};

byte screen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile byte screenRow = 0;
volatile byte screenCol = 0;

byte numbers[11][7] = {
  {1,1,1,1,1,1,0}, //zero
  {0,0,0,0,1,1,0}, //one
  {1,1,0,1,1,0,1}, //two
  {1,0,0,1,1,1,1}, //three
  {0,0,1,0,1,1,1}, //four
  {1,0,1,1,0,1,1}, //five
  {1,1,1,1,0,1,1}, //six
  {0,0,0,1,1,1,0}, //seven
  {1,1,1,1,1,1,1}, //eight
  {1,0,1,1,1,1,1}, //nine
  {0,0,0,0,0,0,0}  //off
};

// the setup routine runs once when you press reset:
void setup() {

for (int i = 0; i < 12; i++)
{
  pinMode(pins[i], OUTPUT);
}

// initialize the digital pins as outputs.
//  pinMode(pin_1, OUTPUT);
//  pinMode(pin_2, OUTPUT);
//  pinMode(pin_3, OUTPUT);
//  pinMode(pin_4, OUTPUT);
//  pinMode(pin_5, OUTPUT);
//  pinMode(pin_6, OUTPUT);     
//  pinMode(pin_7, OUTPUT);
//  pinMode(pin_8, OUTPUT);
//  pinMode(D1, OUTPUT);
//  pinMode(D2, OUTPUT);
//  pinMode(D3, OUTPUT);
//  pinMode(D4, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  digitalWrite(translatePin(rows[screenRow]), HIGH); // set previous off
  digitalWrite(translatePin(cols[screenCol]), LOW);  // set previous off
  // go to the next iteration...
  // go to the next screenCol, wrap if necessary
  screenCol++;
  if (screenCol >= 8) {
    screenCol = 0;
    // when screenCol wraps, go to the next screenRow, wrap if necessary
    screenRow++;
    if (screenRow >= 4) {
      screenRow = 0;
    }
  }
  // set this iteration
  if((screen[screenRow]>>screenCol)&B1 == B1) {
    digitalWrite(translatePin(rows[screenRow]), LOW);  // set this on
    digitalWrite(translatePin(cols[screenCol]), HIGH); // set this on
  } else {
    digitalWrite(translatePin(rows[screenRow]), HIGH); // set this off
    digitalWrite(translatePin(cols[screenCol]), LOW);  // set this off
  }


  
//  digitalWrite(D1, HIGH);
//  digitalWrite(D2, LOW);
//  digitalWrite(D3, LOW);
//  digitalWrite(D4, LOW); 
//  //number 1
//  digitalWrite(pin_1, LOW);   
//  digitalWrite(pin_2, HIGH);   
//  digitalWrite(pin_3, LOW);   
//  digitalWrite(pin_4, LOW);   
//  digitalWrite(pin_5, HIGH);   
//  digitalWrite(pin_6, LOW);   
//  digitalWrite(pin_7, LOW);
//  digitalWrite(pin_8, LOW); 
//  delay(1000);               // wait for a second
  
//  digitalWrite(D1, LOW);
//  digitalWrite(D2, HIGH);
//  digitalWrite(D3, LOW);
//  digitalWrite(D4, LOW); 
  //1
//  digitalWrite(pinA, LOW);   
//  digitalWrite(pinB, LOW);   
//  digitalWrite(pinC, LOW);   
//  digitalWrite(pinD, HIGH);   
//  digitalWrite(pinE, LOW);   
//  digitalWrite(pinF, LOW);   
//  digitalWrite(pinG, LOW);   
//  delay(1);               // wait for a second
  
//  digitalWrite(D1, LOW);
//  digitalWrite(D2, LOW);
//  digitalWrite(D3, HIGH);
//  digitalWrite(D4, LOW); 
//  //2
//  digitalWrite(pinA, HIGH);   
//  digitalWrite(pinB, HIGH);   
//  digitalWrite(pinC, LOW);   
//  digitalWrite(pinD, HIGH);   
//  digitalWrite(pinE, LOW);   
//  digitalWrite(pinF, HIGH);   
//  digitalWrite(pinG, LOW);     
//  delay(1);               // wait for a second
//
//  digitalWrite(D1, LOW);
//  digitalWrite(D2, LOW);
//  digitalWrite(D3, LOW);
//  digitalWrite(D4, HIGH); 
//  //3
//  digitalWrite(pinA, LOW);   
//  digitalWrite(pinB, HIGH);   
//  digitalWrite(pinC, LOW);   
//  digitalWrite(pinD, HIGH);   
//  digitalWrite(pinE, LOW);   
//  digitalWrite(pinF, LOW);   
//  digitalWrite(pinG, HIGH);     
//  delay(1);               // wait for a second
/*  
  //4
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //5
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //6
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //7
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  delay(1000);               // wait for a second
  
  //8
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second

  //9
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  */
}
