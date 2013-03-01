Introduction
------------

**typebox** is an arduino-based serial input to
keyboard output USB converter box.  

Keys and key names are written to a serial port
in the system connected to the input.
The input stream is converted to key strokes that
are sent to the system connected
to the output, emulating a USB keyboard.

The following example shows a stream of keys
and key names that are the input on the left side.
The stream opens a text editor, types a line with
*hello world*, and then moves up to do two edits to
the line.
The final text that results from that stream
in the output is shown on the right side, assuming that
the system connected to the output has a Gnome
desktop environment::

 {alt-f2}gedit{enter}                                        +---- gedit ----+
 hello world{enter}                +-----------+             | Hello world!  |
 {up}{delete}H         USB ------> | type box  | -----> USB  |               |
 {end}!                            +-----------+             +---------------+


The **typebox** converter allows to send keys from one 
computer to another from a script as needed. 

It is a DIY experimental hardware + software
project.

Materials
---------
You need:

- `Arduino Uno`__
- `Easy Input chip`__, by Radovan Robotics, 24 DIP package
- Small protoboard
- USB plug
- 1.5K ohm 1/4W resistor

The Arduino development software is also required,
to compile and download the program into the Arduino.

__ http://arduino.cc/en/Main/ArduinoBoardUno
__ http://www.radovan.org/EasyInput/index.htm


Preparation
-----------

Hardware
~~~~~~~~
Plug the Easy Input chip into the protoboard.  Connect
as shown:

TBD

Four wires connect between the protoboard and the Arduino
ground, DO8, D09 and DO10 pins.


Software
~~~~~~~~
In a Debian or Ubuntu Linux system, install
the ``arduino-core`` and ``arduino-mk`` packages.

Download the software from github, then compile and
download it into the Arduino.  In a bash shell::

 git clone git://github.com/ppaez/typebox.git
 cd typebox
 make
 sudo make upload

Contributing
------------
Please provide suggestions, comments and patches
in http://github.com/ppaez/typebox or by
email to Patricio Paez, pp at pp.com.mx
- 
