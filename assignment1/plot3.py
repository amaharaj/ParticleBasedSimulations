import matplotlib.pyplot as plt
import numpy as np
import math
import pylab

f2 = open('PV_Graph.prn', 'r')
lines = f2.readlines()

x1 = []
y1 = []
x = np.linspace(500,30000,100)

for line in lines:
    p = line.split()
    x1.append(float(p[0]))
    y1.append(float(p[1]))
   
xv = np.array(x1)
yv = np.array(y1)

f1 = 100/x

pylab.ylim([0,0.1])
plt.subplot(1,1,1)
pylab.plot(x,f1, label='ideal gas',color='red',linewidth=3)
pylab.plot(yv,xv,'o',label='Numeric Values')
plt.xlabel("Volume")
plt.ylabel("Pressure")
plt.title("Pressure vs. Volume")
pylab.legend(loc='upper right')

plt.show()

