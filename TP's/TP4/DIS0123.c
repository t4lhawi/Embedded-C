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
    // Clear TMR0IF
}

void main(){
    // Configure PORTA as output
    // Clear PORTA
    // Configure PORTD as output
    // Clear PORTD
    // Set TMR0 mode, and assign prescaler to TMR0 to create a delay of 1 ms
    // clear TMROL
    // active Timer0 interruption
    digit = 0;
    portd_index = 0;
    shifter = 1;
    number = 9950; // Initial number value
    do {
        // extract thousands from number an put it in digit
        // and store the corresponding mask to PORTD array index 3
        // extract hundreds from number an put it in digit
        // and store the corresponding mask to PORTD array index 2
        // extract tens from number an put it in digit
        // and store the corresponding mask to PORTD array index 1
        // extract ones from number an put it in digit
        // and store the corresponding mask to PORTD array index 0
        delay_ms(1000);
        number++ ;
        if (number > 9999) number = 9950;
    } while(1);
}