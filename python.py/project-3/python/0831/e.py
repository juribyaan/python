x1,x2 = 2,3
w1,w2,w3,w4 = 3,4,5,6
b1,b2 = 1,2
yT1,yT2 = 27,-30
lr=0.01

for i in range(2000):
    y1=x1*w1+x2*w2+1*b1
    y2=x1*w3+x2*w4+1*b2

    E=(y1-yT1)**2/2 + (y2-yT2)**2/2
    
    yE1=y1-yT1
    yE2=y2-yT2

    wE1=yE1*x1
    wE2=yE1*x2
    wE3=yE2*x1
    wE4=yE2*x2

    bE1=yE1*1
    bE2=yE2*1

    w1=w1-lr*wE1
    w2=w2-lr*wE2
    w3=w3-lr*wE3
    w4=w4-lr*wE4

    b1=b1-lr*bE1
    b2=b2-lr*bE2    

    print('i = %d\n' %i)
    print('y1= %6.3f y2= %6.3f\n' % (y1,y2))
    print('wE1 = %6.3f , wE2 = %6.3f bE1 = %6.3f\n' % (wE1,wE2,bE1))
    print('wE3 = %6.3f , wE4 = %6.3f bE2 = %6.3f\n' % (wE3,wE4,bE2))
    print('w1 : %f , w2 : %f b1 : %f \n' %(w1,w2 ,b1))
    print('w3 : %f , w4 : %f b1 : %f \n' %(w3,w4 ,b2))

    if E < 0.0000001:
        break