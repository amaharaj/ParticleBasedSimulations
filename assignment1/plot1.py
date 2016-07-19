import matplotlib.pyplot as plt
import numpy as np
import math
import pylab

f2 = open('random_numbers.prn', 'r')
lines = f2.readlines()

x1 = []
y1 = []
x = np.linspace(-0,3.14,100)

for line in lines:
    p = line.split()
    x1.append(float(p[0]))
    y1.append(float(p[1]))
   
xv = np.array(x1)
yv = np.array(y1)

f1 = np.sin(x)/2.0

plt.subplot(1,1,1)
pylab.plot(x,f1, label='sin(x)/2',color='red',linewidth=3)
pylab.hist(xv,bins=100,normed=1,label='Occurances of Random Number')
plt.xlabel("Random Numbers")
plt.ylabel("Occurances of Random Number")
plt.title("Inverse Transform Sampling")
pylab.legend(loc='upper right')

plt.show()

