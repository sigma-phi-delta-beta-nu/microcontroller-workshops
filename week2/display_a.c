// Brandon M. Kelley
// January 26, 2016
//
// Display 'A'

/**
 * P1OUT Mapping to Seven Segment Display
 **
 *      BIT7
 *       _
 * BIT1 |_| BIT6
 * BIT2 |_| BIT5
 *      BIT3
 *
 ** 
 * Hyphen is BIT0
 * Decimal is BIT4
 */

#include <msp430.h>

int main() {
  
  // Define 'A' as a binary output
  const int CC_A = BIT3 | BIT4;

  // Set all P1 bits as outputs
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = 0xFF;

  // Set P1 output bits to the letter 'A'
  P1OUT = CC_A;

  // Loop forever!
  while (1) {}

  return 0;
  
}
