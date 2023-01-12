# About

project is a software developed in Embedded C Language to control a traffic light system using ATmega 32 microcontroller. Project is a part of Udacity's embedded systems nanodegree program.

# System Description 

The system is an on-demand traffic light system with a pedestrian button to generate a request for pedestrians to walk. The system consists of Three LEDs for car trafficking (Red, Yellow, green) , three LEDs for pedestrians and a push button. The Microcontroller used to control the system is ATmega 32.  application is developed using Microchip Studio IDE and simulated using Proteus software. the system Has two modes:
- normal mode: enables cars to pass
- Pedestrain Mode: stops Traffic and enables Pedestrain to pass



![image](https://user-images.githubusercontent.com/121635850/212016734-aa24dc3c-63d5-487a-a2e4-1d90d6caf41f.png)  ![image](https://user-images.githubusercontent.com/121635850/212016761-a01aeee7-d486-4cbf-88b0-e62e0e910400.png)


# System Design
System is divided into 4 Main layers as shown in the below figure. Each layer has it’s own drivers, each driver has it’s own API to enable lower layers to communicate with upper layers, enforcing static layered architecture design and SOLID principles.
![image](https://user-images.githubusercontent.com/121635850/212017146-29894740-8aa3-4fd7-bf30-6985900b31fd.png)


# System Flowchart
![image](https://user-images.githubusercontent.com/121635850/212017342-aed67765-0f10-4917-90df-3d8aa5e8c9f3.png)


# System Constrains 
In normal mode:
1.	Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
2.	The Yellow LED will blink for five seconds before moving to Green or Red LEDs.

In pedestrian mode:
1.	Change from normal mode to pedestrian mode when the pedestrian button is pressed.
2.	If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
3.	If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
4.	At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
5.	After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
6.	Traffic lights signals are going to the normal mode again.

