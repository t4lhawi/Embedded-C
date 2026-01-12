// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main(){
    TRISB |= 0x10; // RB4
    ANSELB = 0;
    TRISC &= 0xFC;
    LATC = 0x00;

    IOCB = 0x10; // IOCB4=1 (Interrupteur ghykhdem kolma bdelna l'etat dyal RB4 (soit 0 wla 1))

    INTCON |= 0x88; // GIE=1, RBIE=1
    INTCON &= 0xFE; // RBIF=0

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