char counter;
void main() {
    TRISA = 0x00; LATA = 0x00;
    TRISB = 0x00; LATB = 0x00;
    TRISC = 0x00; LATC = 0x00;
    TRISD = 0x00; LATD = 0x00;
    TRISE = 0x00; LATE = 0x00;

    while (1) {
        for (counter=0; counter<8; counter++) {
            LATA |= 1 << counter;
            LATB |= 1 << counter;
            LATC |= 1 << counter;
            LATD |= 1 << counter;
            LATE |= 1 << counter;
            delay_ms(200);
        }

        for (counter=0; counter<8; counter++) {
            LATA &= ~(1 << counter);
            LATB &= ~(1 << counter);
            LATC &= ~(1 << counter);
            LATD &= ~(1 << counter);
            LATE &= ~(1 << counter);
            delay_ms(200);
        }
    }
}