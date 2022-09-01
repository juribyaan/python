print(abs(3))
print(abs(-3))
print(all([1,2,3]))
print(all([1,2,3,0]))
print(any([1,2,3,0]))
print(any([0,""]))
print(chr(97))
print(chr(48))
print(dir([1,2,3]))
print(dir({'1':'a'}))
print(divmod(7,3))

a= input()
a
print(a)

b= input("Enter: ")
print(b)

# help(''.join)

# Help on built-in function join:

# join(iterable, /) method of builtins.str instance
#     Concatenate any number of strings.

#     The string whose method is called is inserted in between each given string.
#     The result is returned as a new string.

#     Example: '.'.join(['ab', 'pq', 'rs']) -> 'ab.pq.rs'  이런식으로 알려줌

# print('count' in dir(''))
# True 라고 나옴

for i,count in enumerate(range(10)):
    print(i,count)

for i,count in enumerate(range(10)):
    print(i,count)

def positive(l):
    result = []
    for i in l:
        if i > 0:
            result.append(i)
    return result

print(positive([1,-3,2,0,-5,6]))

def positive(x):
    return x>0

print(list(filter(positive,[1,-3,2,0,-5,6])))

print(list(filter(lambda x: x > 0 , [1,-3,2,0,-5,6])))

print(int('3'))
print(int(3.4))
print(hex(234))
print(hex(3))
print(len("python"))
print(len([1,2,3]))
print(len((1,'a')))
print(list("python"))
print(list((1,2,3)))
a=[1,2,3]
b=list(a)
print(b)

def two_times(numberList):
    result = []
    for number in numberList:
        result.append(number*2)
    return result

result = two_times([1,2,3,4])
print(result)

def two_times2(x): return x*2
list(map(two_times2,[1,2,3,4]))

list(map(lambda a: a*2,[1,2,3,4]))

max([1,2,3])
max("python")
min(1,2,3)
min([1,2,3])
min("python")

oct(34)
oct(12345)

f = open("binary_filse",'rb')
fread = open("read_mode.txt",'r')
fread2 = open("read_mode.txt")
fappend = open("append_mode.txt",'a')

ord('a')
ord('0')
# ord("abc") 문자열은 안되네

pow(2,4)
pow(3,3)
list(range(5))
list(range(5,10))
list(range(1,10,2))
list(range(0,-10,-1))

round(4.6)
round(4.2)
round(5.678,2)

sorted([1,2,3])
sorted(['a','c','b'])
sorted("zero")
sorted((3,2,1))

str(3)
str('hi')
str('hi'.upper())

sum((1,2,3))
sum([4,5,6])

tuple("a,b,c")
tuple('abc')
tuple([1,2,3])
tuple((1,2,3))

type("abc")
type([])
type(open("test",'w'))

list(zip([1,2,3],[4,5,6]))
list(zip([1,2,3],[4,5,6,],[7,8,9]))
list(zip("abc",'def'))