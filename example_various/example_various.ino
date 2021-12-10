/* Examples from PixelBlaze

   By: Andrew Tuline

   Date: Dec. 2021

   This code was adapted from a shared Pixelblaze pattern. For more information
   about creating patterns with Pixelblaze and the shared pattern library, see:

   PixelBlaze as found at https://electromage.com/

   PixelBlaze expressions: https://github.com/simap/pixelblaze/blob/master/README.expressions.md

   Getting started guide: https://www.bhencke.com/pixelblazegettingstarted

   Patterns: https://electromage.com/patterns   


   Original code:
   
   See the appropriate .h file for the original code.

*/


#include <FastLED.h>
#include <PixelBlaze.h>               // Locate this file either in the same directory or in Documents\Arduino\libraries\PixelBlaze

#define LED_DT 12
#define NUM_LEDS 30
struct CRGB leds[NUM_LEDS];

#include "color_hues.h"          // Functions are ch_0() up to 12
#include "modes_waveforms.h"     // Functions are mw_0() up to 12
#include "time_animations.h"     // Functions are ta_0() up to 13


void setup() {
  Serial.begin(115200);
  LEDS.addLeds<WS2812, LED_DT, GRB>(leds, NUM_LEDS);
}

void loop() {
  render();
  FastLED.show();
}


void render() {


  for (int i = 0; i < NUM_LEDS; i++) {

    float h;                        // The return value from the function, ranges from 0 to 1.0.
    float val;                      // The value we send to the function.

    float t = time(.05);            // Used by the time and animations routines.
    float t2 = time(.03);


    val = 4. * i / NUM_LEDS;        // v = modes[mode](4 * index / pixelCount)

    // I'm not using the demoreel100 method to call routines, as they have arguments and add a lot more complexity.

    //    h = ch_0(val);         // modes[0] = (f) => f // as values progress, a rainbow is drawn
    //    h = ch_1(val);         // modes[1] = (f) => 0 // a hue of 0.0 or 1.0 is red
    //    h = ch_2(val);         // modes[2] = (f) => 1/3 // a hue around 1/3 is green
    //    h = ch_3(val);         // modes[3] = (f) => 2/3 // 2/3 hue is blue
    //    h = ch_4(val);         // modes[4] = (f) => 1 // this wraps back around to red
    //    h = ch_5(val);         // modes[5] = (f) => f * .2 % .2 // using modulus will wrap early and with a sharp edge
    //    h = ch_6(val);         // modes[6] = (f) => triangle(f) *.2 // using triangle will keep the transitions smooth
    //    h = ch_7(val);         // modes[7] = (f) => wave(f) * .2 // wave also works, but is non-linear
    //    h = ch_8(val, .5);     // modes[8] = (f) => square(f, .5) * .5 + .33 // square can make stripes
    //    h = ch_9(val);         // modes[9] = (f) => wave(f) * triangle(f*4) * .2 // color textures by combining waveforms
    //    h = ch_10(val);        // modes[10] = (f) => wave(f)*.5 % .2 - triangle(f) *.2 + .66 // more textures
    //    h = ch_11(val);        // modes[11] = (f) => (f + f % .2) * .5 // mod error overlay
    //    h = ch_12(val);        // modes[12] = (f) => abs(f * .25 - .5)*2 // centered

    //    h = mw_0(val);         // modes[0] = (f) => f % 1 //this will just cause any numbers above 1.0 to wrap around
    //    h = mw_1(val);         // modes[1] = (f) => triangle(f) // triangle has a linear slope
    //    h = mw_2(val);         // modes[2] = (f) => wave(f) // wave uses the sin to create rounded slopes
    //    h = mw_3(val);         // modes[3] = (f) => square(f, .5) // a square wave is just on or off and has no transition
    //    h = mw_4(val);         // modes[4] = (f) => triangle(triangle(f)) // combining wave functions can create interesting effects
    //    h = mw_5(val);         // modes[5] = (f) => wave(triangle(f))
    //    h = mw_6(val);         // modes[6] = (f) => triangle(wave(f))
    //    h = mw_7(val);         // modes[7] = (f) => wave(wave(f))
    //    h = mw_8(val, .7);     // modes[8] = (f) => square(wave(triangle(f)), .7) // here we've made a dash-dot-dash pattern
    //    h = mw_9(val);         // modes[9] = (f) => wave(f) * triangle(f*1.3) // by multiplying waveforms, we get a darken effect
    //    h = mw_10(val);        // modes[10] = (f) => (wave(f*1) + triangle(f*3.3))/2 // blend waveforms by averaging them
    //    h = mw_11(val);        // modes[11] = (f) => triangle(f*2) - wave(f*1.5) // subtraction can create interesting interference patterns
    //    h = mw_12(val);        // modes[12] = (f) => abs(triangle(f) - wave(f*2)) // subtraction with absolute fue gives a distance

    //    h = ta_0(val, t);         // modes[0] = (f, t) => (f + t) % 1 // moving left
    //    h = ta_1(val, t);         // modes[1] = (f, t) => (1 + f - t) % 1 // moving right
    //    h = ta_2(val, t);         // modes[2] = (f, t) => (f + triangle(t)) % 1 // bounce back and forth
    //    h = ta_3(val, t);         // modes[3] = (f, t) => (f + wave(t)) % 1 // smooth back and forth
    //    h = ta_4(val, t);         // modes[4] = (f, t) => square(f + t, .5) // a chaser
    //    h = ta_5(val, t);         // modes[5] = (f, t) => (f + triangle(triangle(t) * t)) % 1 // combining wave functions can create interesting effects
    //    h = ta_6(val, t);         // modes[6] = (f, t) => (f + wave(wave(t))) % 1 // warbly movemovent
    //    h = ta_7(val, t);         // modes[7] = (f, t) => square(triangle(wave(t)) + f, .5) // bouncing
    //    h = ta_8(val, t);         // modes[8] = (f, t) => wave(f + t) * wave(f + t2) // times with different intervals create interesting waveform interactions
    //    h = ta_9(val, t);         // modes[9] = (f, t) => wave(wave(f + t) + wave(f - t2) + f - t) //wave textures
    //    h = ta_10(val, t);        // modes[10] = (f, t) => wave(f + wave(wave(t) + f / 4)) // stretchy effect
    //    h = ta_11(val, t);        // modes[11] = (f, t) => wave((f - 2) * (1 + wave(t))) * wave(wave(t2) + f) // zoomed and blended
    //    h = ta_12(val, t);        // modes[12] = (f, t) => 2 * triangle(f + wave(t)) - wave(f * .75 + wave(t2)) // kinetic
    //    h = ta_13(val, t);        // modes[13] = (f, t) => abs(triangle(f - triangle(t2)) - wave(f * 2 + triangle(t))) // glitch conveyer belt

    //  leds[i] = CHSV(h * 255, 255, 255);      // Used for color_hues.h routines
    //  leds[i] = CHSV(0,0,h*255);              // Used for modes_waveforms.h routines
    //  leds[i] = CHSV(0,0,h*255);              // Used for time_animations.h routines

  }
}
