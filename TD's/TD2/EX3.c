// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO for PIC (PIC18F)

void main() {
    // Bus d’entrée : PORTA
    TRISA = 0xFF;
    ANSELA = 0;

    // Bus de sortie : PORTB
    TRISB = 0;
    LATB = 0;

    while(1){
        switch(PORTA){
            case 0:
                LATB = 0b11000011;
                delay_ms(1000);
                LATB = ~LATB;
                delay_ms(1000);
                break;
            case 1:
                LATB = 0b10011001;
                delay_ms(1000);
                LATB = ~LATB;
                delay_ms(1000);
                break;
            case 2:
                LATB = 0b10101010;
                delay_ms(1000);
                LATB = ~LATB;
                delay_ms(1000);
                break;
            case 3:
                LATB = 0b11111111;
                delay_ms(1000);
                LATB = ~LATB;
                delay_ms(1000);
                break;
            default:
                LATB = 0;
                break;
        }
    }
}

// Version avec les Tableaux
void main(){
    char Entree[4] = {0, 1, 2, 3};
    char Sortie[4] = {0b11000011, 0b10011001, 0b10101010, 0b11111111};
    
    while(1){
        if(PORTA == Entree[PORTA]){
            LATB = Sortie[PORTA];
            delay_ms(1000);
            LATB = ~LATB;
            delay_ms(1000);
        }
    }
}