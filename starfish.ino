#include <SoftwareSerial.h>
#include <TinyGPSMinus.h>
#include <dht11.h>
#define DHT11PIN 4
// First we include the libraries
#include <SoftwareSerial.h> //import the serial library

#define RXPIN 7 // D14 = A0 on the Arduino Nano
#define TXPIN 7 // unused
#define GPSBAUD 9600

float lat1 = 48.4652;
float lon2 = 123.3084;

TinyGPSMinus gps;
SoftwareSerial ss(RXPIN, TXPIN);

SoftwareSerial btSerial(10, 11); // set serial RX & TX to pins 10 & 11 respectively

String bt_rx; //set up recieved string variable

dht11 DHT11;

void setup()
{
   // start serial port 
 Serial.begin(9600); 
 btSerial.begin(9600);
 btSerial.println("Starfish"); 

 //btSerial.begin(115200);
  ss.begin(GPSBAUD);
  
  //btSerial.println(F("Testing TinyGPSMinus static object"));
  //btSerial.print(F("Sizeof(gpsobject) = "));
 // btSerial.print(sizeof(TinyGPSMinus));
  //btSerial.println(F(" bytes"));
  //btSerial.println();


 
}
  
 
void loop()
{
  btSerial.println();

  int chk = DHT11.read(DHT11PIN);

  btSerial.print("Humidity (%): ");
  btSerial.println((float)DHT11.humidity, 2);

  btSerial.print("Temperature  (C): ");
  btSerial.println((float)DHT11.temperature, 2);

  delay(2000);

   ss.begin(GPSBAUD);
  
  //btSerial.println(F("Testing TinyGPSMinus static object"));
  //btSerial.print(F("Sizeof(gpsobject) = "));
  //btSerial.print(sizeof(TinyGPSMinus));
  //btSerial.println(F(" bytes"));
  //btSerial.println();


  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  /*// For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (ss.available()) {
      char c = ss.read();
      // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }*/
  //if (newData) {
    char lat[9], lon[10];
    unsigned long age;
    //strcpy(lat, gps.get_latitude());
    //strcpy(lon, gps.get_longitude());
    gps.get_pos_age(&age);
    btSerial.print(("LAT = "));
    btSerial.println(lat1);

    btSerial.print(("LON = "));
    btSerial.println(lon2);
  //}
  
  /*gps.stats(&chars, &sentences, &failed);
  Serial.print(F(" CHARS="));
  Serial.print(chars);
  Serial.print(F(" SENTENCES="));
  Serial.print(sentences);
  Serial.print(F(" CSUM ERR="));
  Serial.println(failed);
   if (chars == 0) {}
    Serial.println(F("** No characters received from GPS: check wiring **"));
  } */
  
}
