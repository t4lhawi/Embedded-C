// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

//---------------------| Q1 |---------------------//
void main(){
    TRISC = 0x00;
    ANSELB = 0x00;

    INTCON2 |= 0x40; // INTEDG0=1
    INTCON |= 0x90; // GIE=1, INT0IE=1
    
    while(1){
        LATC = 0x00;
    }
}

void interrupt(){
    LATC = ~LATC;
    delay_ms(500);
    INTCON &= 0xFD; // INT0F=0
}

//---------------------| Q2 |---------------------//
void main(){
    TRISC = 0x00;
    TRISD = 0x00;
    ANSELB = 0x00;

    INTCON2 |= 0x40; // INTEDG0=1
    INTCON |= 0x88; // GIE=1, RBIE=1
    
    while(1){
        LATC = 0x00;
    }
}

void interrupt(){
    LATC = ~LATC;
    delay_ms(1000);
    LATD = LATC;
    INTCON &= 0xFC; // RBIF=0
}

//---------------------| Q3 |---------------------//
unsigned char int0_flag = 0;
unsigned char int1_flag = 0;

void main(){
    TRISD = 0x00;
    LATD = 0x00;
    ANSELB = 0x00;
    
    INTCON2 |= 0x60; // INTEDG0=1, INTEDG1=1

    INTCON |= 0x90; // GIE=1, INT0IE=1
    INTCON3 |= 0x08; // INT1IE=1
    
    INTCON &= 0xFD; // INT0F=0
    INTCON3 &= 0xFE; // INT1F=0


    while(1){
        if(int0_flag){ // Si INT0F=1
            LATD = 0x01;
            delay_ms(1000);
            LATD = 0x00;
            int0_flag = 0;
        }

        if(int1_flag){ // Si INT1F=1
            LATD = 0x02;
            delay_ms(4000);
            LATD = 0x00;
            int1_flag = 0;
        }
    }
}

void interrupt(){
    if( ( (INTCON >> 1) & 1) == 1){ // Si INT0F=1
        int0_flag = 1;
        INTCON &= 0xFD; // INT0F=0
    }

    if( ( (INTCON3 >> 0) & 1) == 1){ // Si INT1F=1
        int1_flag = 1;
        INTCON3 &= 0xFE; // INT1F=0
    }
}

//---------------------| Q4 |---------------------//
void main(){
    TRISA = 0x00;
    LATA = 0x00;

    TRISB = 0xF0;
    ANSELB = 0x00;

    INTCON |= 0x88; // GIE=1, RBIE=1
    INTCON2 &= 0xFE; // RBIF=0

    while(1);
}

void interrupt(){
    if( (INTCON >> 0) & 1){ // Si RBIF=1
        LATA = ~LATA;
        INTCON &= 0xFE; // RBIF=0
    }
}

//---------------------| Q5 |---------------------//
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
    INTCON3 &= 0xFC; // INT1IF=0, INT2IF=0

    INTCON2 |= 0x70; // INTEDG0=1, INTEDG1=1, INTEDG2=1

    while(1){
        LATD = var1 + var2;
    }
}

void interrupt(){
    if( (INTCON >> 1) & 1){ // Si INT0IF=1
        var1 = var2 = 0;
        INTCON &= 0xFD; // INT0IF=0
    }
    if( (INTCON3 >> 0) & 1){ // Si INT1IF=1
        var1 = PORTC;
        INTCON3 &= 0xFE; // INT1IF=0
    }

    if( (INTCON3 >> 1) & 1){ // Si INT2IF=1
        var2 = PORTA;
        INTCON3 &= 0xFD; // INT2IF=0
    }
}