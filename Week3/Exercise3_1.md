# Exercise 3.1

## Assignment: Investigate Project Board
Look at the documents for the board you are condisering for your final project ([or any ST Discovery Board](https://www.st.com/en/evaluation-tools/stm32-discovery-kits.html#products)), 
draw the hardware block diagram for the board. For peripherals, note the communication paths (SPI, I2C, etc).

Look at the datasheet for the processor and other documents. Answer these questions:
- What kind of processor is it
- How much Flash and RAM does it have? Any other memory types?
- Does it have any special peripherals? (List 3-5 that you noted as being interesting)
- Does it have a floating point unit?
- If it has an ADC, what are the features?

Look at one application note for this processor.

## Board Investigation: STM32WB5MM-DK Discovery Kit

- The processor is an STM32WB5MMGH6
- There is 1 Mbyte flash and 256 Kbytes of SRAM. There is also an 128-Mbit Quad-SPI NOR Flash memory. I do not understand how it differes from typical flash or what the extra descriptors mean (Quad-SPI, NOR), but will investigate to find out
- There are a large number of peripherals built into the discovery board, including:
-- 0.96-in 128x64 OLED display
-- temperature sensor
-- accelerometer/gyroscope
-- time of flight/gesture detection sensor (I have an interest in AI/gesture detection, and will be attempting to see how this feature works)
-- digital microphone (this feature is particularly interesting because there is a demo app that sends audio from the board to an app which can connect to an online speech-to-text converter that works in close to real time. I have long wanted to build a speech rate detector, and this is a possible, though more complex than is needed, mechanism for it)
-- RGB LED (always of interest)
-- infrared LED
-- 3 Push buttons (2 user, 1 reset)
-- BLE
