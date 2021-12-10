
/* Examples: modes and waveforms ------------------------

  This is the 8/16  it conversion of these routines for FastLED.

  modes[0] = (f) => f % 1 //this will just cause any numbers above 1.0 to wrap around
  modes[1] = (f) => triangle(f) // triangle has a linear slope
  modes[2] = (f) => wave(f) // wave uses the sin to create rounded slopes
  modes[3] = (f) => square(f, .5) // a square wave is just on or off and has no transition
  modes[4] = (f) => triangle(triangle(f)) // combining wave functions can create interesting effects
  modes[5] = (f) => wave(triangle(f))
  modes[6] = (f) => triangle(wave(f))
  modes[7] = (f) => wave(wave(f))
  modes[8] = (f) => square(wave(triangle(f)), .7) // here we've made a dash-dot-dash pattern
  modes[9] = (f) => wave(f) * triangle(f*1.3) // by multiplying waveforms, we get a darken effect
  modes[10] = (f) => (wave(f*1) + triangle(f*3.3))/2 // blend waveforms by averaging them
  modes[11] = (f) => triangle(f*2) - wave(f*1.5) // subtraction can create interesting interference patterns
  modes[12] = (f) => abs(triangle(f) - wave(f*2)) // subtraction with absolute fue gives a distance

  export function render(index) {
  v = modes[mode](4 * index / pixelCount)
  hsv(0, 0, v)
  }
*/


float mw_0(float f) {               // (f) => f % 1
  float v = fmod(f, 1.0);
  return (v);
}


float mw_1(float f) {               // (f) => triangle(f)
  float v = triangle(f);
  return (v);
}


float mw_2(float f) {               // wave(f)
  float v = wave(f);
  return (v);
}


float mw_3(float f, float t) {  // (f) => square(f, .5)
  float v = square(f, t);
  return (v);
}


float mw_4(float f) {               // (f) => triangle(triangle(f))
  float v = triangle(triangle(f));
  return (v);
}


float mw_5(float f) {               // wave(triangle(f))
  float v = wave(triangle(f));
  return (v);
}


float mw_6(float f) {               // triangle(wave(f))
  float v = triangle(wave(f));
  return (v);
}


float mw_7(float f, float t) {  // wave(wave(f))
  float v = wave(wave(f));
  return (v);
}


float mw_8(float f, float t) {               // square(wave(triangle(f)), .7)
  float v = square(wave(triangle(f)), t);
  return (v);
}


float mw_9(float f) {               // wave(f) * triangle(f*1.3)
  float v = wave(f) * triangle(f*1.3);
  return (v);
}


float mw_10(float f) {               // (f) => (wave(f*1) + triangle(f*3.3))/2
  float v = (wave(f*1) + triangle(f*3.3))/2;
  return (v);
}


float mw_11(float f) {               // (f) => triangle(f*2) - wave(f*1.5)
  float v = triangle(f*2) - wave(f*1.5);
  return (v);
}


float mw_12(float f) {               // (f) => abs(triangle(f) - wave(f*2))
  float v = abs(triangle(f) - wave(f*2));
  return (v);
}
