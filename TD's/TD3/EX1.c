// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main(){
    TRISB |= 0x10; // RB4
    ANSELB = 0;
    TRISC &= 0xF3;
    LATC = 0x00;

    INTCON |= 0x88; // GIE=1, RBIE=1
    INTCON &= 0xFE; // RBIF=0
    IOCB = 0x10; // IOCB4=1 (Interrupteur ghayb9a khdam 7ta tbdel l'etat dyal RB4)

    while(1);
}

void interrupt(){
    if(PORTB & 0x10){ // RB4=1 (Interrupteur Fermé)
        LATC = 0x02;
    }
    else { // RB4=0 (Interrupteur Ouvert)
        LATC = 0x01;
    }
    INTCON &= 0xFE; // RBIF=0
}