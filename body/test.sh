#!/bin/bash

function test_init
{
  gcc gpioctl.c
}

function test_read_gpio
{
  echo "read: test case 1"
  GPIO_PortName="1|2|7 |2"
  GPIO_PinNumbr="2|3|23|25"
  ./a.out "$GPIO_PortName" "$GPIO_PinNumbr"


  echo "read: test case 2"
  ./a.out "gpio1|gpio2|gpio7|gpio7"\
          "pin2 |pin3 |pin23|pin25"\

  echo "read: test case 3"
  ./a.out 1,2,7,7  2,3,23,25
}

function test_write_gpio
{
  echo "write: test case 1"
  GPIO_PortName="1|2|7 |2"
  GPIO_PinNumbr="2|3|23|25"
  GPIO_PinValue="0|1|1 |0 "
  ./a.out "$GPIO_PortName" "$GPIO_PinNumbr" "$GPIO_PinValue"


  echo "write: test case 2"
  ./a.out "gpio1|gpio2|gpio7|gpio7"\
          "pin2 |pin3 |pin23|pin25"\
          "val0 |val1 |val0 |val1"\

  echo "write: test case 3"
  ./a.out 2,2,7,7  2,3,23,25  0,1,0,1
}

test_init
test_read_gpio
test_write_gpio
