import numpy as np

np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.2f}".format(x)})

Y = np.array([[1.3,5.1,2.2,0.7,1.1]])

YMax=np.max(Y)
print(YMax)

Y= Y-YMax
print(Y)
print(np.exp(Y))