// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

//-------------------------| A |------------------------//
void main(){
    TRISB |= 0x03;
    TRISD = 0x00;
    LATD = 0x00;
    
    RCON &= 0x7F; // IPEN=0
    INTCON |= 0xD0; // GIE=1, PEIE=1, INT0IE=1
    INTCON &= 0xFD; // INT0IF=0
    INTCON3 |= 0x08; // INT1IE=1
    INTCON3 &= 0xFE; // INT1IF=0

    INTCON2 |= 0x60; // INTEDG0=1, INTEDG1=1 (F. Montant - Active à l’État Haut)
    
    while(1){
        LATD = 0xFF;
        delay_ms(500);
        LATD = 0x00;
        delay_ms(500);
    }
}

void interrupt(){
    if((INTCON3 >> 0) & 1){
        LATD = 0xFF;
        delay_ms(2000);
        INTCON3 &= 0xFE; // INT1IF=0
    }
    if((INTCON >> 1) & 1){
        LATD = 0x00;
        delay_ms(2000);
        INTCON &= 0xFD; // INT0IF=0
    }
}


//-------------------------| B |------------------------//
void main(){
    TRISB |= 0x03;
    TRISD = 0x00;
    LATD = 0x00;
    
    RCON |= 0x80; // IPEN=1
    INTCON |= 0xD0; // GIEH=1, GIEL=1, INT0IE=1
    INTCON &= 0xFD; // INT0IF=0

    INTCON3 |= 0x08; // INT1IE=1
    INTCON3 &= 0xBE; // INT1IF=0, INT1IP=0

    INTCON2 |= 0x60; // INTEDG0=1, INTEDG1=1 (F. Montant - Active à l’État Haut)
    
    while(1){
        LATD = 0xFF;
        delay_ms(500);
        LATD = 0x00;
    }
}

void interrupt(){ // INT0
    if((INTCON >> 1) & 1){
        LATD = 0x00;
        delay_ms(2000);
        INTCON &= 0xFD; // INT0IF=0
    }
}

void interrupt_low(){ // INT1
    if((INTCON3 >> 0) & 1){
        LATD = 0xFF;
        delay_ms(2000);
        INTCON3 &= 0xFE; // INT1IF=0
    }
}