//#include "TraitementInfo.h"

int decompte = 0;
int TabData[2];
//int TabCmd[2];
bool flag = LOW;
int modeConfig = 0;
int numRelai = 0;
int n,i;

int nConda = 0;
int nSuperconda = 0;
int nDeconda = 0;

int DataTab[8];



void compteur (int decompte)
{
  if (decompte == 1)
  {
    decompte--;
  }
  else
  {
    decompte++;
  }
  Serial.println("decompte : ");
  Serial.println(decompte);
}

void configRelai (int numRelai, int modeConfig)
{
  switch (modeConfig)
    {
      case 1 :                            // N/A
        {
           digitalWrite(numRelai,HIGH);
           break; 
        }
      case 2 :                            // Condamnation
        {
           Serial.println("configuration Condamnation\n");
           digitalWrite(numRelai,HIGH);
           nConda = numRelai;
           break; 
        }
      case 3 :                            // Décondamnation
        {
           Serial.println("configuration Décondamnation\n");
           digitalWrite(numRelai,HIGH);
           nDeconda = numRelai;
           break;
        }
      case 4 :                            //Supercondamnation
        {
           Serial.println("configuration Supercondamnation\n");
           digitalWrite(numRelai,HIGH);
           nSuperconda = numRelai;
           break;
        }
      case 5 :                            // Data Switch
        {
           Serial.println("configuration mode switch\n");
           digitalWrite(numRelai,LOW);
           
           
           break;
        }
      case 6 :                            // GND Switch
        {
           digitalWrite(numRelai,LOW);
           pinMode(numRelai+8,OUTPUT);
           digitalWrite(numRelai+8,HIGH);
           break; 
        }
      case 7 :                            // Data BUS
        {
           digitalWrite(numRelai,HIGH);
           break;
        }
      case 8:                             // Clock BUS
        {
          digitalWrite(numRelai,HIGH);
          break;
        }
              
    }
}

void commandeRelai (int numRelai)
{
  digitalWrite(numRelai,LOW);
  delay(500);
  digitalWrite(numRelai,HIGH);
}


void dataSwitch(int numRelai)
{
  
}

void MajDataTable()
{
  for (i = 0; i<8; i++)
  {
    DataTab[i] = digitalRead(38+i);
  }
}
