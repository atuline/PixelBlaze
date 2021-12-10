/* rainbow fonts 2

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
    t1 =  time(.1)
    scale = pixelCount/2
    offset = sin(time(.2)* PI2) * pixelCount/10
    offsetL = offset/pixelCount
  }

  export function render(index) {
    c = 1-abs((index + offset) - scale)/scale
    c = wave(c)
    c = wave(c + t1 + offsetL)
    hsv(c,1,.2)
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
  rainbow_fonts_2();
  FastLED.show();
} // loop()



void rainbow_fonts_2() {


  t1 =  time(.1);
  float scale = pixelCount / 2;
  float offset = sin(time(.2) * PI2) * pixelCount / 10;
  float offsetL = offset / pixelCount;

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    c = 1 - abs((index + offset) - scale) / scale;
    c = wave(c);
    c = wave(c + t1 + offsetL);

    leds[i] = CHSV(c * 255, 255, 128);
  }
}
