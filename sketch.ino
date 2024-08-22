#include <FastLED.h>
#include <Buzzer.h>

#define LED_PIN     A5
#define NUM_LEDS    16
Buzzer buzzer(13);


CRGB leds[NUM_LEDS];

int buttonstate = 0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}
void loop() {
  buttonstate = digitalRead(11);
  if (buttonstate == HIGH) {
    start();
  } else {

  }

}

void start() {
  for (int i = 0; i <= 16; i++) {
    leds[i] = CRGB ( 218, 255, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = 0; i <= 25; i++) {
    tone(10, 1000);
    delay(100);
    noTone(10);
    delay(900);
  }
  for (int i = 0; i <= 20; i++) {
    tone(10, 1000);
    delay(100);
    noTone(10);
    delay(400);
  }
  for (int i = 0; i <= 20; i++) {
    tone(10, 1000);
    delay(100);
    noTone(10);
    delay(150);
  }
  for (int i = 0; i <= 40; i++) {
    tone(10, 1000);
    delay(50);
    noTone(10);
    delay(75);
  }
  delay(100);
  tone(10, 100);
  delay(1000);
  noTone(10);
}

void completed() {

}
