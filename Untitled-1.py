import numpy as np
import matplotlib.pyplot as plt

t = np.arange(0,25)
h = 6
a = np.exp(-t*np.log10(2/h))
print(a)
plt.plot(t,a)
plt.show()