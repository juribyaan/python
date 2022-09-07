import tensorflow as tf
import numpy as np

# xs = np.array([-1.0, 0.0, 1.0, 2.0, 3.0, 4.0])
# ys = np.array([-2.0, 1.0, 4.0, 7.0, 10., 13.])
xs = np.array([
[[ 1, 1, 1, 1, 1, 1, 0 ]], # 0
[[ 0, 1, 1, 0, 0, 0, 0 ]], # 1
[[ 1, 1, 0, 1, 1, 0, 1 ]], # 2
[[ 1, 1, 1, 1, 0, 0, 1 ]], # 3
[[ 0, 1, 1, 0, 0, 1, 1 ]], # 4
[[ 1, 0, 1, 1, 0, 1, 1 ]], # 5
[[ 0, 0, 1, 1, 1, 1, 1 ]], # 6
[[ 1, 1, 1, 0, 0, 0, 0 ]], # 7
[[ 1, 1, 1, 1, 1, 1, 1 ]], # 8
[[ 1, 1, 1, 0, 0, 1, 1 ]] # 9
])
print(xs.shape)

ys = np.array([
[[ 0, 0, 0, 0 ]],
[[ 0, 0, 0, 1 ]],
[[ 0, 0, 1, 0 ]],
[[ 0, 0, 1, 1 ]],
[[ 0, 1, 0, 0 ]],
[[ 0, 1, 0, 1 ]],
[[ 0, 1, 1, 0 ]],
[[ 0, 1, 1, 1 ]],
[[ 1, 0, 0, 0 ]],
[[ 1, 0, 0, 1 ]]
])

model = tf.keras.Sequential([
tf.keras.layers.InputLayer(input_shape=(1,7)), # (7,) <= xs = xs.shape
tf.keras.layers.Dense(16, activation='relu'),
tf.keras.layers.Dense(16, activation='relu'),
tf.keras.layers.Dense(4, activation='sigmoid')
])

model.compile(optimizer='adam', loss='mean_squared_error')

model.fit(xs, ys, epochs=1000)

ps = model.predict(xs)

print(ps)
