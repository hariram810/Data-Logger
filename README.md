# Data-Logger

![Screenshot (599)](https://user-images.githubusercontent.com/118633170/205675595-c835323a-1340-4439-a860-e19dd05d83a9.png)

If you have hard-time 3d printing stuff and other materials which i have provided in this project please refer the professionals for the help, [JLCPCB](https://jlcpcb.com/RNA) is one of the best company from shenzhen china they provide, PCB manufacturing, PCBA and 3D printing services to people in need, they provide good quality products in all sectors

[JLCPCB](https://jlcpcb.com/RNA)


Please use the following link to register an account in [JLCPCB](https://jlcpcb.com/RNA)

https://jlcpcb.com/RNA


Pcb Manufacturing

----------

2 layers

4 layers

6 layers

jlcpcb.com/RNA



PCBA Services

[JLCPCB](https://jlcpcb.com/RNA) have 350k+ Components In-stock. You don’t have to worry about parts sourcing, this helps you to save time and hassle, also keeps your costs down.

Moreover, you can pre-order parts and hold the inventory at [JLCPCB](https://jlcpcb.com/RNA), giving you peace-of-mind that you won't run into any last minute part shortages. jlcpcb.com/RNA



3d printing

-------------------

SLA -- MJF --SLM -- FDM -- & SLS. easy order and fast shipping makes [JLCPCB](https://jlcpcb.com/RNA) better companion among other manufactures try out [JLCPCB](https://jlcpcb.com/RNA) 3D Printing servies

[JLCPCB](https://jlcpcb.com/RNA) 3D Printing starts at $1 &Get $54 Coupons for new users


![Screenshot (600)](https://user-images.githubusercontent.com/118633170/205675562-8155f0a5-bfb2-45a4-8161-948cbc6dd568.png)


A data logger (also datalogger or data recorder) is an electronic device that records data over time or about location either with a built-in instrument or sensor or via external instruments and sensors. Increasingly, but not entirely, they are based on a digital processor (or computer), and called digital data loggers (DDL). They generally are small, battery-powered, portable, and equipped with a microprocessor, internal memory for data storage, and sensors. Some data loggers interface with a personal computer and use software to activate the data logger and view and analyze the collected data, while others have a local interface device (keypad, LCD) and can be used as a stand-alone device.



The data saved can be easily opened in an Excel Sheet for further analyses. To maintain the date and time we will use the famous RTC module DS3231 and to get the Temperature and Humidity we will use the DHT11 Sensor. 

We have to write the Arduino program which can do the following.

Read data from DTH11 Sensor (or any other data that you wish to log).
Initialize the I2C bus to read data from RTC module.
Initialize the SPI bus to interface the SD card module with Arduino.
Store the Date, Time, Temperature and Humidity into the SD card.
Store the Date, Time, Temperature and Humidity on a Excel Sheet running on a computer/Laptop.
The above steps might sound complicated but they are very easy since we have the libraries to do the hard job for us. You have to download the following two libraries

DHT11 Sensor Library
DS3231 RTC module library 
To feed the data from Arduino lively into an Excel sheet on computer we will also need to install software called PLX-DAQ provided by Parallax Inc. Follow the link to download the file and install them based on your operating system. This should have created a folder named PLS-DAQ on your desktop. We will take care of it later in our working section.



1. Reading Data from DS3231:

DS3231 is a RTC (Real Time Clock) module. It is used to maintain the date and time for most of the Electronics projects. This module has its own coin cell power supply using which it maintains the date and time even when the main power is removed or the MCU has gone though a hard reset. So once we set the date and time in this module it will keep track of it always.

![Screenshot (603)](https://user-images.githubusercontent.com/118633170/205675639-0f478e6d-a28e-481e-8878-a6b1a3d22827.png)
![Screenshot (601)](https://user-images.githubusercontent.com/118633170/205675652-c651012e-cbe3-4d4b-95d6-5ce4ec1b3b2e.png)
![Screenshot (602)](https://user-images.githubusercontent.com/118633170/205675656-4b2b84a2-1b9e-45bc-8966-05b85e9ab184.png)


Using this module is very easy because of the library provided by Arduino.

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
void Initialize_RTC()
{
   // Initialize the rtc object
  rtc.begin();

//#### the following lines can be uncommented to set the date and time for the first time### 
/*
rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
rtc.setTime(18, 46, 45);     // Set the time to 12:00:00 (24hr format)
rtc.setDate(6, 30, 2017);   // Set the date to January 1st, 2014
*/

}![Screenshot (611)](https://user-images.githubusercontent.com/118633170/205675749-569a18c6-4793-4aaf-8b20-cd73ca79dacf.png)

![Screenshot (609)](https://user-images.githubusercontent.com/118633170/205675803-b63d2f63-2e5b-4ce4-bbe5-445025ee574f.png)


In the loop section using the Serial.print() funtion we will print the time and the temperature values on the serial monitor, with a “comma” character between them and a new line after the temperature value. We need this form of the lines so that we can easily import them and make a chart in Excel. Also note that the temperature values are converted into integers.

So these same values will also be written into the newly created “test.txt” file and at the end we just need to add a delay which will represent the interval of recording the temperature data.

