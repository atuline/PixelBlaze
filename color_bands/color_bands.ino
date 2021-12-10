/* color bands

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
     t1 = time(.5)*2
     t2 = time(.25)
     t3 = time(.15)
   }

   export function render(index) {
     h = index/(pixelCount/2)
     s = wave(-index/3 + t2)
     s = 1-s*s*s*s
     v = wave(index/2 + t3) * wave(index/5 - t3) + wave(index/7 + t3)
     v = v*v*v*v
     hsv(h, s, v)
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
  color_bands();
  FastLED.show();
} // loop()



void color_bands() {

  t1 = time(.5) * 2;
  t2 = time(.25);
  t3 = time(.15);

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    h = index / (pixelCount / 2);

    s = wave(-index / 3 + t2);
    s = 1 - s * s * s * s;
    v = wave(index / 2 + t3) * wave(index / 5 - t3) + wave(index / 7 + t3);
    if (v > 1.0) v = 1.0;                                                               // Don't know why I need this.
    v = v * v * v * v;
    leds[i] = CHSV(h * 255, s * 255, v * 255);
  }

} // color_bands()
