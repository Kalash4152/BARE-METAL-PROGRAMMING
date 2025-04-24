// First: Mix of inputs and outputs
// Set PB0, PB1, PB2 as input
DDRB &= ~(1 << PB0);
DDRB &= ~(1 << PB1);
DDRB &= ~(1 << PB2);

// Set PB3, PB4 as output
DDRB |= (1 << PB3);
DDRB |= (1 << PB4);

// Enable pull-up resistors on input pins
PORTB |= (1 << PB0);
PORTB |= (1 << PB1);
PORTB |= (1 << PB2);

// Later in the code...

// Set ALL PORTB pins as INPUT
DDRB = 0x00;       // All bits = 0 -> All inputs
PORTB = 0xFF;      // Optional: enable pull-ups on all inputs

// Later again...

// Set ALL PORTB pins as OUTPUT
DDRB = 0xFF;       // All bits = 1 -> All outputs
PORTB = 0x00;      // Optional: set all outputs LOW

