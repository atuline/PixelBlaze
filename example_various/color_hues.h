/* Examples: color hues in floating point ---------------------------------

  This stays as close to the PixelBlaze code as I can make it.


  modes[0] = (f) => f // as values progress, a rainbow is drawn
  modes[1] = (f) => 0 // a hue of 0.0 or 1.0 is red
  modes[2] = (f) => 1/3 // a hue around 1/3 is green
  modes[3] = (f) => 2/3 // 2/3 hue is blue
  modes[4] = (f) => 1 // this wraps back around to red
  modes[5] = (f) => f * .2 % .2 // using modulus will wrap early and with a sharp edge
  modes[6] = (f) => triangle(f) *.2 // using triangle will keep the transitions smooth
  modes[7] = (f) => wave(f) * .2 // wave also works, but is non-linear
  modes[8] = (f) => square(f, .5) * .5 + .33 // square can make stripes
  modes[9] = (f) => wave(f) * triangle(f*4) * .2 // color textures by combining waveforms
  modes[10] = (f) => wave(f)*.5 % .2 - triangle(f) *.2 + .66 // more textures
  modes[11] = (f) => (f + f % .2) * .5 // mod error overlay
  modes[12] = (f) => abs(f* .25 - .5)*2 // centered

  render(index) {
    h = modes[mode](4 * index / pixelCount)
    hsv(h, 1, 1)
  }


*/


float ch_0(float f) {           // (f) => f
  float v = f ;
  return (v);
}


float ch_1(float f) {           // (f) => 0
  float v = 0;
  return (v);
}


float ch_2(float f) {           // (f) => 1/3
  float v = 1. / 3.;
  return (v);
}


float ch_3(float f) {           // (f) => 2/3
  float v = 2. / 3.;
  return (v);
}


float ch_4(float f) {           // (f) => 1
  float v = 1.;
  return (v);
}


float ch_5(float f) {           // (f) => f * .2 % .2
  float v = fmod(f * .2, .2);
  return (v);
}


float ch_6(float f) {           // (f) => triangle(f) *.2
  float v = triangle(f) * .2;
  return (v);
}


float ch_7(float f) {           // (f) => wave(f) * .2
  float v = wave(f) * .2;
  return (v);
}


float ch_8(float f , float t) {   // square(f, .5) * .5 + .33
  float v = square(f, t) * .5 + .33;
  return (v);
}


float ch_9(float f) {           // wave(f) * triangle(f*4) * .2
  float v = wave(f) * triangle(f * 4) * .2;
  return (v);
}


float ch_10(float f) {          // (f) => wave(f)*.5 % .2 - triangle(f) *.2 + .66
  float v = fmod(wave(f) * .5, .2) - triangle(f) * .2 + .66;
  return (v);
}


float ch_11(float f) {          // (f) => (f + f % .2) * .5
  float v = (f * fmod(f, .2)) * .5;
  return (v);
}


float ch_12(float f) {          // (f) => abs(f* .25 - .5)*2
  float v = abs(f * .25 - 5) * 2;
  return (v);
}
