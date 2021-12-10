/* halloween color twinkles

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
    t1 = time(1.50) * PI2
    t2 = time(.35) * PI2 // 3.33 times faster than t1
  }

  export function render(index) {

    h = sin(index / 3 + PI2 * sin(index / 2 + t1))
    v = wave(index / 3 / PI2 + sin(index / 2 + t2))
    v = v * v * v * v // Gamma correction
    v = v > .1 ? v : 0
    if (h > 0)
      h = triangle(h) * .1 + .7
    else
      h = triangle(h) * .05 + .02
    hsv(h, 1, v)
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
  halloween_color_twinkles();
  FastLED.show();
} // loop()



void halloween_color_twinkles() {

  t1 = time(1.50) * PI2;
  t2 = time(.35) * PI2;

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    h = sin(index / 3 + PI2 * sin(index / 2 + t1));
    v = wave(index / 3 / PI2 + sin(index / 2 + t2));
    v = v * v * v * v;
    v = v > .1 ? v : 0;
    if (h > 0) {
      h = triangle(h) * .1 + .7;
    } else {
      h = triangle(h) * .05 + .02;
    }

    leds[i] = CHSV(h * 255, 255, v * 255);
  }
}
