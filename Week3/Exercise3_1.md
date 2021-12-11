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

(TBD) Block Diagram (coming soon)

- The processor is an STM32WB5MMGH6
- There is 1 Mbyte flash and 256 Kbytes of SRAM. There is also an 128-Mbit Quad-SPI NOR Flash memory. After googling it, I now understand the difference between NOR flash and NAND flash (standard). NOR is more expensive but about 3x faster for reading and can execute bitwise read, vs NAND, which is faster for writing and erasing.
- There are a large number of peripherals built into the discovery board, including:
  - 0.96-in 128x64 OLED display
  - temperature sensor
  - accelerometer/gyroscope
  - time of flight/gesture detection sensor (I have an interest in AI/gesture detection, and will be attempting to see how this feature works)
  - digital microphone (this feature is particularly interesting because there is a demo app that sends audio from the board to an app which can connect to an online speech-to-text converter that works in close to real time. I have long wanted to build a speech rate detector, and this is a possible, though more complex than is needed, mechanism for it)
  - RGB LED (always of interest)
  - infrared LED
  - 3 Push buttons (2 user, 1 reset)
  - touch sensor
  - Bluetooth 5, which is a feature I like to have in wearables, and will try to make use of in my final project
- TIL that FPU means "Floating Point Unit" and the board has an "adaptive real-time accelerator" for this function
- Every processor in the STM32WB line, including the STM32WB5M used on this board has a 16 bit ADC, with many amazing and wonderful features. Source: [https://www.youtube.com/watch?v=XWzzggtwIo8](https://www.youtube.com/watch?v=XWzzggtwIo8). These features include:
  - adjustable sampling resolution to allow for faster sampling
  - (up to) 16 IO inputs
  - low processing modes, including delayed data conversion to reduce power consumption
  - sampling may be triggered by software or timers/IO
  - 3 watchdogs (and I'm looking forward to learning what those are)
  - Self-calibration
  - The ability to select clock source so that the sampling rate can be faster than the processor if the processor clock speed is slow to reduce power consumption

I found the following application note for the STM32WB: [https://www.st.com/resource/en/application_note/an5289-building-wireless-applications-with-stm32wb-series-microcontrollers-stmicroelectronics.pdf](https://www.st.com/resource/en/application_note/an5289-building-wireless-applications-with-stm32wb-series-microcontrollers-stmicroelectronics.pdf) which discusses implementing wireless applications. It is 160 pages long, and I have skimmed it very briefly, but will go back to take a longer look later.
