#include "DHT.h"
#define DHTTYPE DHT11
#define dht_pin D5
DHT dht(dht_pin,DHTTYPE);

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

    // Dapetin token
char auth[] = "t8HHT8tly0K3CSaFgIcqQdO9UCkXvG6I";
    // id dan password internet 
char ssid[] = "BEBAS TETRING";
char pass[] = "12345678";

void setup(){
  Serial.begin(115200);
  dht.begin();
  
  //kalo pake serangkota jangan lupa ganti jadi
  Blynk.begin(auth, ssid, pass, "iot.serangkota.go.id", 8080);
  //Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, ssid, pass);
}

void loop(){
  float s = dht.readTemperature();
  float h = dht.readHumidity();
  Blynk.run();
  Blynk.virtualWrite(V0, s);
  Blynk.virtualWrite(V1, h);
  
}
