# Gestures &  Music Player Controller

It detects 3D gesture with Gesture Sensor(PAJ7620u2)，and controls  a music player

## REQUIREMENT

- 1 x Gesture Sensor (or PAJ7620u2 compatible)
- 1 x 4pin Female jumper cable
- 1 x small stereo

### Pin Connect (I2C 1)

```
Pi4B  <---->Gesture Sensor 
------------------------------
+5V--4<---->VCC
GND--6<---->GND
SDA--3<---->SDA
SCL--5<---->SCL
```



### Install H/W

- Go to Raspberry config program, set I2C (I2C_1) as enabled. Then shutdown.
- Connect Sensor and RPI with cable. Connect  stereo to RPI. Then power on.
- Check `sudo i2cdetect -y 1` or install it.

```
sudo apt-get update
sudo apt-get install i2c-tools
sudo i2cdetect -y 1
```

- After installation rebooting might be needed.
- Try again `sudo i2cdetect -y 1`, if you can see `73` on the matrix of result, H/W is installed properly.

When you see the followings,  I2C  works.

```
pi@raspberrypi:~$ sudo i2cdetect -y  1 
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- 73 -- -- -- -- 
```

### About the chip
* The chip's registor should be set properly everytime it reboots.
* You can find the default settings of the registor here in the chip's datasheet:
     https://www.alldatasheet.com/view.jsp?Searchword=Paj7620u2%20datasheet&gclid=Cj0KCQjwvYSEBhDjARIsAJMn0ljzSpP8bfbRnMBM7X_stNOUmwhnCTGYhqRbmgagZv9Nr4d21ru-oBYaAqqYEALw_wcB


## Installation of Module

### wiringPi

**WiringPi** is a **PIN** based GPIO access library written in C. The installation guide can be found below:

http://wiringpi.com/download-and-install/

### build

```
python Gesture_Initialization.py
g++ paj7620_test.cpp Pi_PAJ7620.cpp -lwiringPi  -o a.out
```

or using cmake:

```
python Gesture_Initialization.py
mkdir build
cd build
cmake ..
make
./Gesture_main
```






## Configuration the module

### Prepared Gestures

You can modify, remove or create these gestures 
- **LEFT** : previous one
- **RIGHT** : next one
- **UP** : increase volume
- **DOWN**: decrease volume
- **CLOCKWISE** : play 
- **COUNTER CLOCKWISE** : stop

## Contributing

@[JiajianYou](https://github.com/JiajianYou)

@[Touru97](https://github.com/Touru97)

@[Sei2112](https://github.com/Sei2112)

