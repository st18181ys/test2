import matplotlib.pyplot as plt
import random as ra
data=ra.sample(range(100),10)
x=list(range(1,len(data)+1))
fig=plt.figure()
b=plt.bar(x,data)
plt.draw()
plt.show()