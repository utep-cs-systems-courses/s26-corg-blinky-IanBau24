#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
int noteHelper(float frequency);
int note(char letter);
#endif // included
