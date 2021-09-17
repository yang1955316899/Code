import matplotlib.pyplot as plt
import pandas as pd

plt.rcParams['font.family'] = 'Microsoft YaHei'
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
data = pd.read_csv('./Titanic.csv')
male = (data.Sex == 'male').sum()
female = (data.Sex == 'female').sum()
print(male, female)
plt.pie([male, female], labels=['男性', '女性'], autopct='%1.2f%%', explode=[0.1, 0])
plt.title('男女乘客比例')
plt.legend(loc='best')
plt.show()