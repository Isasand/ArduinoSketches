#include <Wire.h>
#include <UnoWiFiDevEd.h>

int sensor_pin = A0;
int output_value;

void setup() {
  Wifi.begin();
  Wifi.println("Web Server is up");
}
void loop() {

  while(Wifi.available()){
    process(Wifi);
  }
  delay(50);
}

void process(WifiData client) { 
  String command = client.readStringUntil('/');

  if (command == "webserver") {
    WebServer(client);
  }
}
void WebServer(WifiData client) {
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,550,0,0,100);

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println("Refresh: 20");  // refresh the page automatically every 20 sec
  client.println();
  client.println("<html>");
  client.println("<head> <title>MOISTURE SERVER</title> </head>");
  client.print("<body>");

    client.print("Moisture (updates every 20 seconds): ");
    client.print(output_value);
    client.print(" % ");
    client.print("<br/>");
  

  client.print("</body>");
  client.println("</html>");
  client.print(DELIMITER); 
}
