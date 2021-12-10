/* block reflections

   By: PixelBlaze

   Converted by: Andrew Tuline

   Date: Dec, 2021

   This code was adapted from a shared Pixelblaze pattern. For more information
   about creating patterns with Pixelblaze and the shared pattern library, see:

   PixelBlaze as found at https://electromage.com/

   PixelBlaze expressions: https://www.bhencke.com/pixelblaze-expression

   Getting started guide: https://www.bhencke.com/pixelblazegettingstarted

   Patterns: https://electromage.com/patterns


   Original code:

      export function beforeRender(delta) {
        t2 = time(0.1) * PI2
        t1 = time(.1)
        t3 = time(.5)
        t4 = time(0.2) * PI2
      }

      export function render(index) {
        h = sin(t2)
        m = (.3 + triangle(t1) * .2)
        h = h + (((index - pixelCount / 2) / pixelCount * ( triangle(t3) * 10 + 4 * sin(t4)) % m))
        s = 1;
        v = ((abs(h) + abs(m) + t1) % 1);
        v = v * v
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
  block_reflections();
  FastLED.show();
} // loop()



void block_reflections() {

  t2 = time(0.1) * PI2;
  t1 = time(.1);
  t3 = time(.5);
  t4 = time(0.2) * PI2;

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    h = sin(t2);
    m = (.3 + triangle(t1) * .2);
    h = h + (fmod((index - pixelCount / 2) / pixelCount * ( triangle(t3) * 10 + 4 * sin(t4)), m));
    s = 1;
    v = (fmod((abs(h) + abs(m) + t1), 1));
    v = v * v;
    leds[i] = CHSV(h * 255, s * 255, v * 255);
  }
}
