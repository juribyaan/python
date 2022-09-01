import numpy as np

# A = np.array([[1,2]])
# BH = np.array([[3,4],[5,6]])
# C = np.array([[1],[2]])
# D = np.array([[3,4]])

# print(A@BH)
# print(C@D)
# print(A@C)

# print(A.T)
# print(BH.T)

X = np.array([[0.05,0.10]])
WH = np.array([[0.15,0.25],[0.20,0.30]])
BH = np.array([[0.35,0.35]])
WY = np.array([[0.40,0.50],[0.45,0.55]])
BY = np.array([[0.60,0.60]])
YT = np.array([[0.01,0.99]])
Y = X@WH + BH
lr = 0.01

for i in range(0,2000):

    H = X@WH + BH
    Y = H@WY + BY
    E = (Y-YT)@(Y-YT).T/2

    e= E[0,0]
    YE = Y - YT
    WYE = H.T@YE
    BYE = 1*YE
    HE = YE@WY.T
    WHE = X.T@HE
    BHE = 1*HE
    WY -= lr*WYE
    BY -= lr*BYE
    WH -= lr*WHE
    BH -= lr*BHE

    # print(Y-YT)
    # print((Y-YT).T)
    # print((Y-YT)@(Y-YT).T)
    # print((Y-YT)@(Y-YT).T/2)
    print(i)
    print(Y)
    print(WY)
    print(BY)
    print(WH)
    print(BH)
    
    if e<0.0000001: break
