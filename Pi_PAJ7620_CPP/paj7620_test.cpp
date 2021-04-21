#include <iostream>
// #include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pi_PAJ7620.h"
#include "unistd.h"
#include "string.h"
// using namespace std;

int main() {
  
  wiringPiSetup();
  int flag=1;
  system("amixer set Headphone -- -3800");
  int play=1;
  int volumnlist[]={-10239,-5000,-3800,-2800,-2000};
  int volumn=2;
  //system("aplay 1.wav");
  while(1)
  {
    if(flag==1) {
      int ges= PAJ7620.getGesture();
      flag++;
      }
    else{
    int gesture = PAJ7620.getGesture();
    //std::cout<<gesture<<std::endl;
    if (gesture != -1) {
      /*if(gesture==0){
        std::cout<<"NO GESTRUE!"<<std::endl;
        }*/
      if (gesture & GESTURE_WAVE) {
        std::cout << "WAVE"<<std::endl;
      }
      if (gesture & GESTURE_COUNTER_CLOCKWISE) {
        std::cout << "Counter Clockwise"<<std::endl;
        system("kill $(ps aux | grep 'aplay' | awk '{print $2}')");
      }
      if (gesture & GESTURE_CLOCKWISE) {
        std::cout << "Clockwise"<<std::endl;
        system("kill $(ps aux | grep 'aplay' | awk '{print $2}')");
        system("aplay 1.wav &");
        
      }
      if (gesture & GESTURE_BACKWORD) {
        std::cout << "Backward"<<std::endl;
      }
      if (gesture & GESTURE_FORWARD) {
        std::cout << "Forward"<<std::endl;
      }
      if (gesture & GESTURE_RIGHT) {
        std::cout << "Right"<<std::endl;
        play+=1;
        char buf[80];
        
        if(play>5){
          play=5;
          system("kill $(ps aux | grep 'aplay' | awk '{print $2}')");
          sprintf(buf,"aplay %d.wav &",play);
          system(buf);
          }
        else
        {
          system("kill $(ps aux | grep 'aplay' | awk '{print $2}')");
          sprintf(buf,"aplay %d.wav &",play);
          system(buf);
          }
        
      }
      if (gesture & GESTURE_LEFT) {
        std::cout << "Left"<<std::endl;
        play-=1;
        char buf[80];
       
        
        if(play<1){
          play=1;
          system("kill $(ps aux | grep 'aplay' | awk '{print $2}')");
          sprintf(buf,"aplay %d.wav &",play);
          system(buf);
          }
        else
        {
          system("kill $(ps aux | grep 'aplay' | awk '{print $2}')");
          sprintf(buf,"aplay %d.wav &",play);
          system(buf);
          }
        
      }
      if (gesture & GESTURE_DOWN) {
        std::cout << "Down"<<std::endl;
        volumn-=1;
        char buf[80];
        
        if(volumn<0)
        {
            volumn=0;
            
            sprintf(buf,"amixer set Headphone -- %d",volumnlist[volumn]);
            system(buf);
          }
          else
          {
            
            sprintf(buf,"amixer set Headphone -- %d",volumnlist[volumn]);
            system(buf);
            }
        
        
      }
      if (gesture & GESTURE_UP) {
        std::cout << "Up"<<std::endl;
        volumn+=1;
        char buf[80];
        
        if(volumn>4)
        {
            volumn=4;
            
            sprintf(buf,"amixer set Headphone -- %d",volumnlist[volumn]);
            system(buf);
          }
          else
          {
            
            sprintf(buf,"amixer set Headphone -- %d",volumnlist[volumn]);
            system(buf);
            }
        
      }
    } else {
      std::cout << "PAJ7620 communication fail";
    }
    delay(100);
  }
}
}
