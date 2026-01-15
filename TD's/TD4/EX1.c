// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

//-------------------------| A |------------------------//
void main(){
    TRISA |= 0x01; // RA0 en Entree
    ANSELA |= 0x01; // RA0 en E. Analogie

    TRISB = 0x00;
    LATB = 0x00;
    TRISC = 0x00;
    LATC = 0x00;

    ADCON2 = 0xB9; // ADCS=001 (Fosc/8 pour 8MHz) | ACQT=111 | ADFM=1

    ADCON1 = 0x00; // PVCFG=00 (+VREF=VDD) | NVCFG=00 (-VREF=VSS)

    ADCON0 = 0x01; // CHS=0000 (AN0) | ADON=1 (Activer CAN)

    while(1){
        ADCON0 |= 0x02; // Demarrer Conversion (GO/DONE=1)

        while(((ADCON0 >> 1) & 1) == 0); // Attendre Fin (GO/DONE=0)
        
        LATB = ADRESL; // 8-bits
        LATC = ADRESH; // 2-bits
    }
}

//-------------------------| B |------------------------//

void main(){
    TRISA |= 0x01; // RA0 en Entree
    ANSELA |= 0x01; // RA0 en E. Analogie

    TRISB = 0x00;
    LATB = 0x00;
    TRISC = 0x00;
    LATC = 0x00;

    INTCON |= 0xC0; // GIE=1, PEIE=1
    PIE1 |= 0x40; // ADIE=1
    PIR1 &= 0xBF; // ADIF=0

    ADCON2 = 0xB9; // ADCS=001 (Fosc/8 pour 8MHz) | ACQT=111 | ADFM=1

    ADCON1 = 0x00; // PVCFG=00 (+VREF=VDD) | NVCFG=00 (-VREF=VSS)

    ADCON0 = 0x01; // CHS=0000 (AN0) | ADON=1 (Activer CAN)

    while(1){
        ADCON0 |= 0x02; // Demarrer Conversion (GO=1)
    }
}

void interrupt(){
    if((PIR1 >> 6) & 1){ // Si ADIF=1
        LATB = ADRESL; // 8-bits
        LATC = ADRESH; // 2-bits
        
        PIR1 &= 0xBF; // ADIF=0
    }
}