import matplotlib.pyplot as plt

# 起始输入为左右边界
data = [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]
data = sorted(data)
print(data)
for i in range(len(data)):
    # i作为纵坐标
    # 左右边界为两侧横坐标
    x,y = data[i],[i,i]
    plt.plot(x,y)
plt.savefig('cmp.jpg')

plt.show()