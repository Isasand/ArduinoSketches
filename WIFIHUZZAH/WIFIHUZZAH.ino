#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "";
const char* password = "";

ESP8266WebServer server(80); //vilken port du kör på
const int led = 13; 

void handleRoot(){
  digitalWrite(led, 1);
  server.send(200, "text/plain", "Hello world!");
  digitalWrite(led, 0);
}

void handleNotFound(){
  String message = "File not found";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

 for (uint8_t i = 0; i < server.args(); i++){
  message += " " + server.argName(i) + server.arg(i) + "\n";
 }
 server.send(404, "text/plain", message);
}


void setup() {
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connecting to Wifi");

  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
}

void ShowConnection(){
  Serial.println("");
  Serial.print("Connected to: "); 
  Serial.println(ssid); 
  Serial.print("IP-adress: ");
  Serial.print(WiFi.localIP());
  delay(1000);
}

void loop() {
  ShowConnection();
  server.handleClient();
}
