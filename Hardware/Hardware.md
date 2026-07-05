# Hardware

## Overview

The robotic arm is built using a Raspberry Pi 4 as the main controller and an Arduino Uno for servo motor control. A Python-based graphical user interface (GUI) running on the Raspberry Pi sends servo angle commands to the Arduino through USB serial communication. The Arduino then generates PWM signals to position each servo motor, enabling smooth and real-time control of the robotic arm.

---

# Hardware Components

| Component                                    |   Quantity  | Description                                                                  |
| -------------------------------------------- | :---------: | ---------------------------------------------------------------------------- |
| Raspberry Pi 4 (4 GB)                        |      1      | Runs the Python GUI and communicates with the Arduino through USB serial.    |
| Arduino Uno                                  |      1      | Controls the servo motors by generating PWM signals.                         |
| Servo Motors                                 |      5      | Used for the robotic arm joints (Base, Shoulder, Elbow, Wrist, and Gripper). |
| External 5 V DC Power Supply (5 A or higher) |      1      | Provides sufficient power to all servo motors.                               |
| USB Cable                                    |      1      | Establishes serial communication between the Raspberry Pi and Arduino.       |
| Jumper Wires                                 |   Multiple  | Used for electrical connections.                                             |
| Robotic Arm Frame                            |      1      | Mechanical structure supporting the servos and joints.                       |
| Mounting Hardware                            | As required | Nuts, bolts, spacers, and brackets for assembly.                             |

---

# Hardware Specifications

## Raspberry Pi 4

* Processor: Broadcom BCM2711 Quad-Core Cortex-A72
* RAM: 4 GB
* Operating System: Raspberry Pi OS (64-bit)
* Communication: USB Serial
* Programming Language: Python 3

---

## Arduino Uno

* Microcontroller: ATmega328P
* Operating Voltage: 5 V
* Digital I/O Pins: 14
* PWM Pins Used:

  * D3
  * D5
  * D6
  * D9
  * D10
* Communication: USB Serial (9600 baud)

---

## Servo Motors

* Quantity: 5
* Operating Voltage: 4.8–6 V
* Rotation Range: 0°–180°
* Control Method: PWM
* Functions:

  * Servo 1 – Base Rotation
  * Servo 2 – Shoulder
  * Servo 3 – Elbow
  * Servo 4 – Wrist
  * Servo 5 – Gripper

---

# Pin Connections

| Arduino Pin | Servo   | Function      |
| ----------- | ------- | ------------- |
| D3          | Servo 1 | Base Rotation |
| D5          | Servo 2 | Shoulder      |
| D6          | Servo 3 | Elbow         |
| D9          | Servo 4 | Wrist         |
| D10         | Servo 5 | Gripper       |

---

# Power Distribution

The Raspberry Pi powers only the Arduino through the USB cable and handles the graphical user interface. The servo motors are powered using an external regulated 5 V power supply capable of delivering sufficient current for all servos during simultaneous movement.

**Important Notes**

* Do not power the servo motors directly from the Arduino 5 V pin.
* Connect the Arduino GND and external power supply GND together (common ground).
* Use a regulated 5 V supply with a current rating of at least 5 A.
* A 1000 µF capacitor across the servo power supply is recommended to reduce voltage drops during sudden servo movements.

---

# Communication

The Raspberry Pi communicates with the Arduino Uno through USB serial communication.

**Communication Parameters**

* Interface: USB Serial
* Baud Rate: 9600 bps
* Data Format:

```
Servo1,Servo2,Servo3,Servo4,Servo5
```

**Example**

```
90,45,120,60,30
```

The Arduino parses the received values and updates each servo position accordingly.

---

# Working Principle

1. The user moves sliders in the Python GUI.
2. The GUI reads the current angle of each slider.
3. The angles are combined into a comma-separated string.
4. The data is transmitted to the Arduino through USB serial communication.
5. The Arduino receives the serial data.
6. The values are separated and converted into servo angles.
7. PWM signals are generated on the respective output pins.
8. The servo motors rotate to the desired positions.

---

# Hardware Features

* Independent control of five servo motors
* Real-time response through USB serial communication
* Low-cost and modular architecture
* Expandable for additional sensors or actuators
* Simple wiring and easy maintenance
* Suitable for educational and robotics learning applications

---

# Future Hardware Enhancements

* Metal gear servo motors for higher payload capacity
* Servo feedback using encoders or potentiometers
* Wireless communication using Wi-Fi or Bluetooth
* Camera module for object detection
* Power monitoring and battery backup
* Emergency stop switch
* End-stop limit switches for joint protection
