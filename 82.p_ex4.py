import numpy as np

from mydnn import *

np.set_printoptions(formatter={'float_kind':lambda x: "{0:6.3f}".format(x)})

NUM_PATTERN = 10
NUM_X = 7
NUM_H = 16
NUM_M = 16
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
yps = [pc for pc in range(0,NUM_PATTERN)]
np.random.seed(0)

WH = initialize_weight_He(NUM_X, NUM_H)
BH = np.zeros((1, NUM_H))

WM = initialize_weight_He(NUM_H, NUM_M)
BM = np.zeros((1, NUM_M))

WY = initialize_weight_Le(NUM_M, NUM_Y)
BY = np.zeros((1, NUM_Y))

lr = 0.01

shuffled_pattern = [pc for pc in range(0,NUM_PATTERN)]

for epoch in range(0,10000):
    # if epoch%100==99 :         print('epoch = %d'%epoch)
    np.random.shuffle(shuffled_pattern)
    sumE = 0

    for rc in range(0,NUM_PATTERN):
        pc = shuffled_pattern[rc]
        X = xs[pc]
        YT = yts[pc]

        H = relu_f  (X @ WH + BH)
        M = relu_f  (H @ WM + BM)
        Y= sigmoid_f(M @ WY + BY)

        e = calculate_MSE(Y,YT)
        sumE += e

        YE = sigmoid_b (Y - YT, Y)
        ME = relu_b(YE @ WY.T , M)
        HE = relu_b(ME @ WM.T , H)

        WYE = M.T @ YE
        BYE = 1*YE
        WME = H.T @ ME
        BME = 1*ME
        WHE = X.T @ HE
        BHE = 1*HE

        WY -= lr*WYE
        BY -= lr*BYE
        WM -= lr*WME
        BM -= lr*BME
        WH -= lr*WHE
        BH -= lr*BHE

        yps[pc]=Y

    if sumE<0.0000001: break

print('epoch = %d'%(epoch+1))
for pc in range(0,NUM_PATTERN):
    print('%d:'%pc,yps[pc])