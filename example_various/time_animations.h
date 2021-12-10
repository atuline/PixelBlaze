
/* Examples: time and animation -------------------------

  Note that this is incomplete, but it should be relatively trivial to do so.



  modes[0] = (f, t) => (f + t) % 1 // moving left
  modes[1] = (f, t) => (1 + f - t) % 1 // moving right
  modes[2] = (f, t) => (f + triangle(t)) % 1 // bounce back and forth
  modes[3] = (f, t) => (f + wave(t)) % 1 // smooth back and forth,
  modes[4] = (f, t) => square(f + t, .5) // a chaser
  modes[5] = (f, t) => (f + triangle(triangle(t) * t)) % 1 // combining wave functions can create interesting effects
  modes[6] = (f, t) => (f + wave(wave(t))) % 1 // warbly movemovent
  modes[7] = (f, t) => square(triangle(wave(t)) + f, .5) // bouncing
  modes[8] = (f, t) => wave(f + t) * wave(f + t2) // times with different intervals create interesting waveform interactions
  modes[9] = (f, t) => wave(wave(f + t) + wave(f - t2) + f - t) //wave textures
  modes[10] = (f, t) => wave(f + wave(wave(t) + f / 4)) // stretchy efect
  modes[11] = (f, t) => wave((f - 2) * (1 + wave(t))) * wave(wave(t2) + f) // zoomed and blended
  modes[12] = (f, t) => 2 * triangle(f + wave(t)) - wave(f * .75 + wave(t2)) // kinetic
  modes[13] = (f, t) => abs(triangle(f - triangle(t2)) - wave(f * 2 + triangle(t))) // glitch conveyer belt


  export function render(index) {
  v = modes[mode](4 * index / pixelCount, t)
  hsv(0, 0, v)
  }


*/

float ta_0(float f, float t) {               // (f, t) => (f + t) % 1
  float v = fmod((f+t), 1);
  return (v);

}



float ta_1(float f, float t) {               // (f, t) => (1 + f - t) % 1
  float v = fmod((1+t-t), 1);
  return (v);
}


float ta_2(float f, float t) {               // (f, t) => (f + triangle(t)) % 1
  float v = fmod((f + triangle(t)), 1);
  return (v);
}


float ta_3(float f, float t) {               // (f, t) => (f + wave(t)) % 1
  float v = fmod((f + wave(t)), 1);
  return (v);
}


float ta_4(float f, float t) {  // (f, t) => square(f + t, .5)
  float v = square((f+t), .5);
  return (v);
}


float ta_5(float f, float t) {               // (f, t) => (f + triangle(triangle(t) * t)) % 1
  float v = fmod((f + triangle(triangle(t) * t)), 1);
  return (v);
}


float ta_6(float f, float t) {               // (f, t) => (f + wave(wave(t))) % 1
  float v = fmod((f + wave(t)), 1);
  return (v);
}


float ta_7(float f, float t) {               // (f, t) => square(triangle(wave(t)) + f, .5)
  float v = square(triangle(wave(t)) + f, t);
  return (v);
}


float ta_8(float f, float t) {               // (f, t) => wave(f + t) * wave(f + t2)
  float v = f;
  return (v);
}


float ta_9(float f, float t) {               // (f, t) => wave(wave(f + t) + wave(f - t2) + f - t)
  float v = f;
  return (v);
}


float ta_10(float f, float t) {               // (f, t) => wave(f + wave(wave(t) + f / 4))
  float v = f;
  return (v);
}


float ta_11(float f, float t) {               // (f, t) => wave(f + wave(wave(t) + f / 4))
  float v = f;
  return (v);
}


float ta_12(float f, float t) {               // (f, t) => 2 * triangle(f + wave(t)) - wave(f * .75 + wave(t2))
  float v = f;
  return (v);
}


float ta_13(float f, float t) {               // (f, t) => abs(triangle(f - triangle(t2)) - wave(f * 2 + triangle(t)))
  float v = f;
  return (v);
}
