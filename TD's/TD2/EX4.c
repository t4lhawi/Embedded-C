// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO for PIC (PIC18F)

void main() {
    // Bus d’entrée Ib : PORTA
    unsigned char Ib = 0;
    TRISA = 0xFF;
    ANSELA = 0xFF;
    // Bus d’entrée Ih : PORTB
    unsigned char Ih = 0;
    TRISB = 0xFF;
    ANSELB = 0xFF;
    
    // Bus de sortie LED B : PORTC
    TRISC = 0;
    LATC = 0;

    // Bus de sortie LED H : PORTD
    TRISD = 0;
    LATD = 0;

    // Bus de sortie LED E : PORTE
    TRISE = 0;
    LATE = 0;


    while(1){
        if(PORTA < 30){
            Ib = 1;
        } 
        if(PORTB > 250){
            Ih = 1;
        }

        // Niveau normal (30 cm <= niveau <= 250 cm)
        if (Ib == 0 && Ih == 0) {
            LATC = 0; // LED B
            LATD = 0; // LED H
            LATE = 0; // LED E
        } 
        // Niveau faible (< 30 cm)
        else if (Ib == 1 && Ih == 0) {
            LATC = 0xFF; // LED B
            LATD = 0; // LED H
            LATE = 0; // LED E
        }
        // Niveau eleve (> 250 cm)
        else if (Ib == 0 && Ih == 1) {
            LATC = 0; // LED B
            LATD = 0xFF; // LED H
            LATE = 0; // LED E
        }
        // Cas incoherent
        else if (Ib == 1 && Ih == 1) {
            LATC = 0; // LED B
            LATD = 0; // LED H
            LATE = 0xFF; // LED E
        }
    }
}