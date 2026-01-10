// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

void main() {
    TRISA |= 0b00000010; // RA1 en entrée
    ANSELA &= 0b11111101;
    
    TRISB = 0;
    LATB = 0;

    while(1){
        if(( (PORTA >> 1) & 1 ) == 0){
            LATB = 0x0F;
        }
        else {
            LATB = 0xF0;
        }
    }
}