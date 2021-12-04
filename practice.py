import numpy as np
import matplotlib.pyplot as plt

means=[1,2,3,4,5,6,7,8,9,10]

x=np.arange(len(means))

plt.bar(x,means,width=0.5)
plt.show()