//Alternate LEDsA from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}


void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  static int interruptCount = 0; // makes a static variable outisde of the function, only accessible in this function, global to be accessible in all functions
  interruptCount ++;
  if (interruptCount % 250 == 0) P1OUT |= LED_GREEN; // every second set green led on
  if(interruptCount % 500 == 0){ // every two seconds set red led off  and overwrite whatever green is to be off
    P1OUT &= ~LED_GREEN; // green will be off every other second
    P1OUT &= ~LED_RED; // two seconds after red will be set to off
  }
  if (interruptCount == 1000){ // at four seconds, turn red led back on and reset count
    P1OUT |= LED_RED; // four seconds after red will be set to on
    interruptCount = 0;
  }
} 
