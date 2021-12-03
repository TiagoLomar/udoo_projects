#include <stdlib.h>
#include <unistd.h>
#include "../udoo_gpio/udoo_gpio.c"

int main(int argc, char const *argv[]) {
  gpio_export(PIN39);
  //printf("PIN %d\n", PIN39);
  //sleep(1);
  gpio_mode(PIN39,OUTPUT);
  gpio_write(PIN39,HIGH);
  sleep(2);
  gpio_write(PIN39,LOW);
  sleep(2);
  gpio_write(PIN39,HIGH);
  sleep(2);
  gpio_write(PIN39,LOW);
  gpio_unexport(PIN39);
  return 0;
}
