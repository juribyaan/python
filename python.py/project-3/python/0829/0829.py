class FourCal:
     def __init__(self,first,second):
         self.first = first
         self.second = second
     def setdata(self,first,second):
         self.first = first
         self.second = second
     def add(self):
         result = self.first + self.second
         return result
     def sub(self):
         result = self.first - self.second
         return result
     def mul(self):
         result = self.first * self.second
         return result
     def div(self):
         result = self.first / self.second
         return result
     

class MoreFourCal(FourCal):
    pass

class FailFourCal(FourCal):
    def mul(self):
        if self.second == 0:
            result = print("Fail")
        else:
            result = FourCal.mul(self)
        return result



a= FourCal(4,2)
b= FourCal(3,7)
c= FourCal(5,9)

a.setdata(4,2)
b.setdata(3,7)
d= FailFourCal(7,0)

class Family:
    lastname= "김"

print(a.add())
print(d.mul())
print(Family.lastname)