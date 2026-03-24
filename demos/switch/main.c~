//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS; // setup led related io pins to out
  P1OUT &= ~LED_GREEN; // turn off green led bit
  P1OUT |= LED_RED; // turn on red led bit

  or_sr(0x18);		/* CPU off, GIE on */
}
