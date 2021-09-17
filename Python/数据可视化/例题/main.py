import matplotlib.pyplot as plt
fig = plt.figure(figsize=(15,8))
plt.axis('off')  #不显示画布的坐标轴
plt.title(u'根据舱等级和性别的获救情况')

at3 = fig.add_subplot(143)
FL = df['Survived'][df['Sex'] == 'male'][df['Pclass'] == 3].value_counts()
FL.plot.bar(label='FL',color='lightblue')
at3.set_xticklabels(['获救','未获救'],rotation=0)
at3.legend()

at4 = fig.add_subplot(144,sharey=at3)
FH = df['Survived'][df['Sex'] == 'male'][df['Pclass'] != 3].value_counts()
FH.plot.bar(label='FH',color='steelblue')
at4.set_xticklabels(['获救','未获救'],rotation=0)
at4.legend()

at1 = fig.add_subplot(141,sharey=at3)
ML = df['Survived'][df['Sex'] == 'female'][df['Pclass'] == 3].value_counts()
ML.plot.bar(label='ML',color='#FA2479')
at1.set_xticklabels(['获救','未获救'],rotation=0)
at1.legend()

at2 = fig.add_subplot(142,sharey=at3)
MH = df['Survived'][df['Sex'] == 'female'][df['Pclass'] != 3].value_counts()
MH.plot.bar(label='MH',color='pink')
at2.set_xticklabels(['获救','未获救'],rotation=0)
at2.legend()
plt.show()
