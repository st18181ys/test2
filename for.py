import numpy as np

x1=2
x2=1
x3=0
y1=1.5
y2=1
y3=1
a=np.array([x1,y1])
b=np.array([x2,y2])
c=np.array([x3,y3])

vec_a=a-b
vec_c=c-b

length_vec_a=np.linalg.norm(vec_a)
length_vec_c=np.linalg.norm(vec_c)
inner_product=np.inner(vec_a,vec_c)
cos=inner_product/(length_vec_a*length_vec_c)

rad=np.arccos(cos)

degree=np.rad2deg(rad)

print(length_vec_a)
print(length_vec_c)
print(inner_product)
print(cos)
print(degree)