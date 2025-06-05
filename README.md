Memory game
There are different difficulties for the game, up to 5 levels. For 0-4 pixels will be green and 4-9 will be red there will be random flash for either green or red, the player must click the correct corresponding color (pin4 or 5), up till 5 consecutive flashes then reset. If the player got it wrong, it will play a sad tone and restart the game from 1 flash, if the player got it correct, it will play a happy tone. If the 5th level is completed, it will play a congratulation tone. The slide switch will turn on or off the switch.



Input 
Description
Function
Pin 7 (Slide switch)
Toggle on/off
HIGH/LOW
Pin 4 (Left button)
Select green
Register player’s guess
Pin 5 (Right button)
Select red
Register player’s guess


Output
Description
Function
NeoPixel (0-9)
Display light
0-4 for green and 5-9 for red
Speaker CPX
Play sound
Play sad, happy and congradulations
Serial Monitor
Debugging/feedback 
Shows current level and switch state


Flash selection
Choose left or right randomly
Button verification
Observe if green is pressed for 0-4 or red for 5-9
Increasing sequence
From 1 flash to 5
delay
Delay so that there will be a consecutive of flash

