/* green ripple reflections

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

  PI10 = PI2*5
  PI6 = PI2*3

  export function beforeRender(delta) {
    t1 = time(.03)*PI2
    t2 = time(.05)*PI2
    t3 = time(.04)*PI2
  }

  export function render(index) {
    a = sin(index*PI10/pixelCount + t1)
    a = a*a
    b = sin(index*PI6/pixelCount - t2)
    c = triangle((index*3/pixelCount + 1 + sin(t3))/2 % 1)
    v = (a+b+c)/3
    v = v*v
    hsv(.3, a, v/2)
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
  green_ripple_reflections();
  FastLED.show();
} // loop()



void green_ripple_reflections() {

  float PI6 = PI2 * 3;
  float PI10 = PI2 * 5;

  t1 = time(.03) * PI2;
  t2 = time(.05) * PI2;
  t3 = time(.04) * PI2;

  for (int i = 0; i < NUM_LEDS; i++) {

    index = i;
    pixelCount = NUM_LEDS;

    a = sin(index * PI10 / pixelCount + t1);
    a = a * a;
    b = sin(index * PI6 / pixelCount - t2);
    c = triangle(fmod((index * 3 / pixelCount + 1 + sin(t3)) / 2, 1));
    v = (a + b + c) / 3;
    v = v * v;

    leds[i] = CHSV(77, a * 255, v * 128);
  }
}
