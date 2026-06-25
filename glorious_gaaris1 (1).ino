#include <Adafruit_NeoPixel.h>

#define PIN_LEDS     6    // Pin de datos conectado a la tira NeoPixel
#define NUM_LEDS    14    // Total de LEDs (del 0 al 13)

Adafruit_NeoPixel tira = Adafruit_NeoPixel(NUM_LEDS, PIN_LEDS, NEO_GRB + NEO_KHZ800);

uint32_t colores[13] = {
  tira.Color(255, 0, 0),     
  tira.Color(0, 255, 0),     
  tira.Color(0, 0, 255),     
  tira.Color(255, 255, 0),   
  tira.Color(0, 255, 255),   
  tira.Color(255, 0, 255),   
  tira.Color(255, 255, 255), 
  tira.Color(255, 127, 0),   
  tira.Color(128, 0, 128),   
  tira.Color(0, 255, 128),   
  tira.Color(128, 128, 255), 
  tira.Color(255, 0, 128),   
  tira.Color(255, 200, 0)    
};

void setup() {
  tira.begin();
  tira.show(); 
  randomSeed(analogRead(0)); 
}

void loop() {
  secuenciaUnoAUno();
  
  delay(1000); 

  
  secuenciaBarrido();
  delay(1000); 

 
  secuenciaParesImparesRandom();
  delay(1000);
}

void secuenciaUnoAUno() {
  for (int i = 0; i <= 12; i++) {
    tira.clear(); 
    tira.setPixelColor(i, colores[i]); 
    tira.show();
    delay(500);
  }
  tira.clear();
  tira.show(); 
}


void secuenciaBarrido() {
  uint32_t colorBarrido = tira.Color(255, 255, 255);

  
  for (int i = 0; i < NUM_LEDS; i++) {
    tira.clear();
    tira.setPixelColor(i, colorBarrido);
    tira.show();
    delay(100); 
  }

 
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    tira.clear();
    tira.setPixelColor(i, colorBarrido);
    tira.show();
    delay(100);
  }
  tira.clear();
  tira.show();
}

void secuenciaParesImparesRandom() {
  
  uint32_t colorPar = tira.Color(random(0, 256), random(0, 256), random(0, 256));
  uint32_t colorImpar = tira.Color(random(0, 256), random(0, 256), random(0, 256));


  tira.clear();
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i % 2 == 0) { 
      tira.setPixelColor(i, colorPar);
    }
  }
  tira.show();
  delay(500);
  
  tira.clear(); 
  tira.show();
  delay(100); 
 
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i % 2 != 0) { 
      tira.setPixelColor(i, colorImpar);
    }
  }
  tira.show();
  delay(500);

  tira.clear(); 
  tira.show();
}


