// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main(){
    TRISC = 0x00;
    TRISB |= 0x02; // Buttons de l'interruption INT1
    ANSELB = 0;
    LATC = 0x00;

    INTCON |= 0xC0; // GIE=1, PEIE=1
    INTCON2 &= 0xDF; // INTEDG1=0 (F. Descendant)
    INTCON3 |= 0x08; // INT1IE=1
    INTCON3 &= 0xFE; // INT1IF=0

    while(1){

    }
}

void interrupt(){
    unsigned char i;
    if((INTCON3 >> 0) & 1){
        for(i=0; i < 5; i++){
            LATC = 0xFF;
            delay_ms(500);
            LATC = 0x00;
            delay_ms(500);
        }
        INTCON3 &= 0xFE; // INT1IF=0
    }
}