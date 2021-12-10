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
    vx=np.array([])
    vy=np.array([])
    x=np.array([0])
    y=np.array([0])
    index=0
    vx=np.append(vx,20*np.cos(np.radians(j)))
    vy=np.append(vy,20*np.sin(np.radians(j)))
    for i in np.arange(0,5,h):
        vx=np.append(vx,vx[index]+h*ax)
        vy=np.append(vy,vy[index]+h*ay)
        x=np.append(x,x[index]+h*vx[index])
        y=np.append(y,y[index]+h*vy[index])
        index+=1
    plt.plot(x,y)
plt.xlim(-1,50)
plt.ylim(0)
plt.show()