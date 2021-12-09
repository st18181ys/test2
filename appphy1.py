import math as mt
import numpy as np
import matplotlib.pyplot as plt

m=0.5
g=9.8
Fx=0
Fy=-m*g
x=np.array([0])
y=np.array([0])
ax=Fx/m
ay=Fy/m
vx=np.array([])
vy=np.array([])
h=0.01
index=0

# j：角度
# t：経過時間
for j in range(0,91,5):
    np.append(vx,20*np.cos(np.radians(j)))
    np.append(vy,20*np.sin(np.radians(j)))
    while y[index]>=0:
        np.append(vx,vx[index]+h*ax)
        np.append(vy,vy[index]+h*ay)
        np.append(x,x[index]+h*vx[index])
        np.append(y,y[index]+h*vy[index])
        index+=1
        if index>40:
            break