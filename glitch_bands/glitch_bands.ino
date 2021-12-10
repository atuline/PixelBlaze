/* glitch bands

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
    t1 = time(0.1)*PI2;
    t2 = time(.1);
    t3 = time(.5);
    t4 = time(0.2)*PI2;
    t5 = time(.05);
    t6 = time(.02);
  }

  export function render(index) {
    h = sin(t1)
    m = (.3 + triangle(t2) * .2)
    h = h + (((index - pixelCount / 2) / pixelCount * ( triangle(t3) * 10 + 4 * sin(t4)) % m))
    s1 = triangle((t5 + index / pixelCount * 5) % 1);
    s1 = s1 * s1
    s2 = triangle((t6 - (index - pixelCount) / pixelCount) % 1);
    s2 = s2 * s2 * s2 * s2
    s = 1 - triangle(s1 * s2)
    v = (s1 > s2) + .5
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
  glitch_bands();
  FastLED.show();
} // loop()



void glitch_bands() {

  t1 = time(0.1) * PI2;
  t2 = time(.1);
  t3 = time(.5);
  t4 = time(0.2) * PI2;
  t5 = time(.05);
  t6 = time(.02);

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    h = sin(t1);
    m = (.3 + triangle(t2) * .2);
    h = h + ((fmod((index - pixelCount / 2) / pixelCount * ( triangle(t3) * 10 + 4 * sin(t4)), m)));
    s1 = triangle(fmod((t5 + index / pixelCount * 5), 1));
    s1 = s1 * s1;
    s2 = triangle(fmod((t6 - (index - pixelCount) / pixelCount), 1));
    s2 = s2 * s2 * s2 * s2;
    s = 1 - triangle(s1 * s2);
    v = (s1 > s2) + .5;

    leds[i] = CHSV(h * 255, s * 255, v * 255);
  }
}
