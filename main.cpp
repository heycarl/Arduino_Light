#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
int relay1pin = 5;
int relay2pin = 4;
int relay3pin = 0;
int relay4pin = 2;
int red_pin = 14;
int green_pin = 12;
int blue_pin = 13;
int red = 0;
int green = 0;
int blue = 0;

const char* ssid = "Community_Super";
const char* password = "9876543210";

ESP8266WebServer server(80);

const int led = 13;

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp8266!");
  digitalWrite(led, 0);
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  pinMode(relay1pin, OUTPUT);
  pinMode(relay2pin, OUTPUT);
  pinMode(relay3pin, OUTPUT);
  pinMode(relay4pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  digitalWrite(relay1pin, 1);
  digitalWrite(relay2pin, 1);
  digitalWrite(relay3pin, 1);
  digitalWrite(relay4pin, 1);
  analogWrite(red_pin, 0);
  analogWrite(green_pin, 0);
  analogWrite(blue_pin, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);



  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.on("/r1on", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay1pin, 0);
  });
  server.on("/r1off", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay1pin, 1);
  });

  server.on("/r2on", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay2pin, 0);
  });
  server.on("/r2off", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay2pin, 1);
  });

  server.on("/r3on", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay3pin, 0);
  });
  server.on("/r3off", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay3pin, 1);
  });

  server.on("/r4on", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay4pin, 0);
  });
  server.on("/r4off", [](){
    server.send(200, "text/plain", "well done");
    digitalWrite(relay4pin, 1);
  });

  server.on("/rgb", [](){
    red = server.arg("red").toInt();
    green = server.arg("green").toInt();
    blue = server.arg("blue").toInt();
    analogWrite(red_pin, red);
    analogWrite(green_pin, green);
    analogWrite(blue_pin, blue);
    server.send(200, "text/plain", "well done");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
