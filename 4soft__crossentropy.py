import numpy as np

np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.2f}".format(x)})

Y = np.array([[.02 , .90 , .05 , .01 , .02]])
YT = np.array([[0,1,0,0,0]])

print(YT*np.log(Y))
print('%.2f'%np.sum(-YT*np.log(Y)))