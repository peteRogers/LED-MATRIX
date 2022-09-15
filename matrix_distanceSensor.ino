#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


#include "Wire.h"
#include "DFRobot_VL53L0X.h"
#include <Smoothed.h> 

DFRobot_VL53L0X distanceSensor;

Smoothed <int> smoothed; 

int PIN = 6;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  //set up led matrix
  matrix.begin();
  matrix.setBrightness(255);
  matrix.setRotation(1);
  //distance sensor set up
  Wire.begin();
  distanceSensor.begin(0x50);
  distanceSensor.setMode(distanceSensor.eContinuous,distanceSensor.eHigh);
  distanceSensor.start();
  //ssetup smoothing results
  smoothed.begin(SMOOTHED_EXPONENTIAL, 10);
}



void loop() {
  matrix.clear();
  smoothed.add(constrain(map(distanceSensor.getDistance(), 1500, 0, 0, 255), 0, 255));
  matrix.fillRect(0,0,8, 8, matrix.Color(smoothed.get(),0,0)); //red pixel top left
  matrix.show();
  delay(1);
}
