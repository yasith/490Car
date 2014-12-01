import serial # Need to have PySerial installed
import time
from multiprocessing.dummy import Pool

pool = Pool(processes=1)

serial_speed = 115200
serial_port = '/dev/cu.AdafruitEZ-Link422d-SPP' # Change this accordingly

con = 0

def async_connect():
  print "connecting"
  global con
  con = serial.Serial(serial_port, serial_speed, timeout=1)
  print "connecting finished"

def draw(char):
  if char == 'h':
    send('mffmbllmfmrrfmbbm')
    send('llfrr')
  elif char == 'l':
    send('mfffbrrffm')
    send('fllbbb')
  elif char == 'v':
    send('rffllbb')
    send('brf')
  elif char == 'e':
    send('mffllfmbrrbmllfmbrrbmllffm')
    send('frr')
  elif char == 'o':
    send('mffllfrrbbrrbm')
    send('ffrr')
  elif char == 'z':
    send('mfrrfm')

def write(word):
  for char in word:
    draw(char)

def send(seq):
  for c in seq:
    con.write(c)

def connected():
  print "connected"

if __name__ == "__main__":
  callback = lambda afterconnect: connected()
  pool.apply_async(async_connect,args=[],callback=callback)

