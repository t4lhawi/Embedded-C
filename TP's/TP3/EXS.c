// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO for PIC (PIC18F)

//---------------------| Q1 |---------------------//
void main(){
    TRISC = 0;
    ANSELB = 0;
    INTCON2 |= 0x40; // INTEDG0=1
    INTCON |= 0x90; // GIE=1, INT0IE=1
    
    while(1){
        LATC = 0x00;
    }
}

void interrupt(){
    LATC=~LATC;
    delay_ms(500);
    INTCON &=0xFD; // INT0F=0
}

//---------------------| Q2 |---------------------//
void main(){
    TRISC = 0;
    TRISD = 0;
    ANSELB = 0;
    INTCON2 |= 0x40; // INTEDG0=1
    INTCON |= 0x88; // GIE=1, RBIE=1
    
    while(1){
        LATC = 0x00;
    }
}

void interrupt(){
    LATC=~LATC;
    delay_ms(1000);
    LATD = LATC;
    INTCON &=0xFC; // RBIF=0
}
//---------------------| Q3 |---------------------//
