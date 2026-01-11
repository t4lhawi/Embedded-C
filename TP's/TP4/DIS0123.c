// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

// Exercice 3 : Gestion des 4 Afficheurs - Interruption
#include "Display_utils.h"

unsigned short shifter; // For offset display
unsigned short portd_index; // data table index
unsigned int digit, number; // data digits
unsigned short portd_array[4]; // data table

void interrupt() {
    LATA = 0; // Turn off all 7seg displays
    LATD = portd_array[portd_index]; // bring appropriate value to
    PORTD LATA = shifter; // turn on appropriate 7seg display

    // move shifter to next digit
    shifter <<= 1;
    if (shifter > 8) shifter = 1;
    // increment portd_index
    portd_index++ ;
    if (portd_index > 3) portd_index = 0;
    // reset TIMER0 data register value
    TMR0L = 0;
    TMR0H = 0;
    // Clear TMR0IF
    INTCON &= 0xFB;
}

void main(){
    // Configure PORTA as output
    TRISA = 0;
    // Clear PORTA
    LATA = 0;
    // Configure PORTD as output
    TRISD = 0;
    // Clear PORTD
    LATD = 0;
    // Set TMR0 mode, and assign prescaler to TMR0 to create a delay of 1 ms
    T0CON = 0b11000100; // TMR0ON = 1, T08BIT = 1, T0CS = 0, PSA = 0, T0PS = 0b100 (Pré-diviseur = 1:32)
    TMR0L = 194; // Valeur initial
    // clear TMR0IF
    INTCON |= 0x04;
    // active Timer0 interruption
    INTCON |= 0xA0;

    digit = 0;
    portd_index = 0;
    shifter = 1;
    number = 9950; // Initial number value
    do {
        // extract thousands from number an put it in digit        
        digit = (number / 1000) % 10;
        // and store the corresponding mask to PORTD array index 3
        portd_array[3] = mask(digit);
        // extract hundreds from number an put it in digit
        digit = digit = (number / 100) % 10;
        // and store the corresponding mask to PORTD array index 2
        portd_array[2] = mask(digit);
        // extract tens from number an put it in digit
        digit = digit = (number / 10) % 10;
        // and store the corresponding mask to PORTD array index 1
        portd_array[1] = mask(digit);
        // extract ones from number an put it in digit
        digit = digit = (number / 1) % 10;
        // and store the corresponding mask to PORTD array index 0
        portd_array[0] = mask(digit);

        delay_ms(1000);

        number++ ;

        if (number > 9999) number = 9950;

    } while(1);
}