// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO for PIC (PIC18F)

//---------------------| Q1 |---------------------//
void main() {
    TRISB = 0;
    LATB = 0;

    while(1){
        LATB++;
        delay_ms(1000);
    }
}

//---------------------| Q2 |---------------------//
void main() {
    TRISD = 0;
    LATD = 0;

    TRISB = 0xFF;
    ANSELB = 0;

    TRISC = 0xFF;
    ANSELC = 0;

    while(1){
        LATD = PORTB + PORTC;
    }
}

//---------------------| Q3 |---------------------//
void main() {
    TRISA |= 0b00000010; // RA1 en entrée
    ANSELA &= 0b11111101;
    
    TRISB = 0;
    LATB = 0;

    while(1){
        if(( (PORTA >> 1) & 1 ) == 0){
            LATB = 0x0F;
        }
        else {
            LATB = 0xF0;
        }
    }
}

//---------------------| Q4 |---------------------//
void main() {
    // Bus d’entrée : PORTA
    TRISA = 0xFF;
    ANSELA = 0;

    // Bus de sortie : PORTB
    TRISB = 0;
    LATB = 0;

    while(1){
        switch(PORTA){
            case 0:
                LATB = 0b11000011;
                delay_ms(500);
                LATB = ~LATB;
                delay_ms(500);
                break;
            case 1:
                LATB = 0b10011001;
                delay_ms(500);
                LATB = ~LATB;
                delay_ms(500);
                break;
            case 2:
                LATB = 0b10101010;
                delay_ms(500);
                LATB = ~LATB;
                delay_ms(500);
                break;
            case 3:
                LATB = 0b11111111;
                delay_ms(500);
                LATB = ~LATB;
                delay_ms(500);
                break;
            default:
                LATB = 0;
                break;
        }
    }
}

//---------------------| Q5 |---------------------//
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