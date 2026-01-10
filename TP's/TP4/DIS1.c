// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

// Exercice 2 : Gestion de 2 Afficheurs - Multiplexage
#include "Display_utils.h"

void main () {
    unsigned short j;
    unsigned short dizaines;
    unsigned short unites;
    RCON |= 0x80; // Disable priority levels on interrupts
    INTCON = 0; // Disable all interrupts
    
    TRISA = 0; // Configure PortA as output
    LATA = 0; // Turn off all 7seg displays
    
    TRISD = 0; // Configure PortD as output
    LATD = 0; // Clear port D
    
    while (1) {
        for (j = 0; j <= 50; j++) {
            dizaines = (j / 10) % 10;
            unites = j % 10;
            
            // Afficher unités sur DIS0
            LATA = 0b00000001;  // DIS0 ON
            LATD = mask(unites);
            delay_ms(100);
            
            // Afficher dizaines sur DIS1
            LATA = 0b00000010;  // DIS1 ON
            LATD = mask(dizaines);
            delay_ms(100);
        }
    }
}