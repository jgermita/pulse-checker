# pulse-checker
simple arduino hardware utility to inspect RC PWM/PPM signals.


# Hardware setup

This should be compatible with any Arduino compatible board. I'm currently running it on an Arduino Mega since I didn't have anything smaller, but there's no reason it won't work on most other Arduino compatibles.

The only truly required hardware setup is wiring an RC PWM/PPM signal into pin 8, or some other pin of your choice.

In order to make it easier to use as a standalone device, I've added 3 feedback LEDs, but they're not required for operation.

For detailed inspection, you can open up a serial monitor of your choice to see the exact pulse timings as they come in. 
