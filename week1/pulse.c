// Brandon M. Kelley
// January 5, 2016
//
// Pulsing LED

#include <msp430.h>

int main() {
  
  // Constants
  const int PERIOD = 100;
  
  // Variables
  int freq = 2;
  int delta = 1;
  int i = 1;
  
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR |= BIT0;
  
  // Loop forever
  while (1) {
    
    // Create PWM light according to freq
    for (; i < PERIOD; i++) {
      if (i % freq == 0) {
        P1OUT |= BIT0;
      } else {
        P1OUT &= ~BIT0;
      }
      __delay_cycles(100);
    }
    
    // Change direction of freq change
    if (freq < 2 || freq > 8) {
      delta *= -1;
    }
    
    // Change freq
    freq += delta;
    
  }
  
  return 0;
  
}
