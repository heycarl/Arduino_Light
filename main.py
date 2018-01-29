from Tkinter import *
import cfg
import requests
def b1_action():
    print(cfg.b1)
    if cfg.b1 == True:
        button1['text'] = 'False'
        r = requests.get("http://192.168.8.113/r1off")
        cfg.b1 = False
    else:
        button1['text'] = 'True'
        r = requests.get("http://192.168.8.113/r1on")
        cfg.b1 = True
        print(cfg.b1)

def b2_action():
    print(cfg.b2)
    if cfg.b2 == True:
        button2['text'] = 'False'
        r = requests.get("http://192.168.8.113/r2off")
        cfg.b2 = False
    else:
        button2['text'] = 'True'
        r = requests.get("http://192.168.8.113/r2on")
        cfg.b2 = True
        print(cfg.b2)

def b3_action():
    print(cfg.b3)
    if cfg.b3 == True:
        button3['text'] = 'False'
        r = requests.get("http://192.168.8.113/r3off")
        cfg.b3 = False
    else:
        button3['text'] = 'True'
        r = requests.get("http://192.168.8.113/r3on")
        cfg.b3 = True
        print(cfg.b3)

def b4_action():
    print(cfg.b4)
    if cfg.b4 == True:
        button4['text'] = 'False'
        r = requests.get("http://192.168.8.113/r4off")
        cfg.b4 = False
    else:
        button4['text'] = 'True'
        r = requests.get("http://192.168.8.113/r4on")
        cfg.b4 = True
        print(cfg.b4)

def b5_action():
    print("Click")
    requests.get("http://192.168.8.113/rgb?red=" + str(scale1.get()) + "&green=" + str(scale2.get()) + "&blue=" + str(scale3.get()))

root = Tk()
root.geometry('800x600')
button1 = Button(text=str(cfg.b1), command=b1_action)
button2 = Button(text=str(cfg.b2), command=b2_action)
button3 = Button(text=str(cfg.b3), command=b3_action)
button4 = Button(text=str(cfg.b4), command=b4_action)
button5 = Button(text="Accept", command=b5_action)
scale1 = Scale(root,orient=VERTICAL,length=300,from_=00,to=255,tickinterval=0,resolution=1)
scale2 = Scale(root,orient=VERTICAL,length=300,from_=00,to=255,tickinterval=0,resolution=1)
scale3 = Scale(root,orient=VERTICAL,length=300,from_=00,to=255,tickinterval=0,resolution=1)
button1.grid(row=1, column=1)
button2.grid(row=1, column=2)
button3.grid(row=1, column=3)
button4.grid(row=1, column=4)
button5.grid(row=3, column=2)
scale1.grid(row=2, column=1)
scale2.grid(row=2, column=2)
scale3.grid(row=2, column=3)
root.mainloop()
