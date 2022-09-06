#define BLYNK_TEMPLATE_ID  "TMPLs5ZipwEB"
#define BLYNK_DEVICE_NAME "Smart Trap"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include <ESP8266WiFi.h>
#include <WiFiClientSecureAxTLS.h>
#include "BlynkEdgent.h"
#define USE_NODE_MCU_BOARD
void Line_Notify(String message) ;
#define LINE_TOKEN "wnetD8Q54F2bsmFG5AVvDqIPpsyF5QbpcrQ84kaEQ6W"// line TOKEN
  char auth[] = "Ux7UNW119r_gXP6-iC7pDMg0CliMNlnd"; // Blynk TOKEN 
  const char ssid[] = "realme";
  const char pass[] = "00000000";
  int PIRStatus = 0;
  int Status = 0;
    WidgetLCD LCD(V0);
    WidgetLED LED(V1);
void setup()
{
   Serial.begin(9600);
   pinMode(D1,INPUT);
   pinMode(D2,OUTPUT);
   Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V2){ 
  Serial.println(param.asInt()); 
   Serial.println(Status); 
    if (param.asInt()){
      Status = 1;
      LCD.clear();
      LCD.print(1,0,"On The System"); 
      LCD.print(4,1,"<<Mode>>");
      LED.on();
     } else {  
     Status = 0;  
      LED.off();
      LCD.clear(); 
      LCD.print(1,0,"Off The System"); 
      LCD.print(4,1,"<<Mode>>");
      digitalWrite(D2, HIGH);
 }
}
void loop(){
  Blynk.run();
  digitalWrite(D2, HIGH);
  if (Status == 1){
    if (digitalRead(D1)){
      LCD.clear(); 
      LCD.print(2,0,"Some One Come"); 
      LCD.print(4,1,"<<Danger>>");  
      if (!PIRStatus){
        PIRStatus = 1;
        digitalWrite(D2, LOW);
        Blynk.notify("Some One Come");
        Line_Notify("Some One Come");
        LED.on();
        delay(3000);
        LCD.clear(); 
        LCD.print(1,0,"Everything OK "); 
        LCD.print(4,1,"<< OK >>");  
        digitalWrite(D2, HIGH);  
        LED.off();
        PIRStatus = 0;
        LED.off();
    }
  }
  }
  else
  {
    LED.off();
    Serial.println("off");
  }
}

 void Line_Notify(String message) {
  axTLS::WiFiClientSecure client; // กรณีขึ้น Error ให้ลบ axTLS:: ข้างหน้าทิ้ง

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");  
    return;
  } 
  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  // Serial.println(req);
  client.print(req);

  // Serial.println("-------------");
  while(client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
}
