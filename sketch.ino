#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    10
CRGB leds[NUM_LEDS];
int buttonstate = 0;
int duration = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
	pinMode(triggerPin, OUTPUT);  // Clear the trigger
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	// Sets the trigger pin to HIGH state for 10 microseconds
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
	pinMode(echoPin, INPUT);
	// Reads the echo pin, and returns
	// the sound wave travel time in microseconds
	return pulseIn(echoPin, HIGH);
}

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
    if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
      delay(5000);
      if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
        completed();
        return;
      }
    } else {
    tone(10, 1000);
    delay(100);
    noTone(10);
    delay(900);
    }
  }
  for (int i = 0; i <= 20; i++) {
    if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
      delay(5000);
      if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
        completed();
        return;


      }
    } else {
    tone(10, 1000);
    delay(100);
    noTone(10);
    delay(400);
    }
  }
  for (int i = 0; i <= 20; i++) {
    if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
      delay(5000);
      if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
        completed();
        return;


      }
    } else {
    tone(10, 1000);
    delay(100);
    noTone(10);
    delay(150);
    }
  }
  for (int i = 0; i <= 40; i++) {
    if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
      delay(5000);
      if (0.0344/2 * readUltrasonicDistance(3, 2) <= 20) {
        completed();
        return;


      }
      
    } else {
    tone(10, 1000);
    delay(50);
    noTone(10);
    delay(75);
    }
  }
  delay(100);
  tone(10, 1000);
  delay(1000);
  noTone(10);
}

void completed() {
  Serial.begin(115200);
  Serial.println("Completed");
  for (int i = 0; i <= 16; i++) {
    leds[i] = CRGB ( 255, 173, 182);
    FastLED.show();
    delay(15);
  }
  tone(10, 1000);
  delay(200);
  noTone(10);

  tone(10, 1100);
  delay(200);
  noTone(10);

  tone(10, 1200);
  delay(200);
  noTone(10);


}
