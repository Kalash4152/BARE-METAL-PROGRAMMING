/*
  Project: Interfacing Push Button with LED using Register-Level Programming
  Author: Kalash Bheda

  Description:
    - An LED is connected to pin PB0 (Arduino digital pin 8).
    - A push button is connected to pin PD2 (Arduino digital pin 2).
    - When the button is pressed, the LED turns ON.
    - When the button is released, the LED turns OFF.
    - No Arduino functions like digitalRead/digitalWrite are used — only register manipulation.

  How It Works:
    - DDRB is used to set PB0 as output (LED).
    - DDRD is used to set PD2 as input (Button).
    - The state of PD2 is read from the PIND register.
    - If bit 2 of PIND is HIGH (button pressed), we set PB0 HIGH (LED ON).
    - Otherwise, we clear PB0 (LED OFF).
*/

void setup() {
  DDRB |= (1 << PB0);   // Set PB0 as output (LED)
  DDRD &= ~(1 << PD2);  // Set PD2 as input (Button)
}

void loop() {
  if (PIND & (1 << PD2)) {
    // If PD2 is high (button pressed)
    PORTB |= (1 << PB0);   // Turn ON LED (set PB0 high)
  } else {
    // If PD2 is low (button not pressed)
    PORTB &= ~(1 << PB0);  // Turn OFF LED (clear PB0)
  }
}
