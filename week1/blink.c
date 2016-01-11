#include <msp430.h>

int main() {
  
  // Constants
  const int PROP_DELAY = 500000;
  
  // Setup
  WDTCTL = WDTPW | WDTHOLD; // Hold the watchdog timer
  P1DIR |= BIT0; // Set the first P1 port as an output
  
  // Loop forever
  while (1) {
    
    // Blinking magic
    P1OUT ^= BIT0; // Toggle the first output with XOR
    __delay_cycles(PROP_DELAY); // Delay for circuit propagation
    
  }
  
  // Code will never reach here... so sad
  return 0;
  
}
