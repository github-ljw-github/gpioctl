#!/bin/bash

function test_init
{
  gcc gpioctl.c
}

function test_read_gpio
{
  GPIO_PortName="1|2|7 |2"
  GPIO_PinNumbr="2|3|23|25"
  ./a.out "$GPIO_PortName" "$GPIO_PinNumbr"
}

function test_write_gpio
{
  GPIO_PortName="1|2|7 |2"
  GPIO_PinNumbr="2|3|23|25"
  GPIO_PinValue="0|1|1 |0 "
  ./a.out "$GPIO_PortName" "$GPIO_PinNumbr" "$GPIO_PinValue"
}

test_init
test_read_gpio
test_write_gpio
