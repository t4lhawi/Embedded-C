// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO for PIC (PIC18F)

unsigned char *R0;

void main() {
    R0 = (unsigned char *)0x20;  // Adresse RAM
    *R0 = 'A';                   // Copier 'A' (ASCII 41h)
}
