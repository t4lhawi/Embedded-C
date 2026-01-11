// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

//---------------------| Exercice 1 |---------------------//
void main(){ 
    TRISA = 0XFF;
    ANSELA = 0xFF;

    TRISB = 0;
    LATC = 0;

    TRISC = 0;
    LATB = 0;

    ADCON0 = 1;
    ADCON1 = 0;
    ADCON2 = 0x15;

    while(1){
        ADCON0|= 2; 
        while(ADCON0 & 2);
        LATB = ADRESL;
        LATC = ADRESH;
    } 

}

//---------------------| Exercice 2 |---------------------//

//---------------------| Exercice 3 |---------------------//






//---------------------| Exercice 4 |---------------------//

//-------------------------| Q1 |------------------------//
void main() {
    int donnees;
    float tension;
    TRISA = 0XFF;
    ANSELA = 0xFF;
    TRISB = 0 ;
    TRISC = 0 ;
    ADCON0 = 1;
    ADCON1 = 0;
    ADCON2 = 0x15;

    while(1) {
        ADCON0 |= 2;
        while(ADCON0 & 2);
        donnees = ADRESH;
        donnees = donnees << 2 | ADRESL >> 6;
        tension = (float) (donnees*500.0) / 1023.0;
        LATC = ((int) tension) / 100;
        LATB = ((int) tension) % 100;
    }
}



//-------------------------| Q2 |------------------------//
unsigned short shifter;
unsigned short portd_index;
unsigned int digit, number;
unsigned short portd_array[4];

unsigned short mask(char num) {
    switch (num) {
        case 0 : return 0x3F;
        case 1 : return 0x06;
        case 2 : return 0x5B;
        case 3 : return 0x4F;
        case 4 : return 0x66;
        case 5 : return 0x6D;
        case 6 : return 0x7D;
        case 7 : return 0x07;
        case 8 : return 0x7F;
        case 9 : return 0x6F;
    }
}

void interrupt() {
    LATA = 0; 
    LATD = portd_array[portd_index]; 
    LATA = shifter;
    shifter <<= 1;

    if (shifter > 8) shifter = 1;
    
    portd_index++;

    if (portd_index > 3) portd_index = 0;
    
    TMR0L = 0;

    INTCON &= 0xFB;
}

void main() {
    // ADC configuration
    int donnees;
    float tension;
    TRISB = 0XFF; 
    ANSELB = 0xFF;
    ADCON0 = 0b00110001;
    ADCON1 = 0;
    ADCON2 = 0x15;

    // 7seg configuration
    TRISA = 0;
    LATA = 0;
    TRISD = 0;
    LATD = 0;
    T0CON = 0b11000010;
    TMR0L = 0;
    INTCON = 0xA0;
    digit = 0;
    portd_index = 0;
    shifter = 1;
    number = 0; // Initial number value

    while(1) {
        ADCON0|=2;
        while(ADCON0 & 2);
        donnees = ADRESH;
        donnees = donnees<<2 | ADRESL>>6;
        tension = (float) (donnees*500.0)/1023.0;
        number = (int) tension;

        digit = number / 1000; 
        portd_array[3] = mask(digit);

        digit = (number / 100) % 10; 
        portd_array[2] = mask(digit)+0x80;

        digit = (number % 100) / 10; 
        portd_array[1] = mask(digit);

        digit = (number % 10); 
        portd_array[0] = mask(digit);

        delay_ms(200);
    }
}