import serial
import time

arduino= serial.Serial('/dev/ttyUSB0',9600,timeout=1)
time.sleep(2)

print("Type 1:(LED ON), 0:(LED OFF), 'q' to quit")

while True:
	cmd= input("Enter command:")
	if(cmd=='q'):
		break
	arduino.write(cmd.encode())
	time.sleep(0.1)
	if arduino.in_waiting >0:
		response= arduino.readline().decode().strip()
		print("Arduino: ",response)

arduino.close()
