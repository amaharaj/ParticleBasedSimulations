import matplotlib.pyplot as plt
import numpy as np
import math
import pylab
from scipy.optimize import curve_fit

f2 = open('msd.prn', 'r')
lines = f2.readlines()

D = open('diffusion_coeffs.prn','w')

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
#    y.append(float(p[2]))
#    z.append(float(p[3]))
  
tv = np.array(dt) 
tv = tv/100.0
xv = np.array(x)
#yv = np.array(y)
#zv = np.array(z)

#def func(x,a,b,c):
 # return a*x**2 + b*x + c
def line(x,m,b):
  return m*x + b 

xdata1 = tv[500:2000]
ydata1 = xv[500:2000]


popt, pcov = curve_fit(line, xdata1, ydata1)
#quad, _ = curve_fit(line, tv[:-100], xv[:-100])

#print popt

d = 3
m = (2./2.)*d
f1 = m*tv

a,b = popt

D.write('Calculated D: ' + str(a) + "\n")
D.write('Expected D: ' + str(m) + "\n")

ax = fig.add_subplot(1,1,1)
ax.plot(tv, f1, label='Expected Slope')
#ax.loglog(tv, a*tv**2 + b*tv , label='Ballistic Motion Fit')
ax.plot(tv, popt[0] * tv, label='Calculated Slope')
ax.plot(tv, xv)
#ax.loglog(tv, yv)
#ax.loglog(tv, zv)
#ax.set_yscale('log')
#ax.set_xscale('log')
plt.xlabel("[dt]")
plt.ylabel("[MSD]")
plt.title("Uncorrelated Mean Squared Displacement vs. Time Step")
pylab.legend(loc='lower right')

D.close()

plt.show()

