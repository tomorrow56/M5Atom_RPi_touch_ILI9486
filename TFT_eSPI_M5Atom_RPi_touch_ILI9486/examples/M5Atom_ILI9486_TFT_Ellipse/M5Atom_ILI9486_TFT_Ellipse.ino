/*
  Ellipse drawing example

  This sketch does not use any fonts.
*/
#include <M5Atom.h>

#include <SPI.h>
#include <TFT_eSPI_M5Atom_RPi_touch_ILI9486.h>" // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library


void setup(void) {
  M5.begin(true, true, true);

  M5.dis.clear();
  for(int i = 0; i < 25; i++){
    M5.dis.drawpix(i, 0x000080);
  }

  tft.init();

  tft.setRotation(1);

}

void loop() {

  tft.fillScreen(TFT_BLACK);

  // Draw some random circles
  for (int i = 0; i < 40; i++)
  {
    int rx = random(60);
    int ry = random(60);
    int x = rx + random(480 - rx - rx);
    int y = ry + random(320 - ry - ry);
    tft.fillEllipse(x, y, rx, ry, random(0xFFFF));
  }

  delay(2000);
  tft.fillScreen(TFT_BLACK);

  for (int i = 0; i < 40; i++)
  {
    int rx = random(60);
    int ry = random(60);
    int x = rx + random(480 - rx - rx);
    int y = ry + random(320 - ry - ry);
    tft.drawEllipse(x, y, rx, ry, random(0xFFFF));
  }

  delay(2000);
}
