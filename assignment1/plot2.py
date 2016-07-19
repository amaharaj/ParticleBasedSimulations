import matplotlib.pyplot as plt
import numpy as np
import math
import pylab

f2 = open('CLT_numbers.prn', 'r')
lines = f2.readlines()

x1 = []
x = np.arange(-3,3,0.2)

for line in lines:
    p = line.split()
    x1.append(float(p[0]))
   
xv = np.array(x1)

f1=np.exp(-x**2/2)/math.sqrt(2*math.pi)
plt.subplot(1,1,1)
pylab.hist(xv,bins=np.linspace(-3,3,100), label='Distribution of Averages',normed=1)
plt.plot(x,f1,color='red',linewidth=3, label='Normal Distribution')
pylab.legend(loc='upper right')
plt.xlabel("Distribution of Averages")
plt.ylabel("Frequency of Occurance")
plt.title("Central Limit Theorem")

plt.show()

