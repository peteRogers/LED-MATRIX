#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


int PIN = 6;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  matrix.begin();
  matrix.setBrightness(255);
  matrix.setRotation(1);
}



void loop() {
   if (Serial.available() > 0){
        int x = Serial.readStringUntil(';').toInt();
        int y = Serial.readStringUntil(';').toInt();
        int r = Serial.readStringUntil(';').toInt();
        int g = Serial.readStringUntil(';').toInt();
        int b = Serial.readStringUntil(';').toInt();
        matrix.drawPixel(x,y,matrix.Color(r,g,b));
        matrix.show();
    }
  //delay(20);
   //matrix.show();
}


//////////////////////
//BELOW ARE EXTRA FUNCTIONS YOU CAN IGNORE
/////////////



// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
