import matplotlib.pyplot as plt
import numpy as np
from database import database

db=database()

left=np.array([1,2,3,4,5])
height=np.array([100,200,500,300,400])
plt.title(" People ")
plt.plot(left,height,marker="o",color="black",linestyle="dashdot")
plt.xlabel("time")
plt.ylabel("number")
plt.grid(True)
plt.show()