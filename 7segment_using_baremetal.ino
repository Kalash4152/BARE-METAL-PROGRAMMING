/*
  Project: 7-Segment Display using Register-Level Programming on Arduino (ATmega328P)
  Author: Kalash Bheda
  Description:
    - This project displays digits 0–9 on a common cathode 7-segment display.
    - Each segment (a to g) is connected to PORTB pins PB0–PB6 on the ATmega328P.
    - The user enters a digit (0 to 9) via the Serial Monitor.
    - The program uses switch-case and register-level control (no pinMode/digitalWrite).
    - It sends the corresponding 7-segment hex code directly to PORTB to light up segments.

  Hardware:
    - Common cathode 7-segment display
    - Segments a–g connected to Arduino pins PB0–PB6
    - Common cathode pin connected to GND

  How It Works:
    - DDRB (Data Direction Register B) is used to set PB0–PB6 as output.
    - PORTB is directly written with specific bit patterns (hex codes) for each digit.
    - The serial terminal receives characters, and appropriate hex is selected using switch-case.
*/

char input;  // Variable to store the user's input

void setup() {
  // Set PB0 to PB6 as output (segment lines)
  DDRB |= 0b01111111;  // Bits 0–6 set to 1 (output), PB7 left unchanged

  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  Serial.println("Enter a number (0-9):");
}

void loop() {
  // Check if data is available from the serial monitor
  if (Serial.available()) {
    input = Serial.read();  // Read one character from serial input

    // Match the input character using switch-case
    switch (input) {
      case '0':
        PORTB = (PORTB & 0b10000000) | 0x3F;  // Display 0
        break;
      case '1':
        PORTB = (PORTB & 0b10000000) | 0x06;  // Display 1
        break;
      case '2':
        PORTB = (PORTB & 0b10000000) | 0x5B;  // Display 2
        break;
      case '3':
        PORTB = (PORTB & 0b10000000) | 0x4F;  // Display 3
        break;
      case '4':
        PORTB = (PORTB & 0b10000000) | 0x66;  // Display 4
        break;
      case '5':
        PORTB = (PORTB & 0b10000000) | 0x6D;  // Display 5
        break;
      case '6':
        PORTB = (PORTB & 0b10000000) | 0x7D;  // Display 6
        break;
      case '7':
        PORTB = (PORTB & 0b10000000) | 0x07;  // Display 7
        break;
      case '8':
        PORTB = (PORTB & 0b10000000) | 0x7F;  // Display 8
        break;
      case '9':
        PORTB = (PORTB & 0b10000000) | 0x6F;  // Display 9
        break;
      default:
        Serial.println("Invalid input. Please enter a digit (0–9).");
        break;
    }
  }
}
