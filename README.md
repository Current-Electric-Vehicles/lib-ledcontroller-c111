# LED Controller by Current Electric Vehicles (C111)
This repository contains driver code for use with the Current Electric Vehicles LED Controller board.

## Quickstart
Add the dependency to your platformio.ini:

```
lib_deps =
    LEDController=https://github.com/Current-Electric-Vehicles/lib-ledcontroller-c111.git
```

Use the controller in your code:

```cpp

#include <LED_Controller.h>

LEDController controller;

void setup() {
  controller.initialize();

  controller.setCanTerminated(true);

  controller.enablePSU1(true);
  controller.enablePSU2(true);

  controller.attachInputInterrupt(C111_USER_INPUT_1, CHANGE, []() {
    ...
  });
}

void loop() {
    ...
}

```

## PlatformIO board.json file
To install the board.json file for this board, clone the repository and run `install-board.py` script located in the root of the project.

You will then be able to use the board in your platformio projects as so:

```ini

[platformio]
default_envs = default

[env]
board = c111-ledcontroller
lib_deps =
    LEDController=https://github.com/Current-Electric-Vehicles/lib-ledcontroller-c111.git
```

However this is optional, and the `esp32dev` board that is packaged with platformio works as well.
