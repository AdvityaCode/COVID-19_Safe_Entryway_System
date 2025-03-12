# Covid-19 Safe Entryway System

Michael Fitzmaurice and Advitya Singh

## System Behavior

This system is designed to prevent the spread of disease by ensuring that individuals entering buildings pass health checks before they are permitted to enter. The two health checks we have decided to focus on were body temperature (to ensure there is no fever), and hand sanitization. We also wanted to design this system in a way that minimized physical contact in order to further prevent the spread of disease.

When the user enters the building, they are greeted by a message prompting them to get their hands sanitized. Next, the individual cups on of their hands under the sanitizer nozzle and wave their other hand over the Ultrasonic Distance Sensor. Once the sensor senses the user's hand in a distance of 7cm, the santizer automatically dispenses. The display then prompts the user to prove that they have santizer their hands by cupping their hands under the gas sensor. Once prove, the next health check is the temperature check. Once the display says "Get temp checked", they user hovers their forehead near the ultrasonic temperature sensor. If the individual has a healthy average body temperature (below 99°), the gate automatically opens and the display states "Entry Granted: Enter the Alumni Gym". Otherwise, the door will not open and the display will state "Entry Denied: Temp too high". The last component of the system is the LDR Sensor. Once a user enter through the gate, the darkness under their body, indicated through the LDR sensor, will prompt the door to close. 

## Design Alternatives
In this section, possible future improvements and additions are expanded on.

1) Placing the Distance Sensor on the sanitizer bottle instead of above the bottle wouuld intuitively make more sense for the users who have never used the system previously. Our concern was that if the sanitizer liquid itself fell on the sensor, it would ruin the sensor and we would have to replace it. In future improvements, we can place the sensor on the bottle at a position that is protected from the liquid but is still on the bottle.
2) During the live demonstration of the project, we noticed that the users were interested in knowing their body temperature. A future implementation plan could display the users temperature on the LCD Display, so we offer proof on our decision of acceptance or denial.
3) The LDR Sensor after the gate could be replaced with a Breakbeam Sensor which uses a laser to see if anyone has passed through it. Because the LDR sensor works perfectly, this addition is simply an alternative.

## Summary of Testing Results

## Modular Diagram of Code
![ECE-218-FinalModularDiagram](https://github.com/user-attachments/assets/bf007645-f108-45d2-a2cd-0eb31b12ecec)
