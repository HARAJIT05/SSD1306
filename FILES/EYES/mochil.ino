#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128,64,&Wire,-1);

// 'z2', 128x64px
const unsigned char zz[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0xef, 0xff, 0xff, 0xfc, 0xef, 0xf4, 0xff, 0xdf, 0xff, 0xcf, 0xfb, 0xff, 0xff, 0xe0, 0x00, 
	0x03, 0xef, 0xff, 0xff, 0xfc, 0xcf, 0xb2, 0x7f, 0xdf, 0xff, 0x5f, 0x7d, 0xff, 0xff, 0xe0, 0x00, 
	0x03, 0xef, 0xff, 0xff, 0xfc, 0x4f, 0x9b, 0x7f, 0xdf, 0xff, 0xde, 0xff, 0xff, 0xff, 0xe0, 0x00, 
	0x03, 0xe7, 0xff, 0xff, 0xfc, 0x6c, 0x1b, 0xaf, 0xdf, 0xff, 0xdd, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x03, 0xf7, 0xff, 0xff, 0xfc, 0x40, 0x6d, 0xdf, 0xdf, 0xff, 0x9b, 0xff, 0xff, 0xdf, 0xf0, 0x00, 
	0x03, 0xf7, 0xff, 0xdf, 0xfd, 0x40, 0xe5, 0xe7, 0xff, 0xff, 0x99, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x03, 0xf7, 0xbf, 0xdf, 0xf9, 0x41, 0xf4, 0xf3, 0xef, 0xff, 0x90, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x03, 0xf7, 0xbf, 0xdf, 0xfa, 0x41, 0xfa, 0xe1, 0xef, 0xff, 0x90, 0x7f, 0xff, 0xff, 0xf8, 0x00, 
	0x03, 0xe3, 0xbf, 0xdf, 0xfc, 0x43, 0xc0, 0x01, 0xef, 0xff, 0x80, 0x3f, 0x7f, 0xff, 0xf8, 0x00, 
	0x03, 0xf3, 0xff, 0xdf, 0xf8, 0x43, 0x3d, 0x00, 0xef, 0xff, 0x80, 0x3f, 0x7f, 0xef, 0xf8, 0x00, 
	0x01, 0xf3, 0xff, 0xdf, 0xb8, 0x04, 0xf0, 0x00, 0x6f, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xfc, 0x00, 
	0x01, 0xf3, 0xbf, 0xdf, 0xb8, 0x43, 0xc0, 0x00, 0x6f, 0xff, 0x80, 0x1e, 0xff, 0xf7, 0xfc, 0x00, 
	0x01, 0xf1, 0xbf, 0xdf, 0xb0, 0x4f, 0x00, 0x18, 0x2f, 0xff, 0xc0, 0x1e, 0xff, 0xf7, 0xfc, 0x00, 
	0x01, 0xb1, 0xbf, 0xff, 0xb0, 0x4c, 0x00, 0x00, 0x4f, 0xff, 0xc0, 0x3f, 0xff, 0xf7, 0xfe, 0x00, 
	0x01, 0xb1, 0x7f, 0xbf, 0xb0, 0x18, 0x00, 0x01, 0xef, 0xff, 0xc0, 0x3d, 0xff, 0xff, 0xfe, 0x00, 
	0x01, 0xb1, 0x7f, 0xbf, 0x30, 0x00, 0xfc, 0x63, 0xef, 0xff, 0xc0, 0x7d, 0xff, 0xfb, 0xfe, 0x00, 
	0x01, 0xb0, 0x77, 0x5f, 0x30, 0x23, 0xf8, 0xc3, 0xf7, 0xff, 0xc0, 0xfb, 0xff, 0xfb, 0xfe, 0x00, 
	0x01, 0xb0, 0x67, 0x5f, 0x51, 0x0f, 0xfe, 0x11, 0xf7, 0xff, 0xc7, 0xfb, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0x90, 0x67, 0x1e, 0xd7, 0x1f, 0xf8, 0x3e, 0xe7, 0xff, 0xdf, 0xf7, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0x90, 0x66, 0x1e, 0xd7, 0x7f, 0x81, 0xff, 0x27, 0xff, 0xdf, 0xf7, 0xff, 0xfd, 0xff, 0x00, 
	0x00, 0x90, 0x66, 0x0e, 0xd7, 0xff, 0xcf, 0xff, 0xc7, 0xff, 0xdf, 0xef, 0xff, 0xfd, 0xff, 0x80, 
	0x00, 0x90, 0x46, 0x0c, 0xd7, 0xff, 0xff, 0xff, 0x87, 0xff, 0xdf, 0xdf, 0xff, 0xff, 0xff, 0x80, 
	0x00, 0xd0, 0xd4, 0x0d, 0xf7, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdc, 0x3f, 0xff, 0xfe, 0xff, 0x80, 
	0x00, 0xd8, 0x80, 0x0d, 0xe7, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xe8, 0x3f, 0xff, 0xfe, 0xff, 0xc0, 
	0x00, 0xd8, 0x80, 0x0d, 0xe7, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xc0, 
	0x00, 0xd8, 0x00, 0x03, 0xef, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0x7f, 0xc0, 
	0x00, 0xc8, 0x38, 0x03, 0xf7, 0xff, 0xff, 0xff, 0x7b, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0x7f, 0xe0, 
	0x00, 0x48, 0x1f, 0x13, 0xf7, 0xff, 0xff, 0xfe, 0xfb, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0x7f, 0xe0, 
	0x00, 0x0c, 0x1c, 0x63, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xff, 0x80, 0x01, 0xff, 0xff, 0xbf, 0xe0, 
	0x00, 0x0c, 0x07, 0x17, 0xff, 0xff, 0xff, 0xfd, 0xfb, 0xff, 0x80, 0x00, 0x07, 0xff, 0xbf, 0xf0, 
	0x00, 0x04, 0x10, 0x77, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xbf, 0xf0, 
	0x00, 0x04, 0x17, 0xef, 0xff, 0xff, 0xff, 0xf7, 0xfb, 0xff, 0xe0, 0x70, 0x00, 0x07, 0xdf, 0xf0, 
	0x00, 0x24, 0x0f, 0xef, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xe0, 0x7f, 0xe0, 0x00, 0x5f, 0xf8, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x08, 0x0c, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x1c, 0x04, 0xc0, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x18, 0x06, 0x40, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x38, 0x02, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x01, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x78, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x3c, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xc0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x1e, 0x00, 0x20, 0x00, 
	0x00, 0x01, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x06, 0x00, 0x30, 0x00, 
	0x00, 0x03, 0x80, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x00, 0x00, 0x70, 0x00, 
	0x00, 0x07, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x00, 0x00, 0xe0, 0x00, 
	0x00, 0x1e, 0x38, 0x38, 0x03, 0xff, 0xff, 0xf0, 0x07, 0x00, 0x30, 0x00, 0x00, 0x01, 0xc0, 0x00, 
	0x00, 0x38, 0x3e, 0x30, 0x03, 0xff, 0xff, 0xf0, 0x07, 0x00, 0x30, 0x00, 0x00, 0x03, 0x80, 0x00, 
	0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x30, 0x00, 0x00, 0x07, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x70, 0x00, 0x00, 0x0e, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x1c, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x78, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x01, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x07, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x7f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 
	0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();
  display.drawBitmap(0,0,zz,128,64,2);
  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}
