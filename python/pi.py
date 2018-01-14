import serial
import requests

s = serial.Serial('/dev/ttyUSB0')
server = "192.168.31.178"
while True:
    data = s.readline()
    response = requests.get(server+"?"+data)
