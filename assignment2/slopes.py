import numpy as np

msddata = open('msd.prn','r')
MSDdata = msddata.readlines()

Slopes = open('slopes.prn','w')

tarr = []
xarr = []
yarr = []
zarr = []

MSDdata = np.loadtxt('msd.prn',delimiter=' ',dtype=[])

for m in MSDdata:
  m.split(' ')
  tarr.append(m[0])
  xarr.append(m[1])
  yarr.append(m[2])
  zarr.append(m[3])

print xarr[-1]
print xarr[399]

slopex = (float(tarr[-1])-float(tarr[399]))/(float(xarr[-1])-float(xarr[399]))
Slopes.write('slope of x_msd: ' + str(slopex) + '\n')
slopey = ((float(tarr[-1])-float(tarr[399]))/(float(yarr[-1])-float(yarr[399])))
Slopes.write('slope of y_msd: ' + str(slopey) + '\n')
slopez = ((float(tarr[-1])-float(tarr[399]))/(float(zarr[-1])-float(zarr[399])))
Slopes.write('slope of z_msd: ' + str(slopez) + '\n')

Slopes.close()
msddata.close()

