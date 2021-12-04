import numpy as np
import pandas as pd
import sklearn
from sklearn.decompositon import PCA
import matplotlib.pyplot as plt

df=pd.reasd_csv('exam.csv')
df2=df[['国語','社会','数学','理科','音楽','美術','体育','技術','英語']]
display(df2)

pca=PCA()
feature=pca.fit(df2)

feature=pca.transform(df2)

plt.figure(figsize=(8,6))
plt.scatter(feature[:,0],feature[:,1],c=list(df.iloc[:,0]),s=30,cmap='Blues')
plt.colorbar()
plt.grid()
plt.xlabel("PC1")
plt.ylabel("PC2")
plt.show()

pca.explained_variance_ratio_

plt.figure(1,figsize=(8,6))
plt.bar(df2.columns,pca.explained_variance_ratio_,alpha=0.5,align='center')
plt.step(df2.columns,pca.explained_variance_ratio_.cumsum(),where='mid')
plt.ylabel('Explained varience ratio',size=12)
plt.xlabel('Principal components',size=12)

pca.explained_variance_ratio_