#include<Arduino.h>

void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
}

void loop(){
    if(Serial.available()){
        char c= Serial.read();

        if(c=='1'){
            digitalWrite(LED_BUILTIN,HIGH);
            Serial.println("LED is ON");
        }else if(c=='0'){
            digitalWrite(LED_BUILTIN,LOW);
            Serial.println("LED is OFF");
        }else{
            Serial.println("You sent: ");
            Serial.println(c);
        }
    }
}