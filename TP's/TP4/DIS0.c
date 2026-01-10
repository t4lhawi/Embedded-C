// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

// Exercice 1 : Gestion de l'Afficheur DIS0 seul
#include "Display_utils.h"

void main () {
    unsigned short i;
    RCON |= 0x80; // Disable priority levels on interrupts
    INTCON = 0; // Disable all interrupts
    
    TRISA = 0; // Configure PortA as output
    LATA = 0; // Turn off all 7seg displays
    
    TRISD = 0; // Configure PortD as output
    LATD = 0; // Clear port D
    
    while (1) {
        for (i = 0 ; i <= 9 ; i++) {
            LATA = 0; // Turn off all 7seg displays
            LATD = mask(i); // bring appropriate value to PORTD
            LATA = 1; // turn on appropriate 7seg display
            delay_ms(1000);
        }
    }
}