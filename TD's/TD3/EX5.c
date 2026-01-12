// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

unsigned char div = 0;

void main(){
    TRISB |= 0x20; // RB5=1 (Entree)
    ANSELB = 0;
    TRISC &= 0xFD; // RC1=0 (Sortie)
    LATC = 0x00;
    
    INTCON |= 0x88; // GIE=1, RBIE=1
    INTCON &= 0xFE; // RBIF=0

    IOCB |= 0x20; // IOCB5=1

    while(1);
}

void interrupt(){
    if(PORTB & 0x20){
        div++;
        if(div % 5 == 0){
            LATC = 0x02;
        } else {
            LATC = 0x00;
        }
    }
    INTCON &= 0xFE; // RBIF=0
}