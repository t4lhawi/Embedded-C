// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main(){
    TRISB |= 0x03; // Buttons de l'interruption INT0, INT1
    ANSELB = 0;
    TRISD &= 0xFC; // RD0, RD1 en Sortie
    LATD = 0x00;

    RCON &= 0x7F; // IPEN=0
    INTCON |= 0xD0; // GIE=1, PEIE=1, INT0IE=1
    INTCON &= 0xFD; // INT0IF=0

    INTCON3 |= 0x08; // INT1IE=1
    INTCON3 &= 0xFE; // INT1IF=0
    
    INTCON2 &= 0x9F;

    while(1);
}

void interrupt(){
    if(((INTCON >> 1) & 1)){
        LATD |= (1 << 0); // RD0=1
        delay_ms(300);
        LATD &= ~(1 << 0);
        INTCON &= 0xFD; // INT0IF=0
    }

    if(((INTCON3 >> 0) & 1)){
        LATD |= (1 << 1); // RD1=1
        delay_ms(500);
        LATD &= ~(1 << 1);
        INTCON3 &= 0xFE; // INT1IF=0
    }
}