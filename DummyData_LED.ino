// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// developed by Neel P. Savani (NASA GSFC / UMBC) and Abhishek Gorti (NASA intern / USNA)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      512
const double _val[8] = {3, 2, 4, 5, 2, 1, 2, 4};  // dummy data of space weather Kp Index
int _snake = 2;
int _time = 1;
const int _dz[6] = {2,4,6,8}
const int _dy[6] = {3,5,7]
int _ddz = 0;
int _ddy = 0;
int current = 0; 
int z_pos = 4;
int y_pos = 2;
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 1000 * 2; // delay for half a second

void setup() {
  Serial.begin(9600);  
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

int _pix(int x, int y, int z) {
  int _i = 0;
  if (z > 0) {
    if (z > 8) {
      z = 8;
    }
    _i += (z * 64);
  }
  if (x > 0) {
    if (x > 8) {
      x = 8;
    }
    _i += (x * 8);
  }
  if (z > 8) {
    z = 8;
  }
  _i += y;
  return _i;
}
uint32_t _colret(int val) {
  int r, g, b = 0;
  if (val < 2) {
    g = 100;
  } else if (val >= 2 && val < 3) {
    r = 100;
    g = 100;
    b = 0;
  } else if (val >= 3 && val < 5) {
    r = 255;
    g = 40;
    b = 0;
  } else if (val >= 5) {
    r = 255;
  }
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}
void loop() {
  for (int i = 0; i < 7; i++)
  {
    for (int h = 0; h < _val[i]; h++) {
      pixels.setPixelColor(_pix(i, h, 7), pixels.Color(_colret(_val[i]))); // Moderately bright green color.
    }
  }
  pixels.setPixelColor(_pix(7, 3, 3), pixels.Color(_colret(_val[7])));
  pixels.setPixelColor(_pix(7, 3, 4), pixels.Color(_colret(_val[7])));
  pixels.setPixelColor(_pix(7, 4, 3), pixels.Color(_colret(_val[7])));
  pixels.setPixelColor(_pix(7, 4, 4), pixels.Color(_colret(_val[7])));

   while(_time <60){
    
   }
      _time++;
       delay(250);
   }
  
  pixels.setPixelColor(_pix(7, y_pos, z_pos), pixels.Color(_colret(_val[7])));

  pixels.show();
  delay(250); // Delay for a period of time (in milliseconds).
}
