import matplotlib.pyplot as plt
import numpy as np
import math
import pylab
from scipy.optimize import curve_fit

f2 = open('msd.prn', 'r')
lines = f2.readlines()

dt = []
x = []
y = []
z =[]

fig = plt.figure()

for line in lines:
    p = line.split()
    dt.append(float(p[0]))
    x.append(float(p[1]))
    y.append(float(p[2]))
    z.append(float(p[3]))
  
tv = np.array(dt) 
xv = np.array(x)
yv = np.array(y)
zv = np.array(z)

def line(x,m,b):
  return m*x + b 

xdata1 = tv[:]
ydata1 = xv[:]


popt, pcov = curve_fit(line, xdata1, ydata1)
#quad, _ = curve_fit(line, tv[:-100], xv[:-100])

f1 = (0.5)*tv

a,b = popt

ax = fig.add_subplot(1,1,1)
ax.plot(tv, xv)
ax.plot(tv, yv)
ax.plot(tv, zv)
#ax.plot(tv, f1)
#ax.plot(tv,2*(a*tv))
plt.xlabel("[dt]")
plt.ylabel("[MSD]")
plt.title("Mean Squared Displacement vs. Time Step")
pylab.legend(loc='lower right')

plt.show()

