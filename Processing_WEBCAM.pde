
import processing.video.*;
import java.awt.*;
import processing.serial.*;
Serial port;
Capture video;
color[] pixArray = new color[64];
int border = 25;

void setup(){
  
  size(400, 400);
  
  printArray(Serial.list());
  port = new Serial(this, Serial.list()[3], 115200);
  video = new Capture(this, 400, 400);
  color c = color(0,0,0);
  for(int i = 0; i < pixArray.length; i++){
    pixArray[i] = c;
  }
  
  
  video.start();
}

void draw(){
  background(255);
 
    PImage p = pixelateRect(video);
   
    PImage toShow = p.get(0, 0, p.width, p.height);
   
    image(toShow, 0, 0);
  //}
}

PImage pixelateRect(PImage img){
  int s = 50;
  int i = 0;
  PGraphics pg = createGraphics(img.width, img.height);
  pg.beginDraw();
  //println(img.width);
   for(int x = 0; x < img.width; x = x + s){
     for(int y = 0; y < img.height; y = y +s){
       PImage p  = img.get(x, y,  s,  s);
       color c = averageImage(p);
        //println(hue(c));
        pg.noStroke();
        pg.fill(red(c), green(c), blue(c));
        pg.rect(x, y, s, s);
        String out = ""+(x/s)+";"+(y/s)+";"+round(red(c))+";"+round(green(c))+";"+round(blue(c))+";";
        int thresh = 20;
        if(abs(red(c)-red(pixArray[i]))>thresh || abs(green(c)-green(pixArray[i]))>thresh || abs(blue(c)-blue(pixArray[i]))>thresh){
          pixArray[i]=c;
          println(out);
          port.write(out);
          delay(5);
        }
       
        //println(red(c));
        i ++;
     }
   
 }
  pg.endDraw();
  return pg.get();
}



color averageImage(PImage img){
  img.loadPixels();
  float r = 0;
  float g = 0; 
  float b = 0;
  for (int i = 0; i < img.pixels.length; i ++){
       r = r + red   (img.pixels[i]);
       g = g+green (img.pixels[i]);
       b = b+ blue  (img.pixels[i]);
  }
    r = r / img.pixels.length;
    g = g / img.pixels.length;
    b = b / img.pixels.length;
    color c = color(r, g, b);
    return c;
}

void captureEvent(Capture c) {
  c.read();
}
