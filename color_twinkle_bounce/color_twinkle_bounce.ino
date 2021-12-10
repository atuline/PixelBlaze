/* color twinkle bounce

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
    t1 = time(.05)*PI2
    t2 = time(.05)*PI2
  }

  export function render(index) {
    a = (1 + sin((index/2  +5* sin(t1)) ))/2
    b = (time(.1) + 1 + sin((index/2  +5* sin(t2)) ))
    v = (a*a*a*a)*.5
    hsv(b,1,v)
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
  color_twinkle_bounce();
  FastLED.show();
} // loop()



void color_twinkle_bounce() {

  t1 = time(.05) * PI2;
  t2 = time(.05) * PI2;

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    a = (1 + sin((index / 2  + 5 * sin(t1)) )) / 2;
    b = (time(.1) + 1 + sin((index / 2  + 5 * sin(t2)) ));
    v = (a * a * a * a) * .5;

    leds[i] = CHSV(b * 255, 255, v * 255);
  }
}
