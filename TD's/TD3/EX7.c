// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

unsigned char var1, var2;

void main(){
    TRISA = 0xFF;
    TRISC = 0xFF;

    TRISD = 0x00;
    LATD = 0x00;
    ANSELB = 0x00;

    RCON |= 0x80; // IPEN=1
    INTCON |= 0xC0; // GIEH=1, GIEL=1

    INTCON |= 0x10; // INT0IE=1
    INTCON3 |= 0x18; // INT1IE=1, INT2IE=1

    INTCON &= 0xFD; // INT0IF=0
    INTCON3 &= 0xFC; // INT1IF=0, INT1IF=0

    INTCON2 |= 0x70; // INTEDG0=1, INTEDG1=1, INTEDG2=1

    INTCON3 &= 0x3F; // INT1IP=0, INT2IP=0

    while(1){
        LATD = var1 + var2;
    }
}

void interrupt(){
    if( (INTCON >> 1) & 1){ // Si INT0IF=1
        var1 = var2 = 0;
        INTCON &= 0xFD; // INT0IF=0
    }
}

void interrupt_low(){
    if( (INTCON3 >> 0) & 1){ // Si INT1IF=1
        var1 = PORTC;
        INTCON3 &= 0xFE; // INT1IF=0
    }
    if( (INTCON3 >> 1) & 1){ // Si INT2IF=1
        var2 = PORTA;
        INTCON3 &= 0xFD; // INT2IF=0
    }
}