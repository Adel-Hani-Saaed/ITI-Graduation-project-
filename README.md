## License

This project is licensed under the [MIT License](LICENSE.md) - see the LICENSE.md file for details.

# Project Overview: Smart Drive Vehicle

Welcome to the Smart Drive Vehicle project's GitHub repository! Here, we'll provide you with an overview of our exciting endeavor to create an advanced smart driving system. Below, you'll find key components and details about our project.

## Firmware Development (STM32 Code)
<div align="center">
  <img src="Image/Layers Architecture .png" alt="Layers Architecture Diagram " width="400">
</div>
At the heart of the Smart Drive Vehicle project is the development of advanced firmware. We are actively working on creating firmware that will power a wide range of features and peripherals within our smart driving system. Our STM32 code is at the core of this development, and it will enable various functionalities, including:

- Real-time vehicle control
- Sensor data processing
- Communication with external devices

## GUI using Raspberry Pi
<div align="center">
  <img src="Image/GUI.png" alt="GUI using Raspberry Pi" width="650">
</div>

To provide a user-friendly interface for our Smart Drive Vehicle, we are developing a Graphical User Interface (GUI) using a Raspberry Pi. This GUI will serve as the primary means of interacting with and controlling the vehicle's functions. Key features of the GUI will include:

- Intuitive controls for vehicle navigation
- Real-time data display, including distance and speed readings
- System status monitoring


# State Machine

The Smart Drive vehicle operates using a state machine to manage its behavior and transitions during operation. This document provides an overview of the state machine, the different states, and the features associated with each state.

![State Machine](Images/diagram Modes.png)

## States

### 1. Idle Mode
In this mode, the SmartDrive vehicle is at rest and not actively engaged in any specific driving tasks. It is waiting for user input or a trigger to transition to another mode.



### 2. Low-Speed Mode
Low-speed mode represents the state in which the vehicle is traveling at lower speeds, typically within urban or congested areas. It includes the following features:


### 3. High-Speed Mode
High-speed mode represents the state in which the vehicle is traveling at higher speeds, typically on highways or open roads. It includes the following features:

#### Features:
1. ACC (Adaptive Cruise Control): Similar to Low-Speed Mode, the vehicle can automatically adjust its speed to maintain a safe following distance from the vehicle ahead.
2. AEB (Automated Emergency Braking): The system can automatically apply the brakes in emergency situations to prevent or mitigate collisions.
3. LKS (Lane Keeping Support): The system assists the driver in keeping the vehicle within its lane, providing steering support if necessary.

## Acknowledgments
I would like to acknowledge the entire team and the open-source community for making this project possible.


## Presentation

In addition to the technical aspects of our project, we are committed to effectively communicating our progress and findings. Our presentation materials will include:

- **Slides:** We'll provide detailed slides outlining the project's goals, methodologies, and results. These slides will be helpful for understanding our project's high-level overview and its significance.

- **Videos:** We plan to create informative videos that showcase the features and capabilities of our Smart Drive Vehicle. These videos will serve as visual aids for better comprehension and engagement.<a href="https://drive.google.com/file/d/1Q1FdiaNc3NXPRbiduHG6HBcWxxKw4brT/preview">
    <img src="https://drive.google.com/file/d/1Q1FdiaNc3NXPRbiduHG6HBcWxxKw4brT/preview" alt="Passed Here To get the video" width="650">
  </a>


## Image

A picture is worth a thousand words. We will include images that visually represent our project. Our images will provide a visual context for our project, making it easier to understand and appreciate.

## Proteus Simulation
<div align="center">
  <img src="Image/Simulation Project .png" alt="Proteus Simulation" width="650">
</div>
To ensure the effectiveness and safety of our smart driving system, we utilize Proteus Simulation. Proteus allows us to simulate various scenarios and test the system's functionality without the need for physical implementation. In this section, we will:

- Describe the simulations we have conducted
- Share simulation results
- Explain how these simulations contribute to the project's development
By using Proteus Simulation, we can fine-tune our system before deploying it in real-world scenarios, enhancing the overall reliability and performance.


## Demo

To witness Smart Drive vehicle in action, you can run the provided example code by following these straightforward steps:

1. **Clone the Repository**:
   ``` shell
   git clone https://github.com/Adel-Hani-Saaed/ITI-Graduation-project-
   ```

2. **Build the Firmware**:
   ``` shell
   make firmware
   ```

3. **Hardware Connection**:
   Connect the Smart Drive vehicle hardware to your computer.

4. **Run the Demo Application**:
   Execute the demo application to experience the capabilities of the Smart Drive vehicle.

These steps will guide you through the process of setting up and running the demo, allowing you to explore the Smart Drive vehicle's features and functionality.












