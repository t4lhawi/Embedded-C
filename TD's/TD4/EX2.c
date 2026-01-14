// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main(){
    TRISA |= 0x03; // RA1, RA2 en Entree
    ANSELA |= 0x03; // RA1, RA2 en E. Analogie

    TRISD &= 0xFE; // RD0
    LATD &= 0xFE; // RD0=0

    ADCON2 = 0xB9; // ADCS=001 (Fosc/8 pour 8MHz) | ACQT=111 | ADFM=1

    ADCON1 = 0x00; // PVCFG=00 (+VREF=VDD) | NVCFG=00 (-VREF=VSS)

    unsigned int AN1, AN2; // 16-bits

    while(1){
        //----------------| AN1 |----------------//
        ADCON0 = 0x05; // CHS=0001 (AN1) | ADON=1 (Activer CAN)
        
        ADCON0 |= 0x02; // Demarrer Conversion (GO=1)
        
        while((ADCON0 >> 1) & 1); // Attendre Fin (DONE=1)
        
        AN1 = (ADRESH << 8) | ADRESL;


        //----------------| AN2 |----------------//
        ADCON0 = 0x09; // CHS=0010 (AN2) | ADON=1 (Activer CAN)
        
        ADCON0 |= 0x02; // Demarrer Conversion (GO=1)
        
        while((ADCON0 >> 1) & 1); // Attendre Fin (DONE=1)
        
        AN2 = (ADRESH << 8) | ADRESL;


        if(AN1 > AN2){
            LATD |= 0x01; // RD0=1
        } else {
            LATD &= 0xFE; // RD0=0
        }
    }
}