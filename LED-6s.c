// Custom delay function (variable ms)
void myDelay_ms(unsigned int time_ms) {
    unsigned int i;
    for(i = 0; i < time_ms; i++) {
        Delay_ms(1);   // Built-in mikroC constant delay
    }
}

void main() {
    unsigned int on_time, off_time;

    TRISB = 0x00;   // PORTB as output
    PORTB = 0x00;   // All pins OFF initially

    while(1) {
        // Cycle: ON time increases 1 ? 5 sec, OFF time decreases 5 ? 1 sec
        for(on_time = 1; on_time <= 5; on_time++) {
            off_time = 6 - on_time;   // Keep total cycle time = 6 sec

            // LED ON
            PORTB.F0 = 1;             // Turn ON LED at RB0
            myDelay_ms(on_time * 1000); // Delay ON_time seconds

            // LED OFF
            PORTB.F0 = 0;             // Turn OFF LED
            myDelay_ms(off_time * 1000); // Delay OFF_time seconds
        }
    }
}
