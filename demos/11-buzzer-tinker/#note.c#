#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
// TODO

// Refactor note function to support multiple octaves based on note constants ex: A = 440 A5 = 880






// takes the frequecy in hertz of a note and returns the appropriate buzzer set period for that note
int noteHelper(float frequency){
  return (2000000/frequency);
}

int note(char letter){
  switch (letter){
  case 'C':
    return noteHelper(261.63);
    break;
  case 'D':
    return noteHelper(293.66);
    break;
  case 'E':
    return noteHelper(329.63);
    break;
  case 'F':
    return noteHelper(349.23);
    break;
  case 'G':
    return noteHelper(392);
    break;
  case 'A':
    return noteHelper(440);
    break;
  case 'B':
    return noteHelper(493.88);
    break;
  case '5':
    return noteHelper(261.63 * 2);
    break;
  }
  return noteHelper(220);
}
