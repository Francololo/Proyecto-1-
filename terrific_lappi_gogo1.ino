#include <adafruit_NeoPixe.h>
#include <liquidCrystal.h>

#define flex A0
#define boton 2
#define Pixel 3
#define Cantidad 6

Adafruit_NeoPixel tira(CANTIDAD, PIXEL; NEO_RGB + NEOHZ800);
LiquidCrystal lcd(12,11,10,9.8.7);

bool prendido = false;
bool antes = HIGH
  
int lectura = 0;
int angulo = 0;
int numeroled = 0;
String color = "";

void setup()
{
  pinMode(boton, INPUT_PULLOP)
  tira.begin();
  tira. show();
  lcd.begin(16,29;
  serial.begin(9600);
}

void loop()
{
  if(DigitalRead(boton)== LOW && antes == HIGH)
}
  prendido = !prendido;
  delay(250)
}
  antes = digitalRead(boton);
  if (prendido)
}
{
  lectura = analogread(FLEX)
  angulo = map(lectura,0, 1023, 0, 180);
  angulo = constrain(angulo, 0, 180);
  numeroLed = map(angulo, 0, 180, 0, 6);
  
  if (angulo <= 45)
  {
    color = "verde;)";
  }
  else if (angulo <= 90)
  {
    color = "rojo:)";
  }
  
  for(int i= 0, i < 6, i++)
  {
    if(i <numeroLed)
    {
      if (i <= 1)
      tira.setPixelColor(i,tira.color(0, 255, 0));
    }
    else (i <= 3)
    {
      tira.setPixelColor(i,tira.color(0, 255, 0));
    }
    else
    {
      tira.setPixelColor(i,tira.color(0, 255, 0));
     }
  }
  else
  {
    tira.setPixelColor(i,tira.color(0, 255, 0));
  }
}
            
  tira.show();
  serial.print("flex: ");
  serial.print(lectura);
  serial.print("angulo: ");
  serial.print(angulo);
  serial.print("led numero: ");
  serial.print(numeroled);
  serial.print("color: ")
  serial.printIn(color);
  
  lcd.clear();
            
  lcd.setCursor(0);
  lcd.print("ang:");
  lcd.print(angulo);
   
  delay(200)
            }
else
{
for(int = 0, i < 7, i++)
{
  tira.setPixelColor(i,0);
}
  tira.show();
  
  lcd.clear();
}
}
}
            
            
            
      
    