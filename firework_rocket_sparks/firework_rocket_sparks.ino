/* firework rocket sparks

   By: PixelBlaze

   Converted by: Andrew Tuline

   Date: Dec, 2021

   This code was adapted from a shared Pixelblaze pattern. For more information
   about creating patterns with Pixelblaze and the shared pattern library, see:

   PixelBlaze as found at https://electromage.com/

   PixelBlaze expressions: https://github.com/simap/pixelblaze/blob/master/README.expressions.md

   Getting started guide: https://www.bhencke.com/pixelblazegettingstarted

   Patterns: https://electromage.com/patterns


   Original code:

  export function beforeRender(delta) {
    t1 = time(.05)
    t2 = time(0.0001) * 0.2
  }

  export function render(index) {
    v = wave(t1 + index/pixelCount)
    v2 = wave(t1 + (index+10)/pixelCount)
    s = (v2 < 0.9995)
    v = (v > .95 && random(1) > .95) * v
    h = random(1)
    h = (s ? h : (index/20)%.2)
    hsv(h, 1-s, (1-s) + v )
  }

*/


#include <FastLED.h>
#include <PixelBlaze.h>               // Locate this file either in the same directory or in Documents\Arduino\libraries\PixelBlaze

#define LED_DT 12
#define COLOR_ORDER GRB
#define LED_TYPE WS2812
#define NUM_LEDS 60

struct CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);
} // setup()



void loop () {
  firework_rocket_sparks();
  FastLED.show();
} // loop()



void firework_rocket_sparks() {

  t1 = time(.05);
  t2 = time(0.0001) * 0.2;

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    v = wave(t1 + index / pixelCount);
    v2 = wave(t1 + (index + 10) / pixelCount);
    s = (v2 < 0.9995);
    v = (v > .95 && frand(1) > .95) * v;
    h = frand(1);
    h = (s ? h : fmod((index / 20), .2));

    leds[i] = CHSV(h * 255, (1 - s) * 255, ((1 - s) + v) * 255);

  }
}
