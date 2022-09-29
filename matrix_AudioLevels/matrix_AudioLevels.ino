/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


const int sampleWindow = 10; // Sample window width - lower number quicker
unsigned int sample;
unsigned int gr[] = {0,0,0,0,0,0,0,0};

int PIN = 6;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

void setup() 
{
  //Serial.begin(115200);
  matrix.begin();
  matrix.setBrightness(255);
  matrix.setRotation(1);
}


void loop() {
   //get audio into array
   shiftArray();
   unsigned int audioLevel = analyseAudio();
   gr[0] = audioLevel;

   //visualise audio levels
   matrix.clear();
   for(int i = 0; i < 8; i ++){
      int x = map(gr[i], 0, 500, 0, 8);
      if(x > 0){
         matrix.drawLine(i, 8, i, 8-x, Spectrum(x*4));
      }
   }
   matrix.show();
}



//////////////////////
//BELOW ARE EXTRA FUNCTIONS YOU CAN IGNORE
/////////////

void shiftArray(){
   gr[7] = gr[6];
   gr[6] = gr[5];
   gr[5] = gr[4];
   gr[4] = gr[3];
   gr[3] = gr[2];
   gr[2] = gr[1];
   gr[1] = gr[0];
  
}


unsigned int analyseAudio(){
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
  return  signalMax - signalMin;  // max - min = peak-peak amplitude
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Spectrum(byte WheelPos) {
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
