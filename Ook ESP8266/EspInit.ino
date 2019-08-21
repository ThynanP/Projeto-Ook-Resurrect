void EspInit(){
String frase;
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;
    http.begin(Ipv4 + Wdata+ "Ook%20Conectado");
    
    int httpCode = http.GET();     //Send the request
    http.end();
   
  }
}
