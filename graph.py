import matplotlib.pyplot as plt
import numpy as np

left=np.array(["40","30","20","10","0"])
height=np.array([100,200,500,300,400])
plt.title(" People ")
plt.plot(left,height,marker="o",color="black",linestyle="dashdot")
plt.xlabel("time")
plt.ylabel("number")
plt.grid(True)
plt.show()