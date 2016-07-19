import matplotlib.pyplot as plt
import numpy as np
import math
import pylab
from scipy.optimize import curve_fit
from scipy.stats import gaussian_kde

f1 = open('Initial_Distribution.prn','r')
f2 = open('Minimization_Distribution.prn','r')

initial = f1.readlines()
minimized = f2.readlines()

xi = []
yi = []

xm = []
ym = []

fig = plt.figure()

for line in initial:
   l = line.split()
   xi.append(float(l[0]))
   yi.append(float(l[1]))

for line in minimized:
   l = line.split()
   xm.append(float(l[0]))
   ym.append(float(l[1]))

xInit = np.array(xi)
yInit = np.array(yi)

xMin = np.array(xm)
yMin = np.array(ym)

InitPlt = np.vstack([xInit,yInit])
z1 = gaussian_kde(InitPlt)(InitPlt)
idx1 = z1.argsort()
xInit, yInit, z1= xInit[idx1], yInit[idx1], z1[idx1]

MinPlt = np.vstack([xMin,yMin])
z2 = gaussian_kde(MinPlt)(MinPlt)
idx2 = z2.argsort()
xMin, yMin, z2 = xMin[idx2], yMin[idx2], z2[idx2]

ax = fig.add_subplot(1,2,1)
ax.scatter(xInit,yInit, c=z1, s=50, edgecolor='')
ax2 = fig.add_subplot(1,2,2)
ax2.scatter(xMin,yMin, c=z2, s=50, edgecolor='')

plt.show()
