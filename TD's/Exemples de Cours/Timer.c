// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

// Exemple : Programme permet de de clignoter une LED branche avec le PORTB chaque 0,5s a l’aide de Timer2, et 
// faire une rotation a gauche de PORTB chaque 1,5 s a l’aide Timer 4 (priorité élevé). 
// Horloge de système est de 8Mhz.

unsigned int timer2 = 0;
unsigned int timer4 = 0;

void main() {
    TRISB = 0x00;
    LATD = 0x00;

    // Configuration des Interruptions
    RCON |= 0x80; // IPEN=1
    INTCON |= 0xC0; // GEIH=1, GEIL=1
    
    PIE1 |= 0x02; // TMR2IE=1
    PIE5 |= 0x01; // TMR5IE=1

    IPR1 &= 0xFD; // TMR2IP=0
    IPR5 |= 0x01; // TMR4IP=1

    PIR1 &= 0xFD; // TMR2IF=0
    PIR5 &= 0xFE; // TMR4IF=0

    // Configuration des Timers 2 (0.5s) et 4 (1.5s)
    T2CON = 0x4E; // 0b01001110 | Prediv=1:16 , Postdiv=1:10 -> iterations = 25
    PR2 = 249;

    T4CON = 0x76; // 0b01110110 | Prediv=1:16 , Postdiv=1:15 -> iterations = 50
    PR4 = 249;

    while(1);
}

void interrupt(){
    if((PIR5 >> 0) & 1){
        PIR5 &= 0xFE; // TMR4IF=0
        timer4++;
        if(timer4 >= 150){
            LATB = (PORTB << 1) | (PORTB >> 7);
            timer4 = 0;
        }
    }
}

void interrupt_low(){
    if((PIR1 >> 1) & 1){
        PIR1 &= 0xFD; // TMR2IF=0
        timer2++;
        if(timer2 >= 50){
            LATB = ~LATB; // Basculer RB0
            timer2 = 0;
        }
    }
}