#include <FastLED.h>

//cuántos pixeles y en qué pin
#define NUM_LEDS 16
#define DATA_PIN 6

//comportamiento de la animación
//offset de color entre pixeles, delay entre iteraciones
#define OFFSET 20
#define DELAY 20

// FastLED trata a todos los LEDs como un arreglo
CRGB leds[NUM_LEDS];
int hue = 0;

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
  for (int i=0; i< NUM_LEDS; i++){
    // a cada LED, asignarle el color base actual + tantos offsets como le toquen
    leds[i] = CHSV(hue + (OFFSET*i), 220, 200);
    //CHSV(hue, saturation, brightness), los tres máx 255
  }
  FastLED.show();
  // mandar el arreglo a los LEDs
  hue++;
  //incrementar el color base
  if (hue == 255){hue = 0;}
  delay(DELAY);
}
