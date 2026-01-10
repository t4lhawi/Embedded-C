// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

//---------------------| Q1 |---------------------//
void main() {
    TRISB = 0;
    LATB = 0;

    while(1){
        LATB = 0x0F;
    }
}

//---------------------| Q2 |---------------------//
void main() {
    char c;
    TRISC = 0xFF;
    ANSELC = 0;

    while(1){
        c = PORTC;
    }
}

//---------------------| Q3 |---------------------//
void main() {
    TRISD = 0xFF;
    ANSELD = 0;
    LATC = 0;

    while(1){
        LATC = PORTD;
    }
}

//---------------------| Q4 |---------------------//
void main() {
    TRISB = 0;
    LATB = 0;

    while(1){
        LATB++;
        delay_ms(1000);
    }
}

//---------------------| Q5 |---------------------//
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