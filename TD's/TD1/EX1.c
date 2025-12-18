// Nom : Mohamed Talhaoui
// Filière : GSEIR3 (S1) | 2025/2026
#include <stdio.h>

int main() {
    signed char p1 = 0;

    // Q1
    p1 |= (1 << 2);

    // Q2
    p1 |= (1 << 3) | (1 << 6);

    // Q3
    p1 &= ~(1 << 0);

    // Q4
    p1 &= ~((1 << 4) | (1 << 5));

    // Q5
    p1 ^= (1 << 3);

    // Q6
    p1 |= (1 << 2);
    p1 &= ~(1 << 0);

    // Q7
    p1 |= (1 << 0) | (1 << 7);
    p1 &= ~((1 << 3) | (1 << 4));

    return 0;
}
