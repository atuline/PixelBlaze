/* fast pulse

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
    t1 = time(.1)
  }

  export function render(index) {
    v = triangle((2*wave(t1) + index/pixelCount) %1)
    v = v*v*v*v*v
    s = v < .9
    hsv(t1,s,v)
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
  fast_pulse();
  FastLED.show();
} // loop()



void fast_pulse() {

  t1 = time(.1);

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;
    v = triangle(fmod((2 * wave(t1) + index / pixelCount), 1));
    v = v * v * v * v * v;
    s = v < .9;
    leds[i] = CHSV(t1 * 255, s * 255, v * 255);
  }
}
