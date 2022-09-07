import imp
import numpy as np
import time
import matplotlib.pyplot as plt

num_samples = 1000

np.random.seed(int(time.time()))

xs = np.random.uniform(-2,0.5,num_samples)
np.random.shuffle(xs)
print(xs[:5])

ys = 2*xs**2 + 3*xs +5

print(ys[:5])

plt.plot(xs,ys,'b.')
plt.show()