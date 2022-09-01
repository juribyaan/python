from xml.etree.ElementTree import _FileRead

from myargv import myargv


all([1,2,abs(-3)-3])
chr(ord('a')) == 'a'

alist = [1,-2,3,-5,8,-3]
list(filter(lambda i: i>=0 , alist))

hex(234)
int('0xea', 16)
int(hex(234),16)

blist = [1,2,3,4]
list(map(lambda i: i*3,blist))

clist = [-8,2,7,6,-3,5,0,1]
c1 = min(clist)
c2 = max(clist)
print(c1 + c2)

round(17/3,4)


import sys
print(sys.argv[1:])
dlist=[int(i) for i in sys.argv[1:]]
print(dlist)
print(sum(dlist))

import os
os.chdir("c:\\")
import myargv
f= open("myargv.py",'w')
for i in range(1,10):
    data = i
    f.write(data)
f.close()

print(sum(data))

import random
lotto_numbers=[]
howManyNum = 0
while True:
    lotto_num = random.randint(1,45)
    if lotto_num in lotto_numbers:
        continue
    lotto_numbers.append(lotto_num)
    howManyNum += 1
    if howManyNum == 6:
        break
print(lotto_numbers)

import random

data = [i for i in range(1,46)]
def random_pop(data):
    lotto=random.randint(0,len(data))
    return data.pop(lotto)

for i in range(6):
    print(random_pop(data))


def sum_all(*numbers):
    print('numbers:' ,numbers)
    return sum(numbers)

sum_all(1,2,3,4,)
sum_all([i for i in range(100)])
sum_all(*[i for i in range(100)])

def give_me_dict(**my_dict):
    return my_dict
give_me_dict(name='Chris', age = 33 , gender = 'male')

print(*['alice','bob'] , *['chris'], 'divid' )

my_list = [ ['Alice', 31], 
            ['Bob', 32], 
            ['Chris', 33] 
            ]

for i in zip(*my_list):
    print(list(i))

students = ['Alice' , 'Bob' , 'Chris']
*other_students, me = students
print(me)
print(other_students)

product_code = 'A320'
class_indicator, *model = product_code
print('Class indicator: ', class_indicator)
print('Model:',''.join(model))