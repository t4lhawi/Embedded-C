// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main() {
    // PORTA 3bits : Entree (Operation)
    TRISA |= 0b00000111;
    ANSELA &= 0b11111000;

    unsigned char E = PORTA & 0x07;

    // PORTB 8bits : Entree
    TRISB = 0xFF;
    ANSELB = 0;

    // PORTC 8bits : Entree
    TRISC = 0xFF;
    ANSELC = 0;

    // PORTD : Sortie
    TRISD = 0;
    ANSELD = 0;
    LATD = 0;

    while(1){
        switch(E){
            case 0:
                LATD = PORTC && PORTB;
                break;
            case 1:
                LATD = PORTC || PORTB;
                break;
            case 2:
                LATD = (PORTB << 2) | (PORTB >> (8 - 2));
                break;
            case 3:
                LATD = (PORTB >> 1);
                break;
            case 4:
                LATD = PORTC + PORTB;
                break;
            case 5:
                LATD = PORTC - PORTB;
                break;
            case 6:
                LATD = PORTC / PORTB;
                break;
            case 7:
                LATD = PORTC * PORTB;
                break;
            default:
                LATD = 0;
                break;
        }
    }
}