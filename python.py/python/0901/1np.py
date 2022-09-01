import numpy as np

np.set_printoptions(formatter={'flaot_kind':lambda x: "{0:6.3f".format(x)})

X = np.array([[-5,10]])

# Xd = 1/(1+np.exp(-X))   #sigmod 순전파 ,Xd는 X dash를 의미
Xd = (X>0)*X
print(Xd)

XdE = np.array([[2,1]]) #XdE는 X dash Error 를 의미
# XE = Xd*(1-Xd)*XdE      #sigmoid 역전파
XE = (Xd>0)*1*XdE

print(XE)