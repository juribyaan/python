import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

NUM_SAMPLES = 1000

xs = np.random.uniform(-2, 0.5, NUM_SAMPLES)
np.random.shuffle(xs)
ys = 2*xs**2 + 3*xs + 5

# ys += 0.1*np.random.randn(NUM_SAMPLES)

def my_func(x):
    return 2*x**2 + 3*x + 5

fig, ax = plt.subplots()
ax.set_xlim(xs.min(), xs.max())
ax.set_ylim(ys.min(), ys.max())

x, y = [], []

line, = plt.plot([], [], 'b.')

def update(frame):
    x.append(frame)
    y.append(my_func(frame))
    line.set_data(x, y)
    return line,

ani = FuncAnimation(fig, update, frames=xs)
plt.show()