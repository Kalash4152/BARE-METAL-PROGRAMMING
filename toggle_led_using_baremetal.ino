/*
  Arduino LED Control using Direct Port Manipulation

  This program demonstrates two operations on an LED connected to Digital Pin 9:
  1. First, the LED is turned ON for 5 seconds and then turned OFF.
  2. After that, the LED continuously toggles its state (ON/OFF) every 0.5 seconds.

  Instead of using the traditional `digitalWrite()` and `pinMode()` functions,
  this code uses direct register manipulation for faster and more efficient control.

  Pin 9 on Arduino Uno corresponds to PB1 on Port B.
  So we use DDRB to set it as output and PORTB to write logic levels.
*/

void setup() {
  // Set PB1 (digital pin 9) as output
  DDRB |= (1 << PB1);

  // Turn LED ON
  PORTB |= (1 << PB1);
  delay(5000); // wait for 5 seconds

  // Turn LED OFF
  PORTB &= ~(1 << PB1);
}

void loop() {
  // Toggle LED on pin 9 using XOR
  PORTB ^= (1 << PB1);
  delay(500); // toggle every 0.5 seconds
}
