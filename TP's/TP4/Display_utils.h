// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
// mikroC PRO (Compiler) | Microcontrôleurs PIC18F (Microchip)

unsigned short mask(unsigned short num) {
    switch (num) {
        case 0 : return 0x3F; // 0b00111111
        case 1 : return 0x06; // 0b00000110
        case 2 : return 0x5B; // 0b01011011
        case 3 : return 0x4F; // 0b01001111
        case 4 : return 0x66; // 0b01100110
        case 5 : return 0x6D; // 0b01101101
        case 6 : return 0x7D; // 0b01111101
        case 7 : return 0x07; // 0b00000111
        case 8 : return 0x7F; // 0b01111111
        case 9 : return 0x6F; // 0b01101111
    }
}