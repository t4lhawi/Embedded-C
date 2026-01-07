// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO for PIC (PIC18F)

volatile char etat = 0;

void main(){
    TRISC = 0x00;
    LATC = 0x00;

    INTCON2 |= 0x40; // INTEDG0=1
    INTCON |= 0x90; // GIE=1, INT0IE=1

    while(1){
        if(!etat){
            LATC = 0x01;
        } else {
            LATC = 0x02;
        }
    }
}

void interrupt(){
    if( (INTCON >> 1) & 1){ // Si INT0IF=1
        etat = !etat;
        INTCON &= 0xFD; // INT0F=0
    }
}