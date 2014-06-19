#include <mbq.h>

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    DigitalWrite(D8, true);
    delayMicroseconds(tone);
    DigitalWrite(D8, false);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
 }
}

void setup()
{
	float forwardSpeed, backwardSpeed, leftSpeed, rightSpeed, stopSpeed, duration, distance, tolerance;
	initBoard();
	while(true)
	{
		forwardSpeed = 50;
		DigitalWrite(D4, false);
		DigitalWrite(D2, true);
		DigitalWrite(D5, false);
		DigitalWrite(D7, true);
		AnalogWrite(PWM3, forwardSpeed);
		AnalogWrite(PWM6, forwardSpeed);
		
		delay(1000);
		playNote('c', 300);
		delay(150);
	}
}

void loop()
{
}

