import numpy as np

from mydnn import *

np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.3f}".format(x)})

NUM_PATTERN = 10
NUM_X = 7
NUM_H = 8
NUM_Y = 4

xs = np.array([
    [[ 1, 1, 1, 1, 1, 1, 0 ]], # 0
    [[ 0, 1, 1, 0, 0, 0, 0 ]], # 1
    [[ 1, 1, 0, 1, 1, 0, 1 ]], # 2
    [[ 1, 1, 1, 1, 0, 0, 1 ]], # 3
    [[ 0, 1, 1, 0, 0, 1, 1 ]], # 4
    [[ 1, 0, 1, 1, 0, 1, 1 ]], # 5
    [[ 0, 0, 1, 1, 1, 1, 1 ]], # 6
    [[ 1, 1, 1, 0, 0, 0, 0 ]], # 7
    [[ 1, 1, 1, 1, 1, 1, 1 ]], # 8
    [[ 1, 1, 1, 0, 0, 1, 1 ]] # 9
])
yts = np.array([
    [[ 0, 0, 0, 0 ]],
    [[ 0, 0, 0, 1 ]],
    [[ 0, 0, 1, 0 ]],
    [[ 0, 0, 1, 1 ]],
    [[ 0, 1, 0, 0 ]],
    [[ 0, 1, 0, 1 ]],
    [[ 0, 1, 1, 0 ]],
    [[ 0, 1, 1, 1 ]],
    [[ 1, 0, 0, 0 ]],
    [[ 1, 0, 0, 1 ]]
])
np.random.seed(0)

WH = initialize_weight_He(NUM_X, NUM_H)
BH = np.zeros((1, NUM_H))
WY = initialize_weight_Le(NUM_H, NUM_Y)
BY = np.zeros((1, NUM_Y))
lr = 0.01

for epoch in range(0,10000):
    X = xs[2]
    YT = yts[2]

    H = relu_f(X@WH + BH)
    Y = sigmoid_f(H@WY + BY)

    e = calculate_MSE(Y,YT)

    YE = sigmoid_b(Y - YT, Y)
    HE = relu_b(YE@WY.T, H)

    WYE = H.T@YE
    BYE = 1*YE
    WHE = X.T@HE
    BHE = 1*HE

    WY -= lr*WYE
    BY -= lr*BYE
    WH -= lr*WHE
    BH -= lr*BHE

    if epoch % 100 == 99:
        print('epoch =', epoch)
        print(Y)
    if e<0.0000001: break