import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import math

file = open("search_results.txt")
bfile = open("bin_search_results.txt")
lines = file.readlines()
blines = bfile.readlines()
time = []
btime = []
n = []
bn=[]
for line in lines:
    s, t1,t2,t3,t4,t5 = list(map(float, line.split(';')))
    time.append(t1)
    time.append(t2)
    time.append(t3)
    time.append(t4)
    time.append(t5)
    n.append(s)
    n.append(s)
    n.append(s)
    n.append(s)
    n.append(s)
for line in blines:
    s, t1,t2,t3,t4,t5 = list(map(float, line.split(';')))
    btime.append(t1)
    btime.append(t2)
    btime.append(t3)
    btime.append(t4)
    btime.append(t5)
    bn.append(s)
    bn.append(s)
    bn.append(s)
    bn.append(s)
    bn.append(s)

X=np.linspace(10, (10**7), 10**6)
Y=np.log(10**6)/np.log(2)*np.log(X)/np.log(2)
plt.ylabel('T, с')
plt.xlabel('длина массива')

plt.grid(True)
plt.scatter(n, time, color='red', label = 'Перебор')
plt.scatter(bn, btime, color = 'blue', label = 'Двоичный поиск')
plt.plot(X,Y,linewidth=2)
plt.legend()
plt.show()

#search_plot
