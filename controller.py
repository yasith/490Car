import serial # Need to have PySerial installed

serial_speed = 115200
serial_port = '/dev/cu.AdafruitEZ-Link422d-SPP' # Change this accordingly
con = serial.Serial(serial_port, serial_speed, timeout=1)

con.write('f') #forwards
con.write('l') #turn left
con.write('r') #turn right
con.write('s') #stop
