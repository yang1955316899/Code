import matplotlib.pyplot as plt
import pandas as pd

plt.rcParams['font.family'] = 'Microsoft YaHei'
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
data = pd.read_csv('./Titanic.csv')
Survived_0 = data.Embarked[data.Survived == 0].value_counts().sort_index()
Survived_1 = data.Embarked[data.Survived == 1].value_counts().sort_index()
print(Survived_1)
plt.bar(['C', 'Q', 'S'], Survived_0, width=0.25, label='未获救')
plt.bar(['C', 'Q', 'S'], Survived_1, width=0.25, label='获救', bottom=Survived_0)
plt.legend()
plt.ylabel('遇难与获救人数')
plt.xlabel('港口')
plt.show()
