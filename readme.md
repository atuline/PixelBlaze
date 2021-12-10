
## PixelBlaze to FastLED conversions

This project was created to provide conversion of very simple PixelBlaze routines to be used by FastLED. It is not
meant to be an ongoing/supported effort.

It can also be used to help port them over to WLED (not planned), and the (currently in development) ARTI interpreter
for our sound reactive fork of WLED.


PixelBlaze functionality provided here includes:

* triangle()
* time()
* wave()
* square()
* clamp()

I've also added a floating point random number generator called:

* frand()


Other translation included:

* Conversion of PixelBlaze floating point '%' operator to the C style fmod() function.


## Not included

* Arrays.
* 2D, 3D.
* Sensor input.
* Probably a lot more.


## Background

    PixelBlaze runs a non-typed Javascript style interpreted language where values are 16.16 fixed point.

    FastLED, on the other hand, typically works with typed 8/16 bit or floating point values.

    Both PixelBlaze and FastLED have their own function calls, such as Pixelblaze's:

    time(), triangle(), wave() and square() routines, each of which return values betwewen 0 and 1.0.

    In order to translate from PixelBlaze to FastLED, we'll resort to floating point math and convert from Javascript
    mathematical operations to C style ones.

    For more information on PixelBlaze, see www.electromage.com.



## Changes

* Use the helper functions in pixelblaze.h.
* Use index instead of i.
* Use pixelCount instead of NUM_LEDS.
* Index and pixelCount may need to be made (float) for calculations.
* Convert % to fmod().
* Add semicolons at the end of each line.
* Sometimes you need to be careful when a number goes < 0.


## Instructions

Place a copy of PixelBlaze.h EITHER in each directory that includes a .ino file OR in Documents\Arduino\libraries\PixelBlaze.

These were tested on an Arduino Nano, and you will need to change configuration settings for your own environment in the .ino files.


Caveat: PixelBlaze.h is not a library, it's just a hack for testing.
