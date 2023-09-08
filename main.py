##
# @Graphical User Interface(GUI) Project with Qt5
#
# @section description_main Description
# Cruise Control System with Automatic Emergency Braking.
# This project is for controlling the speed of the car to adapt its speed according to
# the circumstances of the obstacles ahead.
# Also, here we display the current speed and current Distance that the Driver reach at any moment.
# Further more, we display the mode and state of the Cruise Control selected.  
#
# @section notes_main Notes
#   there are 3 buttons; Accelerate, Deacelerate , stop

##
# @file main.py
#
# @section libraries_main Libraries/Modules
# - time standard library (https://docs.python.org/3/library/time.html)
#   - Access to sleep function.
# - sys standard library
#   - to exit the GUI
# - serial standard library
#   - to read and write data from UART
# - threading standard library
#   - to run different processes almost, simultaneously.
# - PyQT5 libraries
#   - to build the GUI


#imports
import sys
import time
import serial
from threading import *
from PyQt5.QtWidgets import QMainWindow, QWidget, QApplication,QLCDNumber,QPushButton,QLabel
import RPi.GPIO as GPIO

################################################################################################
# Import the generated UI
################################################################################################
from interface_ui import Ui_MainWindow as interface_ui

ser = serial.Serial('/dev/ttyAMA0', 9600)                 #to send and recieve data through UART


################################################################################################
# @MAIN WINDOW CLASS
################################################################################################
class MainWindow(QMainWindow, interface_ui):
	mode=0
	def __init__(self, parent=None):
		QMainWindow.__init__(self)
		################################################################################################
		# Setup the UI main window
		################################################################################################
		self.setupUi(self)


		################################################################################################
		# buttons
		################################################################################################
		self.accel.setAutoRepeat(True)
		self.accel.setAutoRepeatDelay(1000)
		self.decl.setAutoRepeat(True)
		self.decl.setAutoRepeatDelay(1000)
		self.accel.clicked.connect(self.accell)            #button to accelerate the motor
		self.decl.clicked.connect(self.decll)              #button to deacelerate the motor
		self.stop.clicked.connect(self.stopFun)            #button to stop the system

		################################################################################################
		# Show window
		################################################################################################
		self.show()


		##############################################################################################
		#customize Analogue Gauge Wadget
		##############################################################################################
		self.widget.enableBarGraph =True

		self.widget.setEnableBarGraph(False)


		#set Gauge units
		self.widget.units = "m/min"

		#set minimum gaugae value
		self.widget.minValue =0


		#set max gaugae value
		self.widget.maxValue =100


		#set scale value
		self.widget.scalacount =1


		##############################################################################################
		#displaying the Analogue widget needle current value on the LCD
		##############################################################################################
		def change(value):
			self.lcd.display(value)

		self.widget.valueChanged.connect(change)



		#select gauage theme
		self.widget.setGaugeTheme(4)                                    #choose number from zero to 24



		self.widget.setScalePolygonColor(
			color1 = "blue",
			color2 = "green",
			color3 = "white"

		)



		self.widget.setNeedleCenterColor(
			color1 = "Red" ,
			color2 = "#2D16B3" ,
			color3 = "#green"

		)

		self.widget.setBigScaleColor("blue")           #set the Big scaler color
		self.widget.setFineScaleColor("blue")           #set the small scaler color


		self.widget.setScaleValueColor(255,255,255,255)         #number in widget            
		self.widget.setDisplayValueColor(0,0,255,255)

		self.widget.setNeedleColor(0,0,255,255)


		self.widget.setEnableCenterPoint(True)      

		self.widget.setMouseTracking(False)          



    ##############################################################################
    #threads and functions of the buttons
    ##############################################################################
	def threadRead(self):
		t12=Thread(target=self.SerUpdate)
		t12.start()
        
        
	def accell(self):
		
		ser.write(b"A")
		print('sent A')
    
    
	def decll(self):
		
		ser.write(b"D")
		print('sent D')
		
		
	def stopFun(self):
		self.lineEdit_3.setText('Car is Stop')
		ser.write(b"S")
		print('sent S')



	def SerUpdate(self):
		while(1):
			c=ser.read(1)

			if c == b'\r':
				char=ser.read(22)  							 # Retuen .read is ByteArray DataType
				msg=char.split(b' ')						 # Divided the array to Two element in list [0]-->>Speed , [1] -->>Distance
				speed = msg[0].strip(b'\x00\r')				 #remove any null char in bytearray 
				distance = msg[1].strip(b'\x00\r')			
				print("speed = {}".format(speed))			 #print in termnail Speed and Distance 
				print("distance = {}".format(distance))
				distance_str=str(distance)			
				distance_string=distance_str.strip("b\'")
				Distance_String=distance_string
				for v in distance_string:
					if v == 'x' or v == '\\':
						error =1
						break
					error= 0
				if error==1:
					error=0
					dd_str=distance_string.split("\\")
					Distance_String=dd_str[0].strip("\'")
				self.lineEdit.setText(Distance_String)
				Distance = int(Distance_String)

				speed_str=str(speed)
				speed_string=speed_str.strip("b\'")
				Speed_Current=speed_string
				for v in speed_string:
					if v == 'x' or v == '\\':
						error =1
						break
					error= 0
				if error==1:
					error=0
					Adel_str=speed_string.split("\\")          
					Speed_Current=Adel_str[0].strip("\'")
					
				Speed_Now= int(Speed_Current)
				self.widget.updateValue(Speed_Now)
				if Speed_Now == 0:
					self.lineEdit_3.setText('Car is Stop')
				else :
					self.lineEdit_3.setText('Car is Running')




########################################################################
## EXECUTE APP
########################################################################
########################################################################
#  main function
########################################################################
if __name__ == '__main__':
    app = QApplication(sys.argv)


    window =MainWindow()    #the name of the main class
    window.show()
    window.threadRead()
    sys.exit(app.exec_())

########################################################################
## END
########################################################################
