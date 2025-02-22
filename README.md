# Project 3: Windshield Wiper Subsystem
Team Members: Hoang Tran and Advitya Singh
<br/>
<br/>

### Description
This project expands the automobile control system with the windshield wiper subsystem, operating in four modes: HI, LO, INT, and OFF. The wipers will run based on the selected mode, and the delay for INT mode will be user-selectable.
HI/LO Modes: Wipers run in periodic cycles from 0 to 67 degrees, at 40 rpm (HI) and 30 rpm (LO).
INT Mode: Same as LO mode, but with a selectable delay after each cycle.
OFF Mode: Wipers are stationary at 0 degrees.

#### Igniton Subsystem
Displays “Welcome to enhanced alarm system model 218-W25” when the driver sits down.
Ignition occurs only if both seats are occupied and seatbelts are fastened.
The system provides error messages if the ignition button is pressed while these conditions are not met.
The engine continues running even if seatbelts are removed or the driver exits the vehicle.
The engine stops when the ignition button is released.

#### Windshield Wiper Subsystem
Wipers operate based on the selected mode (HI, LO, INT, OFF) and delay time for INT mode.
The LCD displays the selected mode and delay time.
If the engine is off or the wipers are in OFF mode, they return to 0 degrees after completing the current cycle.

## Testing results
- Ignition subsystem

| Specification | Test Result | Comment |
|----------|----------|----------|
| When the driver seat is occupied, the monitor display sends a welcome message. | Pass | | |
| When the ignition is pressed without one/some of the qualifications, the alarm sounds. | Pass | | |
| Enable engine start (i.e., light the green LED) while both seats are occupied and seatbelts fastened. Otherwise print appropriate error message.    | Pass   | All error messages are displayed on serial monitor. | | | 
| Start the engine (i.e., light the blue LED, turn off Green) when ignition is enabled (green LED) and ignition button is pressed  (i.e., before the button is released).   | Pass   | | |
| Keep the engine running even if the driver/passenger should unfasten belt and exit the vehicle.| Pass | | |
| When the engine is running, stop the engine once the ignition button has been pushed and then released. | Pass | | |
<br/>

- Windshield Wiper Subsystem

| Specification | Test Result | Comment |
|----------|----------|----------|
| Wipers run in HI/LO/INT mode when engine is on. | Pass | | | 
| LCD displays mode and delay options for INT. | Pass | | | 
| Wipers delay the correct timing for the mode selected. | Pass|  | |
| Wipers return to 0 degrees when OFF or engine off. | Pass | | |

![modular diagram](https://github.com/user-attachments/assets/3d4035d6-37ca-43dc-8292-aaad0d8bd377)
