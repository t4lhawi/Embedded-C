// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main() {
    // Bus d’entrée Ib et Ih : PORTA
    TRISA = 0xFF;
    ANSELA = 0;

    unsigned char Ib = PORTA & 0x01;
    unsigned char Ih = PORTA & 0x02;
    
    // Bus de sortie LEDs B, H et E : PORTB
    // LED B : 0b00000001 = 0x01
    // LED H : 0b00000010 = 0x02
    // LED E : 0b00000100 = 0x04
    TRISB = 0;
    LATB = 0;


    while(1){
        // Niveau normal (30 cm <= niveau <= 250 cm)
        if (Ib == 0 && Ih == 0) {
            LATB = 0; // Aucune LED allumée
        }
        // Niveau faible (< 30 cm)
        else if (Ib == 1 && Ih == 0) {
            LATB |= 0x01; // LED B
        }
        // Niveau haut (> 250 cm)
        else if (Ib == 0 && Ih == 1) {
            LATB |= 0x02; // LED H
        }
        // Cas incoherent
        else if (Ib == 1 && Ih == 1) {
            LATB |= 0x04; // LED E
        }
    }
}