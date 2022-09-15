# LED-MATRIX
These files show a base use for a 8 x 8 RGB LED matrix using the adafruit GFX library and the adafruit NeoPixel library.


## Functions to control drawing

### Draw one pixel
```java
matrix.drawPixel(x, y, matrix.Color(r, g, b));
```

x: horizontal position 

y: vertical position

r: red value (0, 255)

g: green value (0,255)

b: blue value (0, 255)



### Draw a line
```java
matrix.drawLine(x1, y1, x2, y2, matrix.Color(r, g, b));
```
x1: horizontal poistion for start of the line

y1: vertical poistion for start of the line

x2: horizontal poistion for end of the line

y2: vertical poistion for end of the line


### Draw a Rectangle outline
```java
matrix.drawRect(x, y, w, h, matrix.Color(r, g, b));
```java

### Draw a filled Rectangle
```java
matrix.fillRect(x, y, w, h, matrix.Color(r, g, b));
```java

### Draw a Circle outline
```java
matrix.drawCircle(x, y, rad, matrix.Color(r, g, b));
```

### Draw a filled Circle
```java
matrix.fillCircle(x, y, rad, matrix.Color(r, g, b));
```java
rad = radius of circle

### Set overall brightness of display
```java
matrix.setBrightness(255);
```java

### Clear whole display
```java
matrix.clear();
```java

### Update the display
```java
matrix.show();
```java
