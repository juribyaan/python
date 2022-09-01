# f=open('C:/Users/-/AppData/Local/Programs/Python/Python310/game/sound/echo.py','w')
# f.write(
#      '''# mod1.py
# def add(a,b):
#     return a+b
# def sub(a,b):
#     return a-b
# if __name__ == "__main__":
#      ''')
# f.close()
# f=open('mod1.py','r')
# buf=f.read()

# print(buf)

import mod1
print(mod1.add(3,4))

from mod1 import add
print(add(3,8))

import game.sound.echo
game.sound.echo.echo_test()

import game.grapic.render
game.grapic.render.render_test()

from game.sound import*
echo.echo_test()

from game.grapic.render import render_test
render_test()