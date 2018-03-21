# Building

Build instructions are kept for reference, since I forget each time I'm building
a new firmware.

## Setup QMK
```
cd qmk_firmware
./util/qmk_install.sh
```


## Build layout
```
make ergodox_ez:philip_svorak
```

A hexfile will (hopefully) be created, and the output of the above command
should tell you where. For instance:
```
...
Creating load file for flashing: .build/ergodox_ez_philip_svorak.hex
...
```


If your layout doesn't work, try with the default first (to make sure that QMK
works):

```
 make ergodox_ez:default
```

## Flash Keyboard
Start teensy loader: https://www.pjrc.com/teensy/loader.html

Drag the .hex file to the Teensy window.

At this point I press the green "Auto" button in Teensy loader, but not sure if it is 100%
needed.

Enter a paperclip into the reset hole in the top right corner.
Teensy loader should download the firmware to the keyboard. Done!
