// SPDX-License-Identifier: GPL-2.0-only
/*
 *  gpioctl.c
 *
 *  Copyright (C) 2020 qmail_ljw_qmail@foxmail.com 
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_gpio(int argc, char *argv[]);
int write_gpio(int argc, char *argv[]);

int (*gpio_ops[])(int argc, char *argv[]) = {
  read_gpio,
  write_gpio,
};

int main(int argc, char *argv[])
{
  if(argc < 3 || argc > 4)
    return 1;

  return gpio_ops[argc-3](argc, argv);
}


int write_gpio(int argc, char *argv[])
{
  char *port = argv[1];
  char *pin = argv[2];
  char *val = argv[3];
  int i = 0;
  int version = 0;
  int pinData = 0;
  int portName = 0;
  int pinNumber = 0;

  for(i=0; *port && *pin && *val; i++)
  {
    while(!isdigit(*port) && *port != '\0') {port++;}
    while(!isdigit(*pin) && *pin != '\0') {pin++;}
    while(!isdigit(*val) && *val != '\0') {val++;}
	
    if(*port && *pin && *val)
    {
      portName = atoi(port);
      pinNumber = atoi(pin);
      pinData = atoi(val);
      if(1 <= portName && portName <= 8 && 0 <= pinNumber && pinNumber <= 31 && 0 <= pinData && pinData <= 1)
      {
        fprintf(stderr, "gpio%u_%u, val:%u\n", portName, pinNumber, pinData);
        //gpio_output_data(portName, pinNumber, pinData);
      }
      else
      {
        fprintf(stderr, "invalid gpio or val:gpio%u_%u, val:%u\n", portName, pinNumber, pinData);
      }

    }
    
    while(isdigit(*port) && *port != '\0') {port++;}
    while(isdigit(*pin) && *pin != '\0') {pin++;}
    while(isdigit(*val) && *val != '\0') {val++;}
	
  }
  return 0;
}
int read_gpio(int argc, char *argv[])
{
  char *port = argv[1];
  char *pin = argv[2];
  int i = 0;
  int gpio_value = 0;
  int pinData = 0;
  int portName = 0;
  int pinNumber = 0;

  for(i=0; *port && *pin; i++)
  {
    while(!isdigit(*port) && *port != '\0') {port++;}
    while(!isdigit(*pin) && *pin != '\0') {pin++;}
	
    if(*port && *pin)
    {
      portName = atoi(port);
      pinNumber = atoi(pin);
      if(1 <= portName && portName <= 8 && 0 <= pinNumber && pinNumber <= 31)
      {
        fprintf(stderr, "gpio%d_%d\n", portName, pinNumber);
        //gpio_input_data(portName, pinNumber, &pinData);
      }
      else
      {
        fprintf(stderr, "invalid gpio:gpio%d_%d\n", portName, pinNumber);
      }

    }
    
    while(isdigit(*port) && *port != '\0') {port++;}
    while(isdigit(*pin) && *pin != '\0') {pin++;}
	
  }
  printf("%d\n", gpio_value);
  return gpio_value&0xff;
}

