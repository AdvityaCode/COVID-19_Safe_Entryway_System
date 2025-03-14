# Covid-19 Safe Entryway System

Michael Fitzmaurice and Advitya Singh

## System Behavior

This system is designed to prevent the spread of disease by ensuring that individuals entering buildings pass health checks before they are permitted to enter. The two health checks we have decided to focus on were body temperature (to ensure the user does not have a fever), and hand sanitization. We also wanted to design this system in a way that minimized physical contact in order to further prevent the spread of disease.

When the user enters the building, they are greeted by a message prompting them to get their hands sanitized. Next, the individual puts one of their hands under the sanitizer nozzle and waves their other hand over the Ultrasonic Distance Sensor. Once the distance sensor senses the user's hand at a distance within 7cm, the santizer automatically dispenses through the use of two servo motors attached to the sanitizer bottle. The display then prompts the user to prove that they have gotten sanitizer by cupping their hands under the gas sensor. Once proven, the next health check is the temperature check. Once the display says "Get temp checked", the user hovers their forehead within 6cm of the lens of the infrared temperature sensor to ensure an accurate measurement. If the individual has a healthy average body temperature (between 90°F and 99°F), the gate automatically opens and the display states "Entry Granted: Enter the Alumni Gym". Otherwise, the door will not open and the display will state "Entry Denied: Temp too high". The last component of the system is the LDR Sensor. Once the user enters through the gate, the darkness under their body, indicated through the LDR sensor, will prompt the door to close. 

## Design Alternatives
In this section, possible future improvements and additions are expanded on.

1) Placing the Distance Sensor on the sanitizer bottle instead of above the bottle would intuitively make more sense for the users who have never used the system previously. Our concern was that if the sanitizer liquid itself fell on the sensor, it would ruin the sensor and we would have to replace it. In future improvements, we can place the sensor on the bottle at a position that is protected from the liquid but is still on the bottle.
2) During the live demonstration of the project, we noticed that the users were interested in knowing their body temperature. A future implementation plan could display the users temperature on the LCD Display, so we offer proof on our decision of acceptance or denial.
3) The LDR Sensor after the gate could be replaced with a Break Beam Sensor which uses a laser to see if anyone has passed through it. Because the LDR sensor works perfectly, this addition is simply an alternative.

## Summary of Testing Results
![image](https://github.com/user-attachments/assets/9608b552-6800-4cd9-bf98-037f10b0159d)
![image](https://github.com/user-attachments/assets/d83822d9-f62c-4a0e-87ad-0ed2bea39043)
![image](https://github.com/user-attachments/assets/e714834c-1a23-4e2e-858f-44f16a891840)

## Modular Diagram of Code
![ECE-218-FinalModularDiagram](https://github.com/user-attachments/assets/bf007645-f108-45d2-a2cd-0eb31b12ecec)
- Orange modules are system modules
- Yellow modules are subsystem modules
- Green modules are driver modules
