// Brandon M. Kelley
// January 5, 2016
//
// Dim LED

#include <msp430.h>

int main() {
  
  // Constants
  const int FREQ = 20;
  
  // Variables
  int i = 0;
  
  // Setup
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR |= BIT0;
  
  // Loop forever
  while (1) {
    
    // Spend one cycle with output high
    P1OUT |= BIT0;
    __delay_cycles(100);
    
    // Spend remaining cycles with output low
    P1OUT &= ~BIT0;
    while (++i < FREQ) {
      __delay_cycles(100);
    }
    
  }
  
  return 0;
  
}
