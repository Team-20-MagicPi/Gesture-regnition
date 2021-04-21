#ifndef __PAJ7620_CPP__
#define __PAJ7620_CPP__

#include "Pi_PAJ7620.h"
#include <iostream>


Pi_PAJ7620::Pi_PAJ7620() {
  
}

bool Pi_PAJ7620::begin() {

  int error, fd, buf;

  fd=wiringPiI2CSetup(PAJ7620_ADDR);
  if (fd < 0) {
                std::cout << "Error setup I2C device ";
                exit(1);
        }

  fd=wiringPiI2CSetup(PAJ7620_ADDR);
  error = wiringPiI2CWrite(fd,0xEF);
  error = wiringPiI2CWrite(fd,0x01);  

  if (error != 0) {
    // IOXHOP_PAJ7620_DEBUG("Switch to bank 1 fail");
    std::cout << "Switch to bank 1 fail";
    return false;
  }

  fd=wiringPiI2CSetup(PAJ7620_ADDR);
  error = wiringPiI2CWrite(fd,0x72);
  error = wiringPiI2CWrite(fd,0x01);  


  if (error != 0) {
    // IOXHOP_PAJ7620_DEBUG("Config Enable/Disable register fail");
    std::cout << "Config Enable/Disable register fail";
    return false;
  }

  fd=wiringPiI2CSetup(PAJ7620_ADDR);
  error = wiringPiI2CWrite(fd,0xEF);
  error = wiringPiI2CWrite(fd,0x00);  

  if (error != 0) {
    std::cout << "Switch to bank 0 fail";
    return false;
  }
}

int Pi_PAJ7620::getGesture() {
  int error, fd;

  fd=wiringPiI2CSetup(PAJ7620_ADDR);
  error = wiringPiI2CWrite(fd,0x43);

  if (error != 0) {
    // IOXHOP_PAJ7620_DEBUG("Write offset register to 0x43 fail");
    std::cout << "Write offset register to 0x43 fail";
    return -1;
  }

  int data = 0;
  data=wiringPiI2CReadReg8(fd,0x43);
  //data |= wiringPiI2CReadReg8(fd,0x44);


  return data;
}

Pi_PAJ7620 PAJ7620;

#endif
