# OS-Altitude-Datalogger
Open Source Code and Design Files for the TI MSP430FR5949 and Bosch BME280 Altitude Datalogger

The following repository contains the drivers, software, and EAGLE files to create a low power datalogger capable of recording pressure and temperature. 

# About the BME280
(https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BME280_DS001-11.pdf) 

# About the MSP430FR5969
The MSP430FR596 is an ultra-low power MCU capable of recording up to 64 kB of data to non-volatile FRAM memory.  FRAM (ferro-magnetic Random Access Memory) has advantages over other memory types such as flash by requiring significantly less power and faster write times.
(http://www.ti.com/product/MSP430FR5949)

# To install
Dowload this repository as a zip
Unzip file and rename to "MSP430FR5949_LP"
Locate the Folder where the Energia applicaiton is installed
Copy this folder into the following directory: /Contents/Resources/Java/hardware/msp430/variants/
Open the boards.txt file located at: /Contents/Resources/Java/hardware/msp430/ in a text editor
Append the following text at the end of the file
