#include "TouchButton.h"
#include <Arduino.h>

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100;  // Задержка для дребезга в миллисекундах
bool lastTouchState = HIGH;

void setupTouchButton() {
  pinMode(TOUCH_PIN, INPUT_PULLUP);
  Serial.println("Touch pin initialized");
}

bool isButtonPressed() {
  int reading = digitalRead(TOUCH_PIN);
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != lastTouchState) {
      lastTouchState = reading;
      if (lastTouchState == LOW) {
        lastDebounceTime = millis();
        return true;
      }
    }
  }
  return false;
}
