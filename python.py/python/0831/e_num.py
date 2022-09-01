
X = 
W1,W2,W3 = WH,WM,WY
Y =
YT = 


B1,B2,B3 = BH,BM,BY

lr = 0.01

for i in range(0,10):
    H = X@W1 + 1*B1
    M = H@W2 + 1*B2
    y = M@W3 + 1*B3

    YE= Y-YT
    E = (Y-YT)**2/2
    e = E[0,0]
    ME = YE@y.T
    HE = ME@M.T
    XE = HE@H.T

    BE3 = 1*ME
    BE2 = 1*HE
    BE1 = 1*XE

    X -= lr*XE
    H -= lr*HE
    M -= lr*ME

    if e<     : break