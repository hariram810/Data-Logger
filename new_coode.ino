#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-9GFAQy6iJqM1GugslQh0kqRBcQdIOeS";  // copy the code from email
char ssid[] = "Zeno_Modiff";  // type your wifi name
char pass[] = "UFMTRBRR";       // type your wifi password

WidgetLED led2(V2);
BlynkTimer timer;

BLYNK_WRITE(V4){
  
  int pinValue = param.asInt();

  if(pinValue == 1){
    led2.on();
  }
  if(pinValue == 0){
    led2.off();
  }
}
