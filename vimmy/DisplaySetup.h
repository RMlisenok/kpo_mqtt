#ifndef DISPLAYSETUP_H
#define DISPLAYSETUP_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Определение выводов для SPI-дисплея
#define TFT_CS     15  // D8
#define TFT_RST    5   // D1
#define TFT_DC     4   // D2

extern Adafruit_ST7735 tft;

void setupDisplay();
void displayEmotion(int emotion);

#endif
