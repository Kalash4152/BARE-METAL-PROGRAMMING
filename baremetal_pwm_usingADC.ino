// This program generates a PWM signal whose duty cycle is controlled by an analog input (e.g., a potentiometer).
// It uses Timer1 for PWM generation and the ADC (Analog-to-Digital Converter) to read the analog input.
// The PWM frequency is set to 50 Hz (20ms period), and the duty cycle is adjusted based on the ADC value (0-1023).

#include <avr/io.h>  // Include AVR input/output library

// Setup function for PWM
void setupPWM() {
    DDRB |= (1 << PB1); // Set PB1 as an output pin (for PWM signal)
    
    // Configure Timer1 for Fast PWM mode and non-inverted output on OC1A (PB1)
    TCCR1A = (1 << COM1A1) | (1 << WGM11); // COM1A1: non-inverted mode, WGM11: Fast PWM mode
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // WGM13, WGM12: Fast PWM mode, CS11: prescaler of 8
    
    ICR1 = 19999; // Set TOP value to 19999 for 50Hz PWM frequency (20ms period)
}

// Setup function for ADC
void setupADC() {
    ADMUX = (1 << REFS0); // Set AVCC as reference voltage
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC, prescaler = 128
}

// Function to read ADC value from a specified channel
uint16_t readADC(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Select the channel (0-5 for A0-A5)
    ADCSRA |= (1 << ADSC); // Start the ADC conversion
    while (ADCSRA & (1 << ADSC)); // Wait until the conversion is complete
    return ADC; // Return the ADC result
}

int main() {
    setupPWM();  // Initialize PWM
    setupADC();  // Initialize ADC
    
    while (1) {
        uint16_t potValue = readADC(0);  // Read the value from ADC channel 0 (A0)
        
        // Map the ADC value (0-1023) to a PWM duty cycle (0-ICR1)
        OCR1A = (potValue * ICR1) / 1023;  // Set the duty cycle of PWM based on ADC value
    }
}
