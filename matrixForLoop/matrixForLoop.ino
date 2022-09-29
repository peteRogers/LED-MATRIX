#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


#define PIN 6
//int x  = 0;
int bri = 0;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setBrightness(255);
  matrix.setRotation(2);
}



void loop() {
  matrix.clear();
   for (int x = 0; x < 8; x ++){
    for (int y = 0; y < 8; y ++){
        matrix.drawPixel(x, y, matrix.Color(random(0, 255),random(0, 255),random(0, 255)));
    } 
  }
  matrix.show();
  delay(20);
}
