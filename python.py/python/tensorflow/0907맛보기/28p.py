import numpy as np
import time
import matplotlib.pyplot as plt
import tensorflow as tf

NUM_SAMPLES = 1000

np.random.seed(int(time.time()))

# xs = np.random.uniform(-2, 0.5, NUM_SAMPLES)
xs = np.random.uniform(0, 2*np.pi, NUM_SAMPLES)
np.random.shuffle(xs)
print(xs[:5])

# ys = 2*xs**2 + 3*xs + 5
ys = np.sin(xs)

print(ys[:5])

plt.plot(xs, ys, 'b.')
plt.show()

ys += 0.1*np.random.randn(NUM_SAMPLES)

plt.plot(xs, ys, 'g.')
plt.show()

NUM_SPLIT = int(0.8*NUM_SAMPLES)

x_train, x_test = np.split(xs, [NUM_SPLIT])
y_train, y_test = np.split(ys, [NUM_SPLIT])

plt.plot(x_train, y_train, 'b.', label='train')
plt.plot(x_test, y_test, 'r.', label='test')
plt.legend()
plt.show()


model_f = tf.keras.Sequential([ 
tf.keras.layers.InputLayer(input_shape=(1,)),
tf.keras.layers.Dense(16, activation='relu'),
tf.keras.layers.Dense(16, activation='relu'),
tf.keras.layers.Dense(1) 
])

model_f.compile(optimizer='rmsprop', loss='mse')

p_test = model_f.predict(x_test)

plt.plot(x_test, y_test, 'b.', label='actual')
plt.plot(x_test, p_test, 'r.', label='predicted')
plt.legend()
plt.show()

model_f.fit(x_train, y_train, epochs=600)

p_test = model_f.predict(x_test)

plt.plot(x_test, y_test, 'b.', label='actual')
plt.plot(x_test, p_test, 'r.', label='predicted')
plt.legend()
plt.show()