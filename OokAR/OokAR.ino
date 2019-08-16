#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <memory>
#include <Arduino.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

#define Wdata "/Wdata.php?dados="
#define Rdata "/Rdata.php"

/*const char* ssid = "VIVO-CEBF";
const char* password = "FB5E9ACEBF";*/
//_________________________________________________________________________________

const char* ssid = "Lab_Icarus";
const char* password = "pizzadomestre10";
String Ipv4 = "http://192.168.0.116/";
//_________________________________________________________________________________

int MDF = 5;
int MDT = 4;
int MEF = 12;
int MET = 14;

void setup () {
  
  pinMode(MDF, OUTPUT);
  pinMode(MDT, OUTPUT);
  pinMode(MEF, OUTPUT);
  pinMode(MET, OUTPUT);
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(".");
  EspInit();

}
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin(Ipv4+Rdata);  //Specify request destination                                                                              
      
    int httpCode = http.GET();                                                                  //Send the request
    
      if (httpCode > 0) { //Check the returning code
        String payload = http.getString();   //Get the request response payload <-------------------------------------------ORIGINAL
        Serial.println(payload);
        if (payload == "Tras"){
           digitalWrite(MDF, HIGH);
           digitalWrite(MDT, LOW);
           digitalWrite(MEF, HIGH);
           digitalWrite(MET, LOW);
        }
       else if (payload == "Frente"){
           digitalWrite(MDF, LOW);
           digitalWrite(MDT, HIGH);
           digitalWrite(MEF, LOW);
           digitalWrite(MET, HIGH);
        }
        else if(payload == "Direita"){
           digitalWrite(MDF, HIGH);
           digitalWrite(MDT, LOW);
           digitalWrite(MEF, LOW);
           digitalWrite(MET, HIGH);
        }
        else if(payload == "Esquerda"){
           digitalWrite(MDF, LOW);
           digitalWrite(MDT, HIGH);
           digitalWrite(MEF, HIGH);
           digitalWrite(MET, LOW);
        }
        else{
           digitalWrite(MDF, LOW);
           digitalWrite(MDT, LOW);
           digitalWrite(MEF, LOW);
           digitalWrite(MET, LOW);
        }
      }
 
    http.end();
  }
  delay(100);  
}
