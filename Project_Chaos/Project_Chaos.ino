#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <SoftwareSerial.h>
char b;
SoftwareSerial btSerial(A0, 8); // RX, TX
IRsend irsend;
void setup(){
    btSerial.begin(9600);
    //Serial.begin(9600);
    //pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
    if(btSerial.available()){
        b = (char)btSerial.read();

        //btSerial.print("Hello Hamzah");
       // btSerial.println(b, HEX);
       }
       
       switch (b) {
        case 'a':
          irsend.sendNEC(0x40BD28D7,32); //ON
          btSerial.println("ON");
          break;
       
        case 'b':
          irsend.sendNEC(0x40BD30CF,32); //MUTE
          btSerial.println("MUTE");
          break;
          
        case 'c':
          irsend.sendNEC(0x40BD48B7,32); //CHANNEL ++
          btSerial.println("CHANNEL ++");
          break;
          
        case 'd':
          irsend.sendNEC(0x40BDC837,32); //CHANNEL --
          btSerial.println("CHANNEL --");
          break;
          
        case 'e':
          irsend.sendNEC(0x40BD08F7,32); //VOLUME ++
          btSerial.println("VOLUME ++");
          break;
          
        case 'f':
          irsend.sendNEC(0x40BD8877,32); //VOLUME --
          btSerial.println("VOLUME --");
          break;
       }
       
Serial.println(b);
       
}
