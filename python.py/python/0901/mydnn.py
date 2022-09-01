import numpy as np

def sigmoid_f(X) :
    return 1/(1+np.exp(-X))

def sigmoid_b(XE, X) :
    return X*(1-X)*XE

def relu_f(X) :
    return (X>0)*X

def relu_b(XE, X) :
    return (X>0)*1*XE

def softmax_f(X) :
    XMax = np.max(X)
    X = X - XMax
    sumX = np.sum(np.exp(X))
    return np.exp(X)/sumX

def softmax_b(XE, X) :
    return XE # do nothing

def initialize_weight_He(nRow, nCol) :
    W = np.random.uniform(-1, 1, (nRow, nCol))
    return W*np.sqrt(6.0/W.shape[0])

def initialize_weight_Le(nRow, nCol) :
    W = np.random.uniform(-1, 1, (nRow, nCol))
    return W*np.sqrt(3.0/W.shape[0])

def calculate_MSE(Y, YT) : # 평균 제곱 오차 함수
    E = (Y - YT)@(Y - YT).T/2
    return E[0, 0]
    
def calculate_CEE(Y, YT) : # cross entropy 오차 함수
    e = -np.sum(YT*np.log(Y))
    return e