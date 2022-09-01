X = 
W1,W2,W3 = WH,WM,WY
Y =
YT = 


B1,B2,B3 = BH,BM,BY

lr = 0.01

for i in range(0,10):
    H = X@W1 + 1*B1
    M = H@W2 + 1*B2
    Y = M@W3 + 1*B3

    YE= Y-YT

    E = (Y-YT)@(Y-YT).T/ len(y)
    E = (Y-YT)**2/2

    e = E[0,0]
    e = E[0][0]

    ME = YE@W3.T
    HE = ME@W2.T

    BE3 = 1*YE
    BE2 = 1*ME
    BE1 = 1*HE

    WE3 = M.T@YE
    WE2 = H.T@ME
    WE1 = X.T@HE

    W1 -= lr*WE1
    W2 -= lr*WE2
    W3 -= lr*WE3

    B1 -= lr*BE1
    B2 -= lr*BE2
    B3 -= lr*BE3

    if e<     : break