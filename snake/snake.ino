/* snake

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

  distance = 10

  export function beforeRender(delta) {
    t1 = time(.1)
  }

  export function render(index) {
    h = index/pixelCount
    s = 1
    v = 1

    head = t1 * pixelCount
    offset = (head - index + pixelCount) % pixelCount

    hsv(h, s, clamp(1 - offset / distance, 0, 1))
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
  snake();
  FastLED.show();
} // loop()



void snake() {

  float distance = 10;
  t1 = time(.1);

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    h = index / pixelCount;
    s = 1;
    v = 1;

    float head = t1 * pixelCount;
    float offset = fmod((head - index + pixelCount), pixelCount);

    leds[i] = CHSV(h * 255, s * 255, clamp(1 - offset / distance, 0, 1) * 255);
  }
}
