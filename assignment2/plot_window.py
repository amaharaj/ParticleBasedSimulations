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

a = [ pow(10,i) for i in range(10)]

fig = plt.figure()

#x_val = np.linspace(0,1000, 200)

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

def func(x,a,b,c):
  return a*x**2 + b*x + c
def line(x,m,b):
  return m*x + b 

xdata1 = tv[0:10]
ydata1 = xv[0:10]


popt, pcov = curve_fit(func, xdata1, ydata1)
quad, _ = curve_fit(line, tv[:-100], xv[:-100])

#print popt

f1 = (0.5)*tv

a,b,c = popt

ax = fig.add_subplot(1,1,1)
#ax.loglog(tv, f1)
ax.loglog(tv, a*tv**2 + b*tv , label='Ballistic Motion Fit')
ax.loglog(tv, quad[0] * tv , label='Diffusive Motion Fit')
ax.loglog(tv, xv)
ax.loglog(tv, yv)
ax.loglog(tv, zv)
#ax.set_yscale('log')
#ax.set_xscale('log')
plt.xlabel("log(dt)")
plt.ylabel("log(MSD)")
plt.title("Mean Squared Displacement vs. Time Step")
pylab.legend(loc='lower right')

plt.show()

