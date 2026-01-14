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
        ADCON0 |= 0x02; // Demarrer Conversion (GO=1)

        while((ADCON0 >> 1) & 1); // Attendre Fin (DONE=1)
        
        LATB = ADRESL; // 8-bits
        LATC = ADRESH; // 2-bits
    }
}

//-------------------------| B |------------------------//