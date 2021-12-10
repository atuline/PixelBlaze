// Place pixelblaze.h in a directory called pixelblaze and put it in your documents\arduino\libraries folder.

// Reference: https://forum.electromage.com/t/portability-to-fastled-arduino/310

#define PI   3.141592653
#define PI2  6.283125313


float time(float inVal) {                          // A sawtooth waveform between 0.0 and 1.0 that loops about every 65.536*interval seconds. e.g. use .015 for an approximately 1 second.
  float myVal = millis();
  myVal = myVal / 1000 * .015259 / inVal;          // PixelBlaze uses 1000/65535 = .015259
  myVal = fmod(myVal, 1.0);
  return myVal;
}


float triangle(float t) {                          // Converts a sawtooth waveform v between 0.0 and 1.0 to a triangle waveform between 0.0 to 1.0. v "wraps" between 0.0 and 1.0.
  return 1.0 - fabs(fmod(2 * t, 2.0) - 1.0);
}


float wave(float v) {                              // Converts a sawtooth waveform v between 0.0 and 1.0 to a sinusoidal waveform between 0.0 to 1.0. Same as (1+sin(v*PI2))/2 but faster. v "wraps" between 0.0 and 1.0.
  return (1 + sin(v * 2 * PI)) / 2;
}


float square(float v, float t) {                   // Converts a sawtooth waveform v to a square wave using the provided duty cycle where duty is a number between 0.0 and 1.0. v "wraps" between 0.0 and 1.0.
  float sinValue = wave(v);
  return sinValue >= t ? 1 : 0;
}



float frand(float val) {                           // A floating point random number generator.
float retVal = (float)rand() / 32768;
return retVal;
}


float clamp(float d, float min, float max) {       // We also need a clamp function.
  const float t = d < min ? min : d;
  return t > max ? max : t;
}


// Variables used within various routines that need to be initialized. Yea, this is overkill,
// however the ultimate goal is to have the .ino file be as clean as possible.

float index;
float pixelCount;

float t1;
float t2;
float t3;
float t4;
float t5;
float t6;

float a;
float b;
float c;
float f;
float h;
float hl;
float m;
float s;
float s1;
float s2;
float v;
float v2;
float w1;
float w2;
float w3;
float il;
