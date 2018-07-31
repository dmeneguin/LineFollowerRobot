import serial
import numpy as np
import matplotlib.pyplot as plt

SERIAL_PORT = 'COM3'
SERIAL_RATE = 9600

def main():
    fig = plt.gcf()
    fig.show()
    fig.canvas.draw()
    ser = serial.Serial(SERIAL_PORT, SERIAL_RATE)
    while True:
        reading = ser.readline().decode('utf-8')
        values = map(int,reading.split())
        plt.clf()   
        plt.axis([0, 127, min(values) - 200, max(values) + 200])
        i = 0
        for v in values:
			plt.scatter(i, v)
			i = i + 1
        fig.canvas.draw()

if __name__ == "__main__":
    main()
