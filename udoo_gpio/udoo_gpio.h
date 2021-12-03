#include <stdbool.h>

#ifndef UDOO_GPIO_H
#define UDOO_GPIO_H

#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1

#define PIN16 106
#define PIN17 107
#define PIN18 180
#define PIN19 181
#define PIN20 172
#define PIN21 173
#define PIN22 182
#define PIN23 124
#define PIN24 25
#define PIN25 22
#define PIN26 14
#define PIN27 15
#define PIN28 16
#define PIN29 17
#define PIN30 18
#define PIN31 19
#define PIN32 20
#define PIN33 21
#define PIN34 203
#define PIN35 202
#define PIN36 177
#define PIN37 167
#define PIN38 175
#define PIN39 174
#define PIN40 119
#define PIN41 124
#define PIN42 127
#define PIN43 116
#define PIN44 7
#define PIN45 6
#define PIN46 5
#define PIN47 4


int file;
char pinIdBuffer[4];
char pinPathBuffer[35];


bool gpio_export(int pin);
bool gpio_unexport(int pin);
bool gpio_mode(int pin, int mode);
bool gpio_write(int pin, int value);
int gpio_read(int pin);

#endif
