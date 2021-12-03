#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "udoo_gpio.h"


bool gpio_export(int pin)
{
  file = open("/sys/class/gpio/export", O_WRONLY);
  if (file == -1)
  {
    printf("Error at opening the export file\n");
    return false;
  }
  snprintf(pinIdBuffer, sizeof(pinIdBuffer), "%d", pin);
  if(write(file,pinIdBuffer,sizeof(pinIdBuffer)) == -1)
  {
    close(file);
    return false;
  }
  sleep(1);
  close(file);
  return true;
}

bool gpio_unexport(int pin)
{
  file = open("/sys/class/gpio/unexport", O_WRONLY);
  if (file == -1)
  {
    printf("Error at opening the unexport file\n");
    return false;
  }
  snprintf(pinIdBuffer, sizeof(pinIdBuffer), "%d", pin);
  if(write(file,pinIdBuffer,sizeof(pinIdBuffer)) == -1)
  {
    close(file);
    return false;
  }
  close(file);
  return true;
}

bool gpio_mode(int pin, int mode)
{
  snprintf(pinPathBuffer, 35, "/sys/class/gpio/gpio%d/direction", pin);
  file = open(pinPathBuffer, O_WRONLY);
  if(file == -1)
  {
    printf("Error at opening the direction file: %s\n",pinPathBuffer);
    return false;
  }
  else if (write(file, ((mode == INPUT)?"in":"out"), sizeof(pinIdBuffer)) == -1)
  {
    close(file);
    printf("Error at set the mode of pin%d\n",pin);
    return false;
  }
  close(file);
  return true;
}

bool gpio_write(int pin, int value)
{
  snprintf(pinPathBuffer, 35, "/sys/class/gpio/gpio%d/value",pin);
  file = open(pinPathBuffer,O_WRONLY);
  if(file == -1)
  {
    printf("Error at opening the value file: %s\n",pinPathBuffer);
  }
  else if (write(file, ((value == HIGH)?"1":"0"), 1) == -1)
  {
    printf("Error at writing the pin%d\n",pin);
    close(file);
    return false;
  }
}
int gpio_read(int pin)
{
  char value[3];
  snprintf(pinPathBuffer, 35, "/sys/class/gpio/gpio%d/value",pin);
  file = open(pinPathBuffer,O_RDONLY);
  if(file == -1)
  {
    printf("Error at opening the value file: %s\n",pinPathBuffer);
  }
  else if (read(file, value, sizeof(pinIdBuffer)) == -1)
  {
    printf("Error at reading the pin%d\n",pin);
    close(file);
    return false;
  }
  close(file);
  return atoi(value);
}
