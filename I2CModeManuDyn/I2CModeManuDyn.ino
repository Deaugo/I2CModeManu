#include <Wire.h>
#include "Ressources.h"

#define I2C_SLAVE_ADRESS 11


void setup() 
{
  //int masque = 0x100;
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(35,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(37,OUTPUT);
  pinMode(38,INPUT);
  pinMode(39,INPUT);
  pinMode(40,INPUT);
  pinMode(41,INPUT);
  pinMode(42,INPUT);
  pinMode(43,INPUT);
  pinMode(44,INPUT);
  pinMode(45,INPUT);
  digitalWrite(22,HIGH);
  digitalWrite(23,HIGH);
  digitalWrite(24,HIGH);
  digitalWrite(25,HIGH);
  digitalWrite(26,HIGH);
  digitalWrite(27,HIGH);
  digitalWrite(28,HIGH);
  digitalWrite(29,HIGH);
  digitalWrite(30,HIGH);
  digitalWrite(31,HIGH);
  digitalWrite(32,HIGH);
  digitalWrite(33,HIGH);
  digitalWrite(34,HIGH);
  digitalWrite(35,HIGH);
  digitalWrite(36,HIGH);
  digitalWrite(37,HIGH);
  
  Wire.begin(I2C_SLAVE_ADRESS);
  Serial.begin(9600);
  Serial.println("---------------Slave 1");
  delay(1000);
  Wire.onRequest(requestEvents);
  Wire.onReceive(receiveEvents);
}

void loop() {
  Serial.println("Debut de la boucle");
  while (flag == LOW)
  {
    Serial.println("Stand by...\n");
    delay(50);
    MajDataTable();
    for (i = 0; i<8; i++)
  {
    Serial.println(DataTab[i]);
  }
  }
  flag = LOW;

  numRelai = TabData[0];
   modeConfig = TabData[1];
   Serial.println("numéro du relai : ");
   Serial.println(numRelai);
   Serial.println("type de config : ");
   Serial.println(modeConfig);
    
   if (numRelai>=30 && numRelai<=37)
   {
     configRelai(numRelai,modeConfig);
   }
   else if (numRelai<30)
   {
     commandeRelai(numRelai);
   }
   else {}

}

void receiveEvents(int numBytes)
  {
   Serial.println("Bytes Reçu...\n");
   flag = HIGH;
   Serial.println(decompte);
   TabData[decompte] = Wire.read();
   Serial.println(TabData[decompte]);
   //compteur(decompte);
   if (decompte == 1)
  {
    decompte = 0;
  }
  else
  {
    decompte++;
  }
  Serial.println("decompte : ");
  Serial.println(decompte);
  }

void requestEvents(int numBytes)
  {
    Serial.println("requète reçu");
      for (i = 0; i<8; i++)
        {
          Wire.write(DataTab[i]);
        }
    
  }
