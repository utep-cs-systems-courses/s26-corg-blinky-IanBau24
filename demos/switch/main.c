//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

#define SW1 BIT3 // switch 1 is defines as p1.3
#define SWITCHES SW1 // switches is whatever sw1 is, only on result since only one switch

int main(void) {
  configureClocks(); // idk yet

  P1DIR |= LEDS; // wire the leds to p1dir
  P1OUT &= ~LED_RED; // set leds
  P1OUT |= LED_GREEN;

  P1REN |= SWITCHES; // enable resistors to get input from switches
  P1IE |= SWITCHES; // enable interrupt from switches
  P1OUT |= SWITCHES; // pull up for switches
  P1DIR &= ~SWITCHES; // set switches' bits for input to leds

  or_sr(0x18); // CPU off GIE on
}


void switch_interrupt_handler(){
  char p1 = P1IN; // switch is in p1

  // update interrupt so it accurately detects changes to buttons
  P1IES |= (p1 & SWITCHES); // if switch is up, p1ies is down
  P1IES &= (p1 | ~SWITCHES); // if switch is down p1ies is up

  if(p1 & SW1){// if button is pressed p1 and sw1 and to a 1
    P1OUT ^= LED_GREEN; // toggle led using x or
    P1OUT ^= LED_RED;
  }
  else{
    P1OUT ^= LED_RED;
    P1OUT ^= LED_GREEN;
  }
}

void __interrupt_vec(PORT1_VECTOR) Port_1(){ // swtich on P1 (S2)
  if (P1IFG & SWITCHES) { // did a button (only on this board) cause this interrupt
    P1IFG &= ~SWITCHES; // if so clear all interrupts, (reset p1fg using switches)
    switch_interrupt_handler(); // call handler to see what to do with interrupt
  }
}
