#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

uint16_t col;


int PIN = 6;

int frame1[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setBrightness(128);
  matrix.setRotation(1);
  col = matrix.Color(255, 0, 0);
}



void loop() {
  showFrame(frame1, 50);
}




void showFrame(int frame[], int myDelay){
  matrix.clear();
  for(int i = 0; i < 64; i++){
    int x = i % 8;
    int y = i / 8;
    if(frame[i] == 1){
       matrix.drawPixel(x, y, col);
    } 
  }
  matrix.show();
  delay(myDelay);
}
