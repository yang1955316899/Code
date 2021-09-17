import matplotlib.pyplot as plt
import pandas as pd

plt.rcParams['font.family'] = 'Microsoft YaHei'
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
data = pd.read_csv('./Titanic.csv')
female12 = data.Survived[data.Pclass != 3][data.Sex == 'female'].value_counts().sort_index()  # 未获救
male12 = data.Survived[data.Pclass != 3][data.Sex == 'male'].value_counts().sort_index()  # 获救
female3 = data.Survived[data.Pclass != 3][data.Sex == 'female'].value_counts().sort_index()  # 未获救
male3 = data.Survived[data.Pclass != 3][data.Sex == 'male'].value_counts().sort_index()  # 获救
plt.figure()
plt.subplot(2, 1, 1)
female12.plot(kind='bar')
plt.subplot(2, 2, 3)
plt.bar([0, 1], female3)
# plt.subplot(2, 2, 4)
# plt.bar(male12)
# plt.subplot(2, 2, 5)
# plt.bar(male3)

plt.show()
