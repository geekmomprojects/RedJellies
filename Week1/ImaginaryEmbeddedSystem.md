# Wearable Speech Rate Detector with Haptic Feedback

## Motivation 
I’m frequently told that I speak quickly, making my words difficult to understand. I’m able to correct the problem when I recognize and focus on it, but it’s challenging to maintain that focus for extended time periods.

## Proposed Solution 
I would like to create a small device, ideally wearable, that can analyze the bearer's speech in close to real time. The device will provide subtle feedback through small vibrations or other means which will be apparent to the bearer but undetectable by others, when the detected rate of the bearer's speech exceeds a specified threshold.

## Implementation

### Functionality
The device should be small and inconspicuous enough to be worn publicly without attracting attention. It must be powered by batteries or another portable power source because the wearer must be able to move around while using it. The device will either record continuously, filtering the noise it records to isolate the wearer's speech, or it will start recording when it is triggered by the wearer's voice. It will record and temporarily store enough data from which to determine, with acceptable accuracy, the rate of the wearer's speech in words per minute, or more likely, syllables per minute. The wearer must be able to easily set and change a speech rate threshold for notifications. If the device detects that the wearer's speech rate exceeds the specified threshold, it will notify the user in a subtle fashion, likely with small vibrations, and continue to do so as long as the rate of speech remains above the threshold.

### Hardware
The proposed device may use:
- A microphone to record sound samples
- ADC to convert sound to digital data (could be part of microphone)
- Memory to store the sound samples or data corresponding to words spoken in a period of time that is long enough to compute an averate speech rate
- A processor capable of analyzing sound samples and rapidly determining a numerical speech rate from them
- Possibly a hardware frequency filter of some kind will be helpful to isolate speech from other ambient noise
- A method to allow the user to set the notification threshold, possibly with a small screen and several push buttons, or a potentiometer with marked dial.
- If the device were to have Bluetooth capability, the notification threshold could be set on an app, and data indicating speech rate at different times could be sent to the phone and stored there. 
- A small vibration motor to provide haptic feedback
- If rechargeable batteries are used, a charging circuit and port will be necessary

### Algorithm/Software
Detecting the rate of speech does not require recognition of the actual speech content. The rate of a speaker producing syllables probably correlates well enough with speech rate for the purposes of this project. There are many existing publically documented algorithms for speech analysis. Some use machine learning algorithms in their computation and many appear to be written in Python. The algorithm linked here uses PRAAT in Python to count the number of syllables in a recorded speech sample [https://sites.google.com/site/speechrate/Home](https://sites.google.com/site/speechrate/Home)

It isn't clear how much these algorithms can be simplified and what kind of processor power is required to run them. Speech rate could possibly be inferred from the rapidity of modulations in a speakers loudness which might be a simpler imlementation. More research is required into the efficiency and quality of various algorithms before any specific one could be chosen.

