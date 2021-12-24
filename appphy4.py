import numpy as np
import matplotlib.pyplot as plt

def fx(t,vx):


def fy(t,vy):


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
    for i in np.arange(0,10,h):
        k1=ax*h
        k2=vx[index]+h*k1/2
        k3=vx[index]+h*k2/2
        k4=vx[index]+h*k3
        vx=np.append(vx,vx[index]+h*(k1+k2+k3+k4)/6)
        k1=ay*h
        k2=vy[index]+h*k1/2
        k3=vy[index]+h*k2/2
        k4=vy[index]+h*k3
        vy=np.append(vy,vy[index]+h*(k1+k2+k3+k4)/6)
        x=np.append(x,x[index]+h*vx[index])
        y=np.append(y,y[index]+h*vy[index])
        index+=1
    plt.plot(x,y)
plt.xlim()
plt.ylim()
plt.show()