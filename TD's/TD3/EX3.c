// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

unsigned char etat = 0;

void main(){
    TRISA = 0x00;
    TRISB |= 0xF0; // Buttons de l'interruption RB4-7)
    LATA = 0x00;

    INTCON |= 0x88; // GIE=1, RBIE=1
    INTCON &= 0xFE; // RBIF=0

    while(1){
        if(etat){
            LATA = 0xFF;
        } else {
            LATA = 0x00;
        }
    }
}

void interrupt(){
    if(((INTCON >> 0) & 1)){
        etat = !etat;
        INTCON &= 0xFE; // RBIF=0
    }
}