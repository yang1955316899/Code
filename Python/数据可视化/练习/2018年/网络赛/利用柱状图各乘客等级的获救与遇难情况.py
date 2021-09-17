import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

plt.rcParams['font.family'] = 'Microsoft YaHei'
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
data = pd.read_csv('./Titanic.csv')
Survived_0 = data.Pclass[data.Survived == 0].value_counts().sort_index()  # 未获救
Survived_1 = data.Pclass[data.Survived == 1].value_counts().sort_index()  # 获救
print(Survived_0, Survived_1)
x = np.arange(1, 4)
plt.bar(x, Survived_0, width=0.25, label='未获救')
plt.bar(x, Survived_1, width=0.25, label='获救', bottom=Survived_0)
plt.legend()
plt.xticks([1.0, 2.0, 3.0])
plt.ylabel('人数')
plt.xlabel('乘客等级')
plt.show()
