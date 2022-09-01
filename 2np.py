import numpy as np

np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.2f}".format(x)})

Y = np.array([[1.3,5.1,2.2,0.7,1.1]])
print(np.exp(Y))

sumY = np.sum(np.exp(Y))
print('{:.2f}'.format(sumY))

Y = np.exp(Y)/sumY
print(Y)
def sigmoid_f(X):
    return 1/(1+np.exp(-X))

def sigmoid_b(XE,X):
    return X*(1-X)*XE

X = np.array([[0.05,0.10]])
WH = np.array([[0.15,0.25],[0.20,0.30]])
BH = np.array([[0.35,0.35]])
WY = np.array([[0.40,0.50],[0.45,0.55]])
BY = np.array([[0.60,0.60]])
YT = np.array([[0.01,0.99]])
lr = 0.01

for i in range(0,10000):
    H = sigmoid_f(X@WH +BH)
    Y = sigmoid_f(H@WY + BY)
    E = (Y-YT)@(Y-YT).T/2
    e = E[0,0]


    YE = sigmoid_b(Y-YT,Y)
    HE = sigmoid_b(YE@WY.T,H)

    WYE = H.T@YE
    BYE = 1*YE
    WHE = X.T@HE
    BHE = 1*HE

    WY -= lr*WYE
    BY -= lr*BYE
    WH -= lr*WHE
    BH -= lr* BHE

    print(i)
    print(Y)
    if e<0.0000001: break