import numpy as np
import matplotlib.pyplot as plt 

x=np.arange(-5,5,0.1)
y=np.sin(x)

plt.plot(x,y)
plt.title("Smooth Spline Curve")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()