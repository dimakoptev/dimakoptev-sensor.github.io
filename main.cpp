#include <Arduino.h>
//#include <WiFi.h>
//#include <WebServer.h>
//#include <WiFiClient.h>

// SSID & Password
// const char* ssid = "HUAWEI-B525- 4";  //Võrgu nimi
// const char* password = "A1234567890";  //Password
// WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

// Current time
//unsigned long currentTime = millis();
// Previous time
//unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
//const long timeoutTime = 2000;

//Using 74HC595N to get more free pins
//Pin connected to latch pin (ST_CP) of 74HC595N
const int latchPin = 13;
//Pin connected to clock pin (SH_CP) of 74HC595N
const int clockPin = 12;
//Pin connected to Data in (DS) of 74HC595N
const int dataPin = 14;
//To display number
int D1 = 27;
int D2 = 26;
int D3 = 25;
int D4 = 33;
int D_punkt = 32; //Punkt

void setup() {

  Serial.begin(115200);

  // Serial.println("Try Connecting to ");
  // Serial.println(ssid);
  // // Connect to your wi-fi modem
  // WiFi.begin(ssid, password);
  // // Check wi-fi is connected to wi-fi network
  // while (WiFi.status() != WL_CONNECTED) {
  // delay(500);
  // Serial.print(".");
  // }

  //  // Print local IP address and start web server
  // Serial.println("");
  // Serial.println("WiFi connected.");
  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());
  // server.begin();
  // Serial.println("HTTP server started");
  // delay(100); 

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(D1, OUTPUT); pinMode(D2, OUTPUT); pinMode(D3, OUTPUT); pinMode(D4, OUTPUT);
}
//      1
//     ---
//  2 |   | 3
//    | 4 |
//     ---
//  5 |   | 6
//    |   |
//     ---
//      7
int digits [10][8]{
 //0,7,6,5,4,3,2,1
  {0,0,0,0,1,0,0,0}, // digit 0
  {0,1,0,1,1,0,1,1}, // digit 1
  {0,0,1,0,0,0,1,0}, // digit 2
  {0,0,0,1,0,0,1,0}, // digit 3
  {0,1,0,1,0,0,0,1}, // digit 4
  {0,0,0,1,0,1,0,0}, // digit 5
  {0,0,0,0,0,1,0,0}, // digit 6
  {0,1,0,1,1,0,1,0}, // digit 7
  {0,0,0,0,0,0,0,0}, // digit 8
  {0,0,0,1,0,0,0,0}  // digit 9
};

void Row(int i){
    if (i == 1) digitalWrite(D1, LOW); else digitalWrite(D1, HIGH);
    if (i == 2) digitalWrite(D2, LOW); else digitalWrite(D2, HIGH);
    if (i == 3) digitalWrite(D3, LOW); else digitalWrite(D3, HIGH);
    if (i == 4) digitalWrite(D4, LOW); else digitalWrite(D4, HIGH);
}

void DisplayDigit(int Digit)
{
  digitalWrite(latchPin,LOW);
  for (int i = 7; i>=0; i--)
  {
    digitalWrite(clockPin,LOW);
    if (digits[Digit][i]==1) digitalWrite(dataPin, LOW); 
    if (digits[Digit][i]==0) digitalWrite(dataPin, HIGH);
    digitalWrite(clockPin,HIGH);
  }
  digitalWrite(latchPin, HIGH);
}

void loop() //Siin toimub kogu koodi väljakutsumine ja kuvamine.
{
  //See funktsioon peab käima väga kiiresti, kuna kuvatakse ühte numbrit korraga. 
  //vahepeal ei tohi led ära kustuda, vaid kutsutakse uuesti funktsioon välja.
    Row(1);
    DisplayDigit(1);
    delay(5);
    Row(2);
    DisplayDigit(2);
    digitalWrite(D_punkt, HIGH);
    delay(5);
    Row(3);
    DisplayDigit(3);
    delay(5);
    Row(4);
    DisplayDigit(4);
    delay(5);

}

// // Handle root url (/)
// void handle_root() {
//   server.send(200, "text/html", HTML);


