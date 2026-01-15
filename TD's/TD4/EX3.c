// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main(){
    TRISA |= 0x20; // RA5 en Entree
    ANSELA |= 0x20; // RA5 en E. Analogie

    TRISC = 0x00;
    LATC = 0x00;

    TRISD = 0x00;
    LATD = 0x00;

    ADCON2 = 0xB9; // ADCS=001 (Fosc/8 pour 8MHz) | ACQT=111 | ADFM=1

    ADCON1 = 0x00; // PVCFG=00 (+VREF=VDD) | NVCFG=00 (-VREF=VSS)

    ADCON0 = 0x15; // CHS=00101 (AN5) | ADON=1 (Activer CAN)

    while(1){
        // Demarrer Conversion (GO=1)
        ADCON0 |= 0x02;
        
        // Attendre Fin Jusqu'à (GO/DONE=0)
        while(ADCON0 & 0x02);

         // Lire valeur ADC 10-bit (0-1023)
        unsigned int CAN = (ADRESH << 8) | ADRESL;
        
        // Convertir en tension (0-5V)
        float volt = (CAN * 5.0) / 1023.0;
        
        // Partie entière (0-5)
        unsigned int partie_entier = volt;

        // Partie fractionnaire (0-99 pour 2 décimales)
        float frac = volt - partie_entier;
        unsigned int partie_frac = frac * 100 ;
    
        // Afficher
        LATC = partie_entier;
        LATD = partie_frac;
    }
}