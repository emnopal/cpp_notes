import numpy as np
import matplotlib.pyplot as plt

n = 100
x = 0
for j in range(1, 3000):
    x += 2*np.pi/1000
    fx[j] = 1/2
    for i in range(1,n,2):
        fx[j] += (2/np.pi)*np.sin[i*x]/[i]

plt.figure()
plt.plot(fx)