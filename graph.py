import matplotlib.pyplot as plt
import numpy as np
from database import database

db=database()
dict_list=[]
people=[]
for i in range(0,4):
    dict_list=db.read()
    people[i]=dict_list[0]["count"]
time=["time1","time2","time3","current","from_now_on"]
number=people
ave=sum(people)/len(people)
number.append(ave)
plt.title(" People ")
plt.plot(time,number,marker="o",color="black",linestyle="dashdot")
plt.xlabel("time")
plt.ylabel("number")
plt.grid(True)
plt.show()