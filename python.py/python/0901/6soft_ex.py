import numpy as np
np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.3f}".format(x)})

def relu_f(X):
    return (X>0)*X

def relu_b(XE,X):
    return (X>0)*1*XE

def softmax_f(X):
    XMax = np.max(X)
    X = X -XMax
    sumX = np.sum(np.exp(X))
    return np.exp(X)/sumX

def softmax_b(XE,X):
    return XE

X = np.array([[0.05, 0.10]])
WH = np.array([[0.15, 0.25],[0.20, 0.30]])
BH = np.array([[0.35, 0.35]])
WY = np.array([[0.40, 0.50],[0.45, 0.55]])
BY = np.array([[0.60, 0.60]])
YT = np.array([[0, 1]])
lr = 0.01

for i in range(0,10000):
    H = relu_f(X@WH + BH)
    Y = softmax_f(H@WY + BY)
    e = -np.sum(YT*np.log(Y))
    YE = softmax_b(Y - YT,Y)
    HE = relu_b(YE@WY.T,H)

    WYE = H.T@YE
    BYE = 1*YE
    WHE = X.T@HE
    BHE = 1*HE

    WY -= lr*WYE
    BY -= lr*BYE
    WH -= lr*WHE
    BH -= lr*BHE
    print(i)
    print(Y)

    if e<0.0000001: break