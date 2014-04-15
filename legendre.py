import numpy
import pylab
import math
a=-1
h=1.0/128.0
tlist=[]
for x in range(0,256):
	tlist.append(a)
	a=a+x*h
print tlist

