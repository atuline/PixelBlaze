/* marching rainbow

   By: PixelBlaze

   Converted by: Andrew Tuline

   Date: June, 2018

   This code was adapted from a shared Pixelblaze pattern. For more information
   about creating patterns with Pixelblaze and the shared pattern library, see:

   PixelBlaze as found at https://electromage.com/

   PixelBlaze expressions: https://github.com/simap/pixelblaze/blob/master/README.expressions.md

   Getting started guide: https://www.bhencke.com/pixelblazegettingstarted

   Patterns: https://electromage.com/patterns


   Original code:

  export function beforeRender(delta) {
  t1 = time(.1)
  t2 = time(.05)
  }

  export function render(index) {
  w1 = wave(t1 + index/pixelCount)
  w2 = wave(t2-index/pixelCount*10+.2)
  v = w1 - w2
  h = wave(wave(wave(t1 + index/pixelCount)) - index/pixelCount)
  hsv(h,1,v)
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

  marching_rainbow();
  FastLED.show();

} // loop()


void marching_rainbow() {

  t1 = time(.1);
  t2 = time(.05);

  for (int i = 0; i < NUM_LEDS; i++) {

    w1 = wave(t1 + (float)i / NUM_LEDS);
    w2 = wave(t2 - (float)i / NUM_LEDS * 10 + .2);
    v = w1 - w2;
    if (v < 0) v = 0;                             // Apparently, PB doesn't display negative values.
    h = wave(wave(wave(t1 + (float)i / NUM_LEDS)) - (float)i / NUM_LEDS);
    leds[i] = CHSV(h * 255, 255, v * 255);
  }

} // marching_rainbow()
