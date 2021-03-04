from tkinter import *
import serial
import time

tk = Tk()
tk.title("Rubik's cube solver")

b_strana = []

m_strana = []

c_strana = []

z_strana = []

o_strana = []

y_strana = []

ser = serial.Serial('COM3', 9600)

data = ""

def resetujArduino():
    ser.setDTR(False)
    time.sleep(0.022)
    ser.setDTR(True)

def zapisPoleDoString():
    global data
    for barva in b_strana:
        data = data + barva

    for barva in m_strana:
        data = data + barva

    for barva in c_strana:
        data = data + barva

    for barva in z_strana:
        data = data + barva

    for barva in o_strana:
        data = data + barva

    for barva in y_strana:
        data = data + barva

    return data

def posliData():

    global data
    resetujArduino()
    zapisPoleDoString()
    time.sleep(20)
    print(ser.name)

    ser.write(data.encode("utf-8"))

    ser.close()






def znenaPrepis(b1,b2,b3,b4,b5,b6, b7,b8,b9,b10,b11,b12, b13, b14, b15):

    if b14["text"] =="Bílá strana":
        global b_strana

        if b1["text"] == "b":
            b_strana.insert(0,'b')
        elif b1["text"] == "m":
            b_strana.insert(0,'m')
        elif b1["text"] == "c":
            b_strana.insert(0,'c')
        elif b1["text"] == "z":
            b_strana.insert(0,'z')
        elif b1["text"] == "o":
            b_strana.insert(0,'o')
        elif b1["text"] == "y":
            b_strana.insert(0,'y')

        if b2["text"] == "b":
            b_strana.insert(1,'b')
        elif b2["text"] == "m":
            b_strana.insert(1,'m')
        elif b2["text"] == "c":
            b_strana.insert(1,'c')
        elif b2["text"] == "z":
            b_strana.insert(1,'z')
        elif b2["text"] == "o":
            b_strana.insert(1,'o')
        elif b2["text"] == "y":
            b_strana.insert(1,'y')

        if b3["text"] == "b":
            b_strana.insert(2,'b')
        elif b3["text"] == "m":
            b_strana.insert(2,'m')
        elif b3["text"] == "c":
            b_strana.insert(2,'c')
        elif b3["text"] == "z":
            b_strana.insert(2,'z')
        elif b3["text"] == "o":
            b_strana.insert(2,'o')
        elif b3["text"] == "y":
            b_strana.insert(2,'y')

        if b4["text"] == "b":
            b_strana.insert(3,'b')
        elif b4["text"] == "m":
            b_strana.insert(3,'m')
        elif b4["text"] == "c":
            b_strana.insert(3,'c')
        elif b4["text"] == "z":
            b_strana.insert(3,'z')
        elif b4["text"] == "o":
            b_strana.insert(3,'o')
        elif b4["text"] == "y":
            b_strana.insert(3,'y')

        b_strana.insert(4, 'b')


        if b6["text"] == "b":
            b_strana.insert(5,'b')
        elif b6["text"] == "m":
            b_strana.insert(5,'m')
        elif b6["text"] == "c":
            b_strana.insert(5,'c')
        elif b6["text"] == "z":
            b_strana.insert(5,'z')
        elif b6["text"] == "o":
            b_strana.insert(5,'o')
        elif b6["text"] == "y":
            b_strana.insert(5,'y')

        if b7["text"] == "b":
            b_strana.insert(6,'b')
        elif b7["text"] == "m":
            b_strana.insert(6,'m')
        elif b7["text"] == "c":
            b_strana.insert(6,'c')
        elif b7["text"] == "z":
            b_strana.insert(6,'z')
        elif b7["text"] == "o":
            b_strana.insert(6,'o')
        elif b7["text"] == "y":
            b_strana.insert(6,'y')

        if b8["text"] == "b":
            b_strana.insert(7,'b')
        elif b8["text"] == "m":
            b_strana.insert(7,'m')
        elif b8["text"] == "c":
            b_strana.insert(7,'c')
        elif b8["text"] == "z":
            b_strana.insert(7,'z')
        elif b8["text"] == "o":
            b_strana.insert(7,'o')
        elif b8["text"] == "y":
            b_strana.insert(7,'y')

        if b9["text"] == "b":
            b_strana.insert(8,'b')
        elif b9["text"] == "m":
            b_strana.insert(8,'m')
        elif b9["text"] == "c":
            b_strana.insert(8,'c')
        elif b9["text"] == "z":
            b_strana.insert(8,'z')
        elif b9["text"] == "o":
            b_strana.insert(8,'o')
        elif b9["text"] == "y":
            b_strana.insert(8,'y')

        b14.configure( text = 'Modrá strana')
        b1.configure( text = 'b', bg = "white")
        b2.configure(text='b', bg="white")
        b3.configure(text='b', bg="white")
        b4.configure(text='b', bg="white")
        b5.configure(text='m', bg="blue")
        b6.configure(text='b', bg="white")
        b7.configure(text='b', bg="white")
        b8.configure(text='b', bg="white")
        b9.configure(text='b', bg="white")
        b10.configure( bg="white")
        b11.configure(bg="dark orange")
        b12.configure(bg="red")
        b13.configure(bg="yellow")

        array_length = len(b_strana)
        for x in range(array_length):
            print(b_strana[x])

    elif b14["text"] =="Modrá strana":
        global m_strana

        if b1["text"] == "b":
            m_strana.insert(0,'b')
        elif b1["text"] == "m":
            m_strana.insert(0,'m')
        elif b1["text"] == "c":
            m_strana.insert(0,'c')
        elif b1["text"] == "z":
            m_strana.insert(0,'z')
        elif b1["text"] == "o":
            m_strana.insert(0,'o')
        elif b1["text"] == "y":
            m_strana.insert(0,'y')

        if b2["text"] == "b":
            m_strana.insert(1,'b')
        elif b2["text"] == "m":
            m_strana.insert(1,'m')
        elif b2["text"] == "c":
            m_strana.insert(1,'c')
        elif b2["text"] == "z":
            m_strana.insert(1,'z')
        elif b2["text"] == "o":
            m_strana.insert(1,'o')
        elif b2["text"] == "y":
            m_strana.insert(1,'y')

        if b3["text"] == "b":
            m_strana.insert(2,'b')
        elif b3["text"] == "m":
            m_strana.insert(2,'m')
        elif b3["text"] == "c":
            m_strana.insert(2,'c')
        elif b3["text"] == "z":
            m_strana.insert(2,'z')
        elif b3["text"] == "o":
            m_strana.insert(2,'o')
        elif b3["text"] == "y":
            m_strana.insert(2,'y')

        if b4["text"] == "b":
            m_strana.insert(3,'b')
        elif b4["text"] == "m":
            m_strana.insert(3,'m')
        elif b4["text"] == "c":
            m_strana.insert(3,'c')
        elif b4["text"] == "z":
            m_strana.insert(3,'z')
        elif b4["text"] == "o":
            m_strana.insert(3,'o')
        elif b4["text"] == "y":
            m_strana.insert(3,'y')

        m_strana.insert(4, 'm')


        if b6["text"] == "b":
            m_strana.insert(5,'b')
        elif b6["text"] == "m":
            m_strana.insert(5,'m')
        elif b6["text"] == "c":
            m_strana.insert(5,'c')
        elif b6["text"] == "z":
            m_strana.insert(5,'z')
        elif b6["text"] == "o":
            m_strana.insert(5,'o')
        elif b6["text"] == "y":
            m_strana.insert(5,'y')

        if b7["text"] == "b":
            m_strana.insert(6,'b')
        elif b7["text"] == "m":
            m_strana.insert(6,'m')
        elif b7["text"] == "c":
            m_strana.insert(6,'c')
        elif b7["text"] == "z":
            m_strana.insert(6,'z')
        elif b7["text"] == "o":
            m_strana.insert(6,'o')
        elif b7["text"] == "y":
            m_strana.insert(6,'y')

        if b8["text"] == "b":
            m_strana.insert(7,'b')
        elif b8["text"] == "m":
            m_strana.insert(7,'m')
        elif b8["text"] == "c":
            m_strana.insert(7,'c')
        elif b8["text"] == "z":
            m_strana.insert(7,'z')
        elif b8["text"] == "o":
            m_strana.insert(7,'o')
        elif b8["text"] == "y":
            m_strana.insert(7,'y')

        if b9["text"] == "b":
            m_strana.insert(8,'b')
        elif b9["text"] == "m":
            m_strana.insert(8,'m')
        elif b9["text"] == "c":
            m_strana.insert(8,'c')
        elif b9["text"] == "z":
            m_strana.insert(8,'z')
        elif b9["text"] == "o":
            m_strana.insert(8,'o')
        elif b9["text"] == "y":
            m_strana.insert(8,'y')

        b14.configure( text = 'Červená strana')
        b1.configure( text = 'b', bg = "white")
        b2.configure(text='b', bg="white")
        b3.configure(text='b', bg="white")
        b4.configure(text='b', bg="white")
        b5.configure(text='c', bg="red")
        b6.configure(text='b', bg="white")
        b7.configure(text='b', bg="white")
        b8.configure(text='b', bg="white")
        b9.configure(text='b', bg="white")
        b10.configure( bg="white")
        b11.configure(bg="blue")
        b12.configure(bg="green")
        b13.configure(bg="yellow")

        array_length = len(m_strana)
        for x in range(array_length):
            print(m_strana[x])


    elif b14["text"] =="Červená strana":
        global c_strana

        if b1["text"] == "b":
            c_strana.insert(0,'b')
        elif b1["text"] == "m":
            c_strana.insert(0,'m')
        elif b1["text"] == "c":
            c_strana.insert(0,'c')
        elif b1["text"] == "z":
            c_strana.insert(0,'z')
        elif b1["text"] == "o":
            c_strana.insert(0,'o')
        elif b1["text"] == "y":
            c_strana.insert(0,'y')

        if b2["text"] == "b":
            c_strana.insert(1,'b')
        elif b2["text"] == "m":
            c_strana.insert(1,'m')
        elif b2["text"] == "c":
            c_strana.insert(1,'c')
        elif b2["text"] == "z":
            c_strana.insert(1,'z')
        elif b2["text"] == "o":
            c_strana.insert(1,'o')
        elif b2["text"] == "y":
            c_strana.insert(1,'y')

        if b3["text"] == "b":
            c_strana.insert(2,'b')
        elif b3["text"] == "m":
            c_strana.insert(2,'m')
        elif b3["text"] == "c":
            c_strana.insert(2,'c')
        elif b3["text"] == "z":
            c_strana.insert(2,'z')
        elif b3["text"] == "o":
            c_strana.insert(2,'o')
        elif b3["text"] == "y":
            c_strana.insert(2,'y')

        if b4["text"] == "b":
            c_strana.insert(3,'b')
        elif b4["text"] == "m":
            c_strana.insert(3,'m')
        elif b4["text"] == "c":
            c_strana.insert(3,'c')
        elif b4["text"] == "z":
            c_strana.insert(3,'z')
        elif b4["text"] == "o":
            c_strana.insert(3,'o')
        elif b4["text"] == "y":
            c_strana.insert(3,'y')

        c_strana.insert(4, 'c')


        if b6["text"] == "b":
            c_strana.insert(5,'b')
        elif b6["text"] == "m":
            c_strana.insert(5,'m')
        elif b6["text"] == "c":
            c_strana.insert(5,'c')
        elif b6["text"] == "z":
            c_strana.insert(5,'z')
        elif b6["text"] == "o":
            c_strana.insert(5,'o')
        elif b6["text"] == "y":
            c_strana.insert(5,'y')

        if b7["text"] == "b":
            c_strana.insert(6,'b')
        elif b7["text"] == "m":
            c_strana.insert(6,'m')
        elif b7["text"] == "c":
            c_strana.insert(6,'c')
        elif b7["text"] == "z":
            c_strana.insert(6,'z')
        elif b7["text"] == "o":
            c_strana.insert(6,'o')
        elif b7["text"] == "y":
            c_strana.insert(6,'y')

        if b8["text"] == "b":
            c_strana.insert(7,'b')
        elif b8["text"] == "m":
            c_strana.insert(7,'m')
        elif b8["text"] == "c":
            c_strana.insert(7,'c')
        elif b8["text"] == "z":
            c_strana.insert(7,'z')
        elif b8["text"] == "o":
            c_strana.insert(7,'o')
        elif b8["text"] == "y":
            c_strana.insert(7,'y')

        if b9["text"] == "b":
            c_strana.insert(8,'b')
        elif b9["text"] == "m":
            c_strana.insert(8,'m')
        elif b9["text"] == "c":
            c_strana.insert(8,'c')
        elif b9["text"] == "z":
            c_strana.insert(8,'z')
        elif b9["text"] == "o":
            c_strana.insert(8,'o')
        elif b9["text"] == "y":
            c_strana.insert(8,'y')

        b14.configure( text = 'Zelená strana')
        b1.configure( text = 'b', bg = "white")
        b2.configure(text='b', bg="white")
        b3.configure(text='b', bg="white")
        b4.configure(text='b', bg="white")
        b5.configure(text='z', bg="green")
        b6.configure(text='b', bg="white")
        b7.configure(text='b', bg="white")
        b8.configure(text='b', bg="white")
        b9.configure(text='b', bg="white")
        b10.configure( bg="white")
        b11.configure(bg="red")
        b12.configure(bg="dark orange")
        b13.configure(bg="yellow")

        array_length = len(c_strana)
        for x in range(array_length):
            print(c_strana[x])


    elif b14["text"] == "Zelená strana":
        global z_strana

        if b1["text"] == "b":
            z_strana.insert(0, 'b')
        elif b1["text"] == "m":
            z_strana.insert(0, 'm')
        elif b1["text"] == "c":
            z_strana.insert(0, 'c')
        elif b1["text"] == "z":
            z_strana.insert(0, 'z')
        elif b1["text"] == "o":
            z_strana.insert(0, 'o')
        elif b1["text"] == "y":
            z_strana.insert(0, 'y')

        if b2["text"] == "b":
            z_strana.insert(1, 'b')
        elif b2["text"] == "m":
            z_strana.insert(1, 'm')
        elif b2["text"] == "c":
            z_strana.insert(1, 'c')
        elif b2["text"] == "z":
            z_strana.insert(1, 'z')
        elif b2["text"] == "o":
            z_strana.insert(1, 'o')
        elif b2["text"] == "y":
            z_strana.insert(1, 'y')

        if b3["text"] == "b":
            z_strana.insert(2, 'b')
        elif b3["text"] == "m":
            z_strana.insert(2, 'm')
        elif b3["text"] == "c":
            z_strana.insert(2, 'c')
        elif b3["text"] == "z":
            z_strana.insert(2, 'z')
        elif b3["text"] == "o":
            z_strana.insert(2, 'o')
        elif b3["text"] == "y":
            z_strana.insert(2, 'y')

        if b4["text"] == "b":
            z_strana.insert(3, 'b')
        elif b4["text"] == "m":
            z_strana.insert(3, 'm')
        elif b4["text"] == "c":
            z_strana.insert(3, 'c')
        elif b4["text"] == "z":
            z_strana.insert(3, 'z')
        elif b4["text"] == "o":
            z_strana.insert(3, 'o')
        elif b4["text"] == "y":
            z_strana.insert(3, 'y')

        z_strana.insert(4, 'z')

        if b6["text"] == "b":
            z_strana.insert(5, 'b')
        elif b6["text"] == "m":
            z_strana.insert(5, 'm')
        elif b6["text"] == "c":
            z_strana.insert(5, 'c')
        elif b6["text"] == "z":
            z_strana.insert(5, 'z')
        elif b6["text"] == "o":
            z_strana.insert(5, 'o')
        elif b6["text"] == "y":
            z_strana.insert(5, 'y')

        if b7["text"] == "b":
            z_strana.insert(6, 'b')
        elif b7["text"] == "m":
            z_strana.insert(6, 'm')
        elif b7["text"] == "c":
            z_strana.insert(6, 'c')
        elif b7["text"] == "z":
            z_strana.insert(6, 'z')
        elif b7["text"] == "o":
            z_strana.insert(6, 'o')
        elif b7["text"] == "y":
            z_strana.insert(6, 'y')

        if b8["text"] == "b":
            z_strana.insert(7, 'b')
        elif b8["text"] == "m":
            z_strana.insert(7, 'm')
        elif b8["text"] == "c":
            z_strana.insert(7, 'c')
        elif b8["text"] == "z":
            z_strana.insert(7, 'z')
        elif b8["text"] == "o":
            z_strana.insert(7, 'o')
        elif b8["text"] == "y":
            z_strana.insert(7, 'y')

        if b9["text"] == "b":
            z_strana.insert(8, 'b')
        elif b9["text"] == "m":
            z_strana.insert(8, 'm')
        elif b9["text"] == "c":
            z_strana.insert(8, 'c')
        elif b9["text"] == "z":
            z_strana.insert(8, 'z')
        elif b9["text"] == "o":
            z_strana.insert(8, 'o')
        elif b9["text"] == "y":
            z_strana.insert(8, 'y')

        b14.configure(text='Oranžová strana')
        b1.configure(text='b', bg="white")
        b2.configure(text='b', bg="white")
        b3.configure(text='b', bg="white")
        b4.configure(text='b', bg="white")
        b5.configure(text='o', bg="dark orange")
        b6.configure(text='b', bg="white")
        b7.configure(text='b', bg="white")
        b8.configure(text='b', bg="white")
        b9.configure(text='b', bg="white")
        b10.configure(bg="white")
        b11.configure(bg="green")
        b12.configure(bg="blue")
        b13.configure(bg="yellow")

        array_length = len(z_strana)
        for x in range(array_length):
            print(z_strana[x])

    elif b14["text"] == "Oranžová strana":
        global o_strana

        if b1["text"] == "b":
            o_strana.insert(0, 'b')
        elif b1["text"] == "m":
            o_strana.insert(0, 'm')
        elif b1["text"] == "c":
            o_strana.insert(0, 'c')
        elif b1["text"] == "z":
            o_strana.insert(0, 'z')
        elif b1["text"] == "o":
            o_strana.insert(0, 'o')
        elif b1["text"] == "y":
            o_strana.insert(0, 'y')

        if b2["text"] == "b":
            o_strana.insert(1, 'b')
        elif b2["text"] == "m":
            o_strana.insert(1, 'm')
        elif b2["text"] == "c":
            o_strana.insert(1, 'c')
        elif b2["text"] == "z":
            o_strana.insert(1, 'z')
        elif b2["text"] == "o":
            o_strana.insert(1, 'o')
        elif b2["text"] == "y":
            o_strana.insert(1, 'y')

        if b3["text"] == "b":
            o_strana.insert(2, 'b')
        elif b3["text"] == "m":
            o_strana.insert(2, 'm')
        elif b3["text"] == "c":
            o_strana.insert(2, 'c')
        elif b3["text"] == "z":
            o_strana.insert(2, 'z')
        elif b3["text"] == "o":
            o_strana.insert(2, 'o')
        elif b3["text"] == "y":
            o_strana.insert(2, 'y')

        if b4["text"] == "b":
            o_strana.insert(3, 'b')
        elif b4["text"] == "m":
            o_strana.insert(3, 'm')
        elif b4["text"] == "c":
            o_strana.insert(3, 'c')
        elif b4["text"] == "z":
            o_strana.insert(3, 'z')
        elif b4["text"] == "o":
            o_strana.insert(3, 'o')
        elif b4["text"] == "y":
            o_strana.insert(3, 'y')

        o_strana.insert(4, 'o')

        if b6["text"] == "b":
            o_strana.insert(5, 'b')
        elif b6["text"] == "m":
            o_strana.insert(5, 'm')
        elif b6["text"] == "c":
            o_strana.insert(5, 'c')
        elif b6["text"] == "z":
            o_strana.insert(5, 'z')
        elif b6["text"] == "o":
            o_strana.insert(5, 'o')
        elif b6["text"] == "y":
            o_strana.insert(5, 'y')

        if b7["text"] == "b":
            o_strana.insert(6, 'b')
        elif b7["text"] == "m":
            o_strana.insert(6, 'm')
        elif b7["text"] == "c":
            o_strana.insert(6, 'c')
        elif b7["text"] == "z":
            o_strana.insert(6, 'z')
        elif b7["text"] == "o":
            o_strana.insert(6, 'o')
        elif b7["text"] == "y":
            o_strana.insert(6, 'y')

        if b8["text"] == "b":
            o_strana.insert(7, 'b')
        elif b8["text"] == "m":
            o_strana.insert(7, 'm')
        elif b8["text"] == "c":
            o_strana.insert(7, 'c')
        elif b8["text"] == "z":
            o_strana.insert(7, 'z')
        elif b8["text"] == "o":
            o_strana.insert(7, 'o')
        elif b8["text"] == "y":
            o_strana.insert(7, 'y')

        if b9["text"] == "b":
            o_strana.insert(8, 'b')
        elif b9["text"] == "m":
            o_strana.insert(8, 'm')
        elif b9["text"] == "c":
            o_strana.insert(8, 'c')
        elif b9["text"] == "z":
            o_strana.insert(8, 'z')
        elif b9["text"] == "o":
            o_strana.insert(8, 'o')
        elif b9["text"] == "y":
            o_strana.insert(8, 'y')

        b14.configure(text='Žluta strana')
        b1.configure(text='b', bg="white")
        b2.configure(text='b', bg="white")
        b3.configure(text='b', bg="white")
        b4.configure(text='b', bg="white")
        b5.configure(text='y', bg="yellow")
        b6.configure(text='b', bg="white")
        b7.configure(text='b', bg="white")
        b8.configure(text='b', bg="white")
        b9.configure(text='b', bg="white")
        b10.configure(bg="green")
        b11.configure(bg="red")
        b12.configure(bg="dark orange")
        b13.configure(bg="blue")

        array_length = len(o_strana)
        for x in range(array_length):
            print(o_strana[x])

    elif b14["text"] == "Žluta strana":
        global y_strana

        if b1["text"] == "b":
            y_strana.insert(0, 'b')
        elif b1["text"] == "m":
            y_strana.insert(0, 'm')
        elif b1["text"] == "c":
            y_strana.insert(0, 'c')
        elif b1["text"] == "z":
            y_strana.insert(0, 'z')
        elif b1["text"] == "o":
            y_strana.insert(0, 'o')
        elif b1["text"] == "y":
            y_strana.insert(0, 'y')

        if b2["text"] == "b":
            y_strana.insert(1, 'b')
        elif b2["text"] == "m":
            y_strana.insert(1, 'm')
        elif b2["text"] == "c":
            y_strana.insert(1, 'c')
        elif b2["text"] == "z":
            y_strana.insert(1, 'z')
        elif b2["text"] == "o":
            y_strana.insert(1, 'o')
        elif b2["text"] == "y":
            y_strana.insert(1, 'y')

        if b3["text"] == "b":
            y_strana.insert(2, 'b')
        elif b3["text"] == "m":
            y_strana.insert(2, 'm')
        elif b3["text"] == "c":
            y_strana.insert(2, 'c')
        elif b3["text"] == "z":
            y_strana.insert(2, 'z')
        elif b3["text"] == "o":
            y_strana.insert(2, 'o')
        elif b3["text"] == "y":
            y_strana.insert(2, 'y')

        if b4["text"] == "b":
            y_strana.insert(3, 'b')
        elif b4["text"] == "m":
            y_strana.insert(3, 'm')
        elif b4["text"] == "c":
            y_strana.insert(3, 'c')
        elif b4["text"] == "z":
            y_strana.insert(3, 'z')
        elif b4["text"] == "o":
            y_strana.insert(3, 'o')
        elif b4["text"] == "y":
            y_strana.insert(3, 'y')

        y_strana.insert(4, 'y')

        if b6["text"] == "b":
            y_strana.insert(5, 'b')
        elif b6["text"] == "m":
            y_strana.insert(5, 'm')
        elif b6["text"] == "c":
            y_strana.insert(5, 'c')
        elif b6["text"] == "z":
            y_strana.insert(5, 'z')
        elif b6["text"] == "o":
            y_strana.insert(5, 'o')
        elif b6["text"] == "y":
            y_strana.insert(5, 'y')

        if b7["text"] == "b":
            y_strana.insert(6, 'b')
        elif b7["text"] == "m":
            y_strana.insert(6, 'm')
        elif b7["text"] == "c":
            y_strana.insert(6, 'c')
        elif b7["text"] == "z":
            y_strana.insert(6, 'z')
        elif b7["text"] == "o":
            y_strana.insert(6, 'o')
        elif b7["text"] == "y":
            y_strana.insert(6, 'y')

        if b8["text"] == "b":
            y_strana.insert(7, 'b')
        elif b8["text"] == "m":
            y_strana.insert(7, 'm')
        elif b8["text"] == "c":
            y_strana.insert(7, 'c')
        elif b8["text"] == "z":
            y_strana.insert(7, 'z')
        elif b8["text"] == "o":
            y_strana.insert(7, 'o')
        elif b8["text"] == "y":
            y_strana.insert(7, 'y')

        if b9["text"] == "b":
            y_strana.insert(8, 'b')
        elif b9["text"] == "m":
            y_strana.insert(8, 'm')
        elif b9["text"] == "c":
            y_strana.insert(8, 'c')
        elif b9["text"] == "z":
            y_strana.insert(8, 'z')
        elif b9["text"] == "o":
            y_strana.insert(8, 'o')
        elif b9["text"] == "y":
            y_strana.insert(8, 'y')

        b14.configure(text='Klikni na druhé tlačítko', state = "disabled")
        b1.configure(text='b', bg="white", state = "disabled")
        b2.configure(text='b', bg="white", state = "disabled")
        b3.configure(text='b', bg="white", state = "disabled")
        b4.configure(text='b', bg="white", state = "disabled")
        b5.configure(text='y', bg="yellow")
        b6.configure(text='b', bg="white", state = "disabled")
        b7.configure(text='b', bg="white", state = "disabled")
        b8.configure(text='b', bg="white", state = "disabled")
        b9.configure(text='b', bg="white", state = "disabled")
        b10.configure(bg="green")
        b11.configure(bg="red")
        b12.configure(bg="dark orange")
        b13.configure(bg="blue")
        b15.configure(state="normal")

        array_length = len(y_strana)
        for x in range(array_length):
            print(y_strana[x])




def zmenBarvu(buttons):
    if buttons["bg"] == "white":
        buttons.configure(bg = "blue", text = 'm')

    elif buttons["bg"] == "blue":

        buttons.configure(bg = "red", text = 'c')

    elif buttons["bg"] == "red":

        buttons.configure(bg = "green", text = 'z')

    elif buttons["bg"] == "green":

        buttons.configure(bg = "dark orange", text = 'o')

    elif buttons["bg"] == "dark orange":

        buttons.configure(bg = "yellow", text = 'y')

    elif buttons["bg"] == "yellow":

        buttons.configure(bg = "white", text = 'b')








button1 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button1))
button1.grid(row=2, column=1)

button2 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button2))
button2.grid(row=2, column=2)

button3 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button3))
button3.grid(row=2, column=3)

button4 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button4))
button4.grid(row=3, column=1)

button5 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 state = "disabled")
button5.grid(row=3, column=2)

button6 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button6))
button6.grid(row=3, column=3)

button7 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button7))
button7.grid(row=4, column=1)

button8 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button8))
button8.grid(row=4, column=2)

button9 = Button(tk, text='b', font='Times 20 bold', bg='white', fg='black', height=4, width=8,
                 command=lambda: zmenBarvu(button9))
button9.grid(row=4, column=3)

button10 = Button(tk, text=' ', font='Times 20 bold', bg='dark orange', fg='black', height=4, width=8,
                 state = "disabled")
button10.grid(row=1, column=2)

button11 = Button(tk, text=' ', font='Times 20 bold', bg='blue', fg='black', height=4, width=8,
                 state = "disabled")
button11.grid(row=3, column=0)

button12 = Button(tk, text=' ', font='Times 20 bold', bg='green', fg='black', height=4, width=8,
                 state = "disabled")
button12.grid(row=3, column=4)

button13 = Button(tk, text=' ', font='Times 20 bold', bg='red', fg='black', height=4, width=8,
                 state = "disabled")
button13.grid(row=5, column=2)

button14 = Button(tk, text='Bílá strana', font='Times 20 bold', bg='white', fg='black', height=4, width=24,
                 command=lambda: znenaPrepis(button1,button2,button3,button4,button5,button6,button7,button8,button9,button10,button11,button12,button13,button14, button15))
button14.grid(row=5, column= 5)

button15 = Button(tk, text='Pošli data', font='Times 20 bold', bg='white', fg='black', height=4, width=24, state = "disabled",
                 command=posliData)
button15.grid(row=5, column= 6)

tk.mainloop()











