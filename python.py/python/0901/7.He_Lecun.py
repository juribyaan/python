import numpy as np

np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.3f}".format(x)})

np.random.seed(0)
W = np.random.uniform(-1,1,(2,2))

print(W)
print(W*np.sqrt(6.0/W.shape[0]))
print(W*np.sqrt(3.0/W.shape[0]))