#include "pico/stdlib.h"

// GPIO 11 (Green led)
#define pin_led 11

// Time in ms
#define dot_time 200
#define dash_time 800
#define gap_time 125
#define letter_time 250
#define cycle_time 3000

// Functions prototype
void dot_blink();
void dash_blink();
void repetition(void (*blink)(), int times);


// Main function responsible for the SOS morse code
int main(){
  gpio_init(pin_led);
  gpio_set_dir(pin_led, GPIO_OUT);

  while(true){
    repetition(dot_blink, 3);
    sleep_ms(letter_time);

    repetition(dash_blink, 3);
    sleep_ms(letter_time);

    repetition(dot_blink, 3);
    sleep_ms(cycle_time);
  }

}

void dot_blink(){
  gpio_put(pin_led, true);
  sleep_ms(dot_time);
  gpio_put(pin_led, false);
  sleep_ms(gap_time);
}

void dash_blink(){
  gpio_put(pin_led, true);
  sleep_ms(dash_time);
  gpio_put(pin_led, false);
  sleep_ms(gap_time);
}

void repetition(void (*blink)(), int times){
  for (int i = 0; i < times; i++)
    blink();
}