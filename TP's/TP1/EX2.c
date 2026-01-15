// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

unsigned char *R0;
unsigned char i;

//---------------------| Q1 |---------------------//
void main() {
    R0 = (unsigned char *)0x20;  // Adresse de départ RAM

    for(i = 0; i < 10; i++) {
        *R0 = 0x20;              // Écriture de 0x20
        R0++;                    // Case suivante
    }
}


//---------------------| Q2 |---------------------//
void main() {
    unsigned char *p;
    unsigned char val = 0;

    p = (unsigned char *)0x90;   // adresse RAM de départ

    while(val <= 10) {
        *p = val;
        p++;
        val++;
    }
}
