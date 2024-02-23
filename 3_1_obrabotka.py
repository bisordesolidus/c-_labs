import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import math

afile = open("freq_used_results_A.txt")
bfile = open("freq_used_results_B.txt")
cfile = open("freq_used_results_C.txt")

alines = afile.readlines()
blines = bfile.readlines()
clines = cfile.readlines()

atime = []
btime = []
ctime = []
an = []
bn=[]
cn=[]
for line in alines:
    s, t = (map(float, line.split(';')))
    atime.append(t)
    an.append(s)
for line in blines:
    s, t = (map(float, line.split(';')))
    btime.append(t)
    bn.append(s)
for line in clines:
    s, t = (map(float, line.split(';')))
    ctime.append(t)
    cn.append(s)

X=np.linspace(10, (10**6), 10**6)
Y=10**(-8)*X*X
plt.ylabel('T, с')
plt.xlabel('Кол-во запросов над массивом')

plt.grid(True)
plt.scatter(an, atime, color='red', linewidth=1,label = 'Сортировка А')
plt.scatter(bn, btime, color = 'blue', linewidth=1,label = 'Сортировка Б')
plt.scatter(cn, ctime, color='green', linewidth=1,label = 'Сортировка С')

plt.legend()
plt.show()
afile.close()
bfile.close()
cfile.close()
#task_3_random
