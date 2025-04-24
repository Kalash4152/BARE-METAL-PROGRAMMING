#include <avr/io.h>       // For register definitions
#define F_CPU 16000000UL  // Define CPU clock frequency (16 MHz)
#include <util/delay.h>    // For delay functions

int main(void) {
    // Step 1: Set reference voltage to AVcc
    ADMUX = (1 << REFS0);

    // Step 2: Set ADC prescaler to 64 and enable ADC
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // ADC Enable (ADEN) and Prescaler (ADPS2, ADPS1)

    uint16_t adc_value;

    while (1) {
        // Step 3: Start the conversion by setting the ADSC bit
        ADCSRA |= (1 << ADSC);

        // Step 4: Wait for the conversion to complete (ADSC bit becomes 0 when done)
        while (ADCSRA & (1 << ADSC));

        // Step 5: Read the ADC value (ADCL and ADCH contain the result)
        adc_value = ADC;  // 16-bit value (ADCL + ADCH)

        // Optional: You can use the adc_value here, e.g., send to a UART or display it

        // Small delay for stability
        _delay_ms(100);
    }

    return 0;
}
