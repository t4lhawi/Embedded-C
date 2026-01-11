// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

// Exercice 4 : Timer 0 Mode Compteur

void main () {
    TRISA |= 0x10; // RA4 Entree
    TRISD = 0;
    LATD = 0;
    
    T0CON = 0xE8; // TMR0ON = 1, T08BIT = 1, T0CS = 1 (Compteur), T0SE = 0 (F. Descendant), PSA = 1
    TMR0L = 0;
    INTCON &= 0xFB; // TMR0IF = 0

    while (1){
        LATD = TMR0L;
    }
}