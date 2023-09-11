# SmartDrive

SmartDrive is a project that aims to develop a smart driving system. It includes firmware for various features and peripherals, along with documentation, examples, and tests.

## System Diagram

The system diagram below illustrates the components and their interactions in the SmartDrive system.

![System Diagram]([https://your-image-url.type](https://github.com/Adel-Hani-Saaed/ITI-Graduation-project-/blob/main/Image/diagram%20Modes.png))
<img src="[https://your-image-url.type](https://github.com/Adel-Hani-Saaed/ITI-Graduation-project-/blob/main/Image/diagram%20Modes.png)" width="100" height="100">

## State Machine

The state machine represents the behavior of the SmartDrive system. It describes the different states and transitions of the system during operation.

![State Machine](Image/diagram_Modes.png)

The SmartDrive system operates based on a state machine with the following states:

1. Idle
2. ACC (Adaptive Cruise Control)
3. LDW (Lane Departure Warning)
4. AEB (Automated Emergency Braking)
5. LKS (Lane Keeping Support)

The state transitions are as follows:

- From Idle:
    - Transition to ACC state when the ACC mode is enabled.
    - Transition to LDW state when the LDW mode is enabled.
- From ACC:
    - Transition to Idle state when the ACC mode is disabled.
    - Transition to AEB state when a potential collision risk is detected.
- From LDW:
    - Transition to Idle state when the LDW mode is disabled.
    - Transition to LKS state when the vehicle deviates from the lane.
- From AEB:
    - Transition to Idle state when the collision risk is mitigated.
- From LKS:
    - Transition to Idle state when the vehicle is back within the lane.

## GUI

![System GUI](images/gui.png)

The SmartDrive project includes a graphical user interface (GUI) that provides an intuitive and user-friendly interface for interacting with the system. The GUI allows users to monitor the system's status, configure settings, and visualize data in real time. Some key features of the GUI include:

- Real-time visualization of sensor data such as vehicle speed, distance to objects, and lane position.
- Interactive controls for enabling/disabling various ADAS modes, such as Adaptive Cruise Control (ACC), Lane Departure Warning (LDW), and Automated Emergency Braking (AEB).
- Configurable settings for adjusting sensitivity thresholds, warning/alert preferences, and system behavior.
- Graphical representation of the vehicle's trajectory, highlighting detected lane markings and potential collision risks.
- Logging and exporting of system data for further analysis and evaluation.

The GUI is developed using the Qt framework and Python, providing a cross-platform solution that can run on various operating systems. It utilizes the PyQt library for seamless integration of Qt with Python. The GUI module is located in the `firmware/App` directory.

For more information on using and customizing the GUI, please refer to the [Qt for Python Documentation](https://doc.qt.io/qtforpython-6/).


## Demo

To see SmartDrive in action, you can run the provided example code. Follow the steps below to set up and run the demo:

1. Clone the repository: `git clone https://github.com/k-abdulaziz/SmartDrive.git`
2. Install the necessary dependencies: `cd SmartDrive && npm install`
3. Build the firmware: `make firmware`
4. Connect the SmartDrive hardware to your computer.
5. Run the demo application: `npm run demo`

The demo will showcase the various features of the SmartDrive system, including adaptive cruise control, lane departure warning, and automatic emergency braking.
