import numpy as np

A=np.array([[1,2]])
B=np.array([[3,4],
            [5,6]])
C=np.array([[1],
            [2]])
D=np.array([[3,4]])
print(A@B)
print(C@D)
print(A@C)
