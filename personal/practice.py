import matplotlib.pyplot as plt
 
# x、yデータ
x = range(20)
y = range(20)
 
# 点(x, y)がもつ量
z = range(20)
 
# カラーマップ
cm = plt.cm.get_cmap('Blues')
# figureを生成する
fig = plt.figure()
 
# axをfigureに設定する
ax = fig.add_subplot(1, 1, 1)
 
# axに散布図を描画、戻り値にPathCollectionを得る
mappable = ax.scatter(x, y, c=z, vmin=0, vmax=100, s=35, cmap=cm)
 
# カラーバーを付加
fig.colorbar(mappable, ax=ax)
 
# 表示
plt.show()
