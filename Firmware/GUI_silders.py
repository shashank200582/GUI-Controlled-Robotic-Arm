import tkinter as tk
import serial
import time

# Update this port if needed (check with ls /dev/ttyACM*)
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
time.sleep(2)  # wait for Arduino to initialize

def send_angles():
    angles = [s1.get(), s2.get(), s3.get(), s4.get(), s5.get()]
    data = ','.join(map(str, angles)) + '\n'
    arduino.write(data.encode())

root = tk.Tk()
root.title("Servo Controller")
root.geometry("400x400")

tk.Label(root, text="Servo 1").pack()
s1 = tk.Scale(root, from_=0, to=180, orient='horizontal', command=lambda x: send_angles())
s1.pack()

tk.Label(root, text="Servo 2").pack()
s2 = tk.Scale(root, from_=0, to=180, orient='horizontal', command=lambda x: send_angles())
s2.pack()

tk.Label(root, text="Servo 3").pack()
s3 = tk.Scale(root, from_=0, to=180, orient='horizontal', command=lambda x: send_angles())
s3.pack()

tk.Label(root, text="Servo 4").pack()
s4 = tk.Scale(root, from_=0, to=180, orient='horizontal', command=lambda x: send_angles())
s4.pack()

tk.Label(root, text="Servo 5").pack()
s5 = tk.Scale(root, from_=0, to=180, orient='horizontal', command=lambda x: send_angles())
s5.pack()

root.mainloop()
