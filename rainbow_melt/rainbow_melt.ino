/* rainbow melt

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

  hl = pixelCount/2
  export function beforeRender(delta) {
    t1 =  time(.1)
    t2 = time(0.13)
  }

  export function render(index) {
    c1 = 1-abs(index - hl)/hl
    c2 = wave(c1)
    c3 = wave(c2 + t1)
    v = wave(c3 + t1)
    v = v*v
    hsv(c1 + t2,1,v)
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
  rainbow_melt();
  FastLED.show();
} // loop()



void rainbow_melt() {

  float hl = pixelCount / 2;
  t1 =  time(.1);
  t2 = time(0.13);

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    float c1 = 1 - abs(index - hl) / hl;
    float c2 = wave(c1);
    float c3 = wave(c2 + t1);
    v = wave(c3 + t1);
    v = v * v;
    leds[i] = CHSV((c1 + t2) * 255, 255, v * 255);
  }
}
