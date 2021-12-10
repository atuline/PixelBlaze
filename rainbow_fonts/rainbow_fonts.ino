/* rainbow fonts

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
    t1 = time(.1)
  }

  export function render(index) {
    c = 1-abs(index - hl)/hl
    c = wave(c)
    c = wave(c + t1)
    hsv(c,1,.3)
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
  rainbow_fonts();
  FastLED.show();
} // loop()



void rainbow_fonts() {

  hl = pixelCount / 2;
  t1 = time(.1);

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    c = 1 - abs(index - hl) / hl;
    c = wave(c);
    c = wave(c + t1);

    leds[i] = CHSV(c * 255, 255, 77);
  }
}
