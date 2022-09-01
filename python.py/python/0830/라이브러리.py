
import sys
sys.path
sys.path.append("C:\\Users\\-\\Documents")

from fileinput import filename
import pickle
f = open("test.txt",'wb')
data = {1: 'python', 2: 'you need'}
pickle.dump(data,f)
f.close()
f = open("test.txt",'rb')
data = pickle.load(f)
print(data)

import os
os.environ
os.environ['path']
os.chdir("C:\\WINDOWS")
os.getcwd()
os.system("dir")
f= os.popen("dir")
print(f.read())

import shutil
shutil.copy("src.txt","dst.txt")

import glob
glob.glob("C:\\Users\\-\\AppData\\Local\\Programs\\Python\\Python310\\*")

import tempfile
filename = tempfile.mkstemp()
filename
f.close()

import time
time.time()
time.localtime(time.time())
time.asctime(time.localtime(time.time()))
time.ctime()
time.strftime('%x', time.localtime(time.time()))
time.strftime('%c',time.localtime(time.time()))
for i in range(10):
    print(i)
    time.sleep(1)

import calendar
calendar.monthrange(2015,12)
calendar.prmonth(2015,12)
calendar.weekday(2015,12,31)

import random
random.random()
random.randint(1,10)
random.randint(1,55)

def random_pop(data):
    number = random.randint(0, len(data)-1)
    print('surrent random index : ',number)
    return data.pop(number)
if __name__ == "__main__":
    data = [1,2,3,4,5]
    while data: print(random_pop(data))
    print(data)

def random_pop1(data):
    number = random.choice(data)
    data.remove(number)
    return number
data = [1,2,3,4,5]
random.shuffle(data)
data

import random
import string
string.ascii_lowercase
string.ascii_letters
letters = string.ascii_lowercase
random.choice(letters)
[random.choice(letters) for _ in range(10)]
''.join([random.choice(letters) for _ in range(10)])
''.join(random.choice(letters) for _ in range(10))
[''.join([random.choice(letters) for _ in range(10)]) for _ in range(random.randint(1,10))]
''.join([random.choice(letters) for _ in range(random.randint(1,20))])