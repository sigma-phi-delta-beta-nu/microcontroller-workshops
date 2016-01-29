// Brandon M. Kelley
// January 26, 2016
//
// Display 'A', 'B', 'C', and 'D' sequentially

/**
 * P1OUT Mapping to Seven Segment Display
 **
 *      BIT7
 *       _
 * BIT1 |_| BIT6
 * BIT2 |_| BIT5
 *      BIT3
 *
 * *
 * Hyphen is BIT0
 * Decimal is BIT4
 */

#include <msp430.h>

int main() {
  
  // Define each letter as binary output
  const int CC_A = BIT3 | BIT4;
  const int CC_B = BIT4 | BIT6 | BIT7;
  const int CC_C = 0xF2;
  const int CC_D = BIT1 | BIT4 | BIT7;
  
  // Make letters loopable
  const int OUTPUTS = { CC_A, CC_B, CC_C, CC_D };
  const int NUM_OUTPUTS = 4;
  
  // Set up
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = 0xFF;

  // Loop
  while (1) {
    
    // Make an index for looping
    const int *index = OUTPUTS;

    // Loop through outputs
    while (index < OUTPUTS + NUM_OUTPUTS) {
      
      // Display and delay before continuing to the next letter
      P1OUT = *(index++);
      __delay_cycles(500000);
      
    }
    
  }
  
  return 0;
  
}
