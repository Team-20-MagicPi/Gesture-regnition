# build

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

**Gesture_Initialization.py** is used to initialize the registor of the sensor, so always remember to run it before the main program.
