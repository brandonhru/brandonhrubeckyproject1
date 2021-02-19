  
#include <Adafruit_NeoPixel.h>
#define PIN       2 
#define NUM_LEDS 32
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type:
//   NEO_GRB  Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB  Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB);
 
uint32_t color = strip.Color(43, 137, 219); // Change RGB color value here
 
// These are the pixels in order of animation-- 32 pixels in total:
int sine[] = {
   5,  4,  3,  2,  1, 0, 15, 14, 13, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28,
  36, 35, 34, 33, 32, 47, 46, 45, 44, 52, 53, 54, 55, 56, 57, 58, 59};
 
void setup() {
  strip.begin();
  strip.show();            // Initialize all pixels to 'off'
  strip.setBrightness(180); // 40/255 brightness (about 15%)
}
 
void loop() {
  for(int i=0; i<32; i++) {
    strip.setPixelColor(sine[i], color);             // Draw 'head' pixel
    strip.setPixelColor(sine[(i + 32 - 8) % 32], 0); // Erase 'tail'
    strip.show();
    delay(20);
  }
}
  
