# Exercise 2.1: Imaginary Embedded System - Idea Project Diagram

Make a block diagram describing an embedded system you’d like to have or make. Be
imaginative. Reality does not apply here.

## Proposed System - Contactless Candy Launcher
### Statement of the Problem
The door to my house is at the top of 18 steps, and as a result, even though I live in a neighborhood with many trick-or-treaters, relatively few want to put in the effort to climb to my front door to get candy. Additionally, the spread of Covid makes face-to-face transactions involving strangers (especially strange children) somewhat risky.

### Proposed Solution
The Contactless Halloween Candy Launcher solves both aforementioned problems by allowing trick or treaters to trigger an input at the bottom of the stairs at my house, to indicate they’d like candy. Possible triggers include a simple arcade button or voice recognition of the spoken phrase “Trick or Treat.”

In response to the trigger, an automated projectile launcher, loaded with some aerodynamic candy that is soft enough to be unlikely to cause injury (e.g. fun-size Snickers) will launch the candy into the air so that it traverses an arc computed to land in a basket located directly in front of the trick-or-treater. The trick-or-treater can then take the candy from the basket and continue trick-or-treating down the rest of the street.  The projectile candy arcs through the air into a basket at the bottom of the stairs. The next candy bar then automatically falls into position in the chute, waiting for its turn to be launched and the servo motor resets its position. A buzzer will sound just prior to launching to warn passerby of an impending projectile.

### Hardware
For simplified wiring, the trigger in this proposed prototype is a simple arcade button, labelled “Trick-or-Treat” connected via a small processor (ATtiny?) to some wireless remote control, paired with a complementary controller at the top of the stairs that is connected to the motorized candy launcher. To keep coding simple, the remote control could be a simple IR beacon, pointed at a receiver attached to the controller at the top of the stairs.

An IR receiver connects to the processor. Upon receiving (and debouncing, as we don’t want false triggers) the IR signal, the processor activates a buzzer for several seconds,  then sends a signal to the motor controller which activates the servo.

### Block Diagram
![Simple System Diagram](https://github.com/geekmomprojects/RedJellies/blob/main/Week2/Week2ProjectDiagram.png)


