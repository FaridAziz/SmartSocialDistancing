#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "FARID";
const char* password = "dewafarsa0500";
const char* host = "192.168.1.14/";

int irPin1 = D7;
int irPin2 = D4;
int count = 0;

boolean state = true;

void setup() {
  Serial.begin(9600);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);

  WiFi.hostname("NodeMCU");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

//  Serial.println("WIFI CONNECTED");

}

void loop() {

  WiFiClient  client;
  if (!client.connect(host, 80)) {
    Serial.println("Connection Failed");
    return;
  }

  if (!digitalRead(irPin1) && state) {
    count++;
    state = false;
//    Serial.print("Count : ");
    Serial.println(count);
    delay(500);
  }
  else if(!digitalRead(irPin2) && state){
    count--;
    state = false;
//    Serial.print("Count : ");
    Serial.println(count);
    delay(500);
  }

  if (digitalRead(irPin1)) {
    state = true;
//    delay(100);
  }
  else if(digitalRead(irPin2)){
    state = true;
  }

  String Link;
  HTTPClient http; 
  Link = "http://192.168.1.14/webserver/public/kirimdata?pengunjung=" + String(count);

  http.begin(Link);

  http.GET();
  http.end();
  delay(100);

}
