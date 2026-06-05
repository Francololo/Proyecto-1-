#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 13, 5, 4, 3, A2);

int tempPin = A0;
int luzPin = A1;

int trigPin = 7;
int echoPin = 6;

int buzzer = 8;

int rojo = 9;
int verde = 10;
int azul = 11;

float temperatura;
int luz;

long duracion;
int distancia;

void setup()
{
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
  pinMode(buzzer, OUTPUT);

  
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

  
  Serial.begin(9600);

  
  lcd.begin(16, 2);
}

void loop()
{
  
 
  int lecturaTemp = analogRead(tempPin);

  float voltaje = lecturaTemp * 5.0;
  voltaje = voltaje / 1023.0;

  temperatura = (voltaje - 0.5) * 100;

 
  
 
  luz = analogRead(luzPin);

 
  
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);

  distancia = duracion * 0.034 / 2;

 
  
 
  digitalWrite(rojo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);

 
  
 
  if (temperatura > 39)
  {
    digitalWrite(rojo, HIGH);

    tone(buzzer, 1000);
    delay(300);
    noTone(buzzer);
  }

 
  
 
  if (distancia < 100 && distancia > 50)
  {

    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);

    tone(buzzer, 800);
    delay(100);

    noTone(buzzer);
  }

 
  
 
  if (distancia <= 50)
  {

    digitalWrite(rojo, HIGH);

    tone(buzzer, 1500);
    delay(200);

    noTone(buzzer);
    delay(200);

    tone(buzzer, 1500);
    delay(200);

    noTone(buzzer);
  }

 
  
 
  if (luz < 200)
  {
    Serial.println("Modo nocturno ACTIVADO");
  }

 
  
 
  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print("T:");
  lcd.print(temperatura);

  lcd.print(" D:");
  lcd.print(distancia);

  lcd.setCursor(0, 1);

  lcd.print("L:");
  lcd.print(luz);

 
  
 
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  Serial.print("Luz: ");
  Serial.println(luz);

  Serial.print("Distancia: ");
  Serial.println(distancia);

  Serial.println("HAY ALGUIEN");

  delay(1000);
}