import numpy as np

np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.2f}".format(x)})

def softmax_f(X):
    XMax = np.max(X)
    X = X / XMax
    
    return X

def softmax_b(XE,X):
    return XE

X = np.array([[1.3 , 5.1 , 2.2 , 0.7 , 1.1]])
X = softmax_f(X)
print(X)

def softmax_f(X):
    XMax = np.max(X)
    X = X - XMax
    sumX = np.sum(np.exp(X))
    return np.exp(X)/sumX

def softmax_b(XE,X):
    return XE

X = np.array([[1.3 , 5.1 , 2.2 , 0.7 , 1.1]])
X = softmax_f(X)
print(X)