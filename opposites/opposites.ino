/* opposites

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
    t2 = time(.2)
  }

  export function render(index) {
    il = index/pixelCount
    w1 = wave(t1 + il)
    w2 = wave(t2 - il)
    w3 = wave((il + w1 + w2 )%1)
    h = w3 %.3
    h = (h > .15 ? h : h +.5) + t1
    s = 1
    v = ((w1+.1) * (w2+.1) * (w3+.1))
    v = v*v
    hsv(h,s,v)
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
  opposites();
  FastLED.show();
} // loop()



void opposites() {

  t1 = time(.1);
  t2 = time(.2);

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    il = index / pixelCount;
    w1 = wave(t1 + il);
    w2 = wave(t2 - il);
    w3 = wave(fmod((il + w1 + w2 ), 1));
    h = fmod(w3, .3);
    h = (h > .15 ? h : h + .5) + t1;
    s = 1;
    v = ((w1 + .1) * (w2 + .1) * (w3 + .1));
    v = v * v;

    leds[i] = CHSV(h * 255, s * 255, v * 255);
  }
}
