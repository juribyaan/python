class Calculator:
    def __init__(self):
        self.value = 0
    def add(self,val):
        self.value += val

class UpgradeCalculator(Calculator):
    def minus(self,val):
        self.value -= val

cal=UpgradeCalculator()
cal.add(10)
cal.minus(7)

print(cal.value)

class MaxLimitCalculator(UpgradeCalculator):
    def add(self,val):
        self.value += val
        if self.value > 100:
            self.value = 100

cal1=MaxLimitCalculator()
cal1.add(50)
cal1.add(60)

print(cal1.value)
    