#  Indicator lights project

This project is a module controlling the turn signals of a car. This project uses a Arduino Uno, 3 switches and two leds. 
The project had the following requirements:

1. The indicator lights must always be in the OFF position.

2. All lane modes will be controlled by three switches.

3. The three functioning modes listed below should be covered by the car's indicator lights:

  Lane change mode, Normal mode, and Hazard mode are all available.

4. When the relevant switch is depressed for less than 500 milliseconds, the corresponding indicator light shall be switched to the lane change mode.

5. The relevant indicator light flashes three times with a 300ms ON phase and a 700ms OFF phase as a result of the lane change mode.

6. The lane change mode should be automatically off.

7. When the appropriate switch is held down for more than 500 milliseconds, the associated indicator light shall be converted to normal mode.

8. A potentiometer-controlled light must blink at a frequency between 1Hz and 10Hz when the switch is depressed, with a 50% duty cycle.

9. Release the associated switch for at least 100 milliseconds to deactivate regular mode.

10. When the relevant button is pushed for at least 200ms and then released again, the car's indicator lights shall be switched to the hazard position.

11. When in the hazard mode, a symmetric flashing with a 50% duty cycle and a 1Hz frequency takes precedence over all other modes.

12. When the relevant switch is pushed for at least 200ms and then released, the car's indicator lights shall be switched off from the hazard mode.

13. The software's core procedure must run in 10 milliseconds.

14.-Hazard mode has the ability to supersede all other modes.


  -Any Normal mode (left or right) or the other Lane Change mode can replace Lane Change mode (for example, the left lane).



  -Lane change mode (for ex. the left lane) can be overridden by any Normal mode (left or right) or the other Lane
change mode


 
