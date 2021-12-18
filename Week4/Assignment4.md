# Assignment 4: Blinky is as Blinky Does

<img src="blinky.gif">

I did this project in stages. First simply making the LED blink, then toggling the LED inside an interrupt function triggered by a push button, and finally adding debouncing. Most of my time was spent learning the workings of the STM32Cube IDE.

The ST32WBMMG-DK board has no built-in LED, so I added a standard LED and current limiting resistor to GPIO pin 11,and configured pin 11 as a GPIO output. 

The ST32WBMMG-DK has two user push buttons, on pins PB12 and PB13. I selected Pin 12, configured with a pull-up resistor to trigger an interrupt on falling edge detection.

The final, debounced code configuration is entirely in main.c. To allow debouncing, the LED pin state is toggled in main(void)in response to a global flag, button_flag, defined in the Private Variables secition shown below:

The value of button_flag is set when the interrupt processing function, EXTI15_10_IRQHandler(void), calls a callback function, HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin). Since HAL_GPIO_EXTI_Callback is initially defined with the “_weak” keyword, and can be overridden with a new definition in main.c. 

I didn’t come up with this solution by myself. It took a fair amount of Googling to figure out how to use interrupts to set a flag variable, but I now have a much better understanding of the sequence of functions called  when a GPIO interrupt is processed.

Timer TIM16 is configured to track time for the debouncing process. It is a 16 bit timer not used for any other process. I’m still a bit confused by the prescaler settings, but I followed the directions in a Shawn Hymel video to try to figure it all out. From the Clock Configuration tab in STM32Cube, it appears the default clock speed is 4 MHz. I set the prescaler to 8000, for a clock frequency of 500 Hz or a clock rate of 2 ms/tick. I debounced over a period of 10 ticks = 20 ms, which may be short, but seems to work fine in practice.
