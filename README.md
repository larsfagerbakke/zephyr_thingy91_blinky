# zephyr_thingy91_blinky

This repository contains a small (minimal* with logging) sample of how to blink the [Nordic Semiconductor Thingy91's](https://www.nordicsemi.com/Products/Development-hardware/Nordic-Thingy-91) included leds ... I know, groundbreaking stuff here! :boom:

\* I have a SEGGER J-Link so thats why the extra configs are there. CONFIG_FPU=y is not needed (printing floats in debug), but part of my included configs.

## Init

The best approach to use this sample is to use Visual Studio nRF extension and create a new project and drop the sample code in there. This will set up the board you are working with and such, given it supports the leds in the board definition file.

## Led handler

Have a look at led_handler. It offers the possibility to both turn on and of a led (toggle) but also toggle a color. Useful if you want to give visual feedback when fetching sensor values, making http requests and such.

### Like?

Give my project a star! =) Want to use it? Feel free! Have suggestions? Make a PR!