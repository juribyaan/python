import tensorflow as tf

mnist = tf.keras.datasets.mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0
x_train, x_test = x_train.reshape((60000, 28,28,1)), x_test.reshape((10000, 28,28,1))

model = tf.keras.Sequential([
tf.keras.layers.Conv2D(filters=(32), kernel_size=(5,5) , input_shape=(28,28,1), padding='same',activation='relu'),
tf.keras.layers.MaxPooling2D(pool_size=(2,2),strides=(2,2)),
tf.keras.layers.Flatten(),
tf.keras.layers.Dense(256, activation='relu'),
tf.keras.layers.Dense(128, activation='relu'),
tf.keras.layers.Dense(1, activation='linear')
])

model.compile(optimizer='adam', loss='mse')

model.fit(x_train, y_train, epochs=1)

import matplotlib.pyplot as plt

p_test = model.predict(x_test)
print('p_test[0] :', p_test[0])

x_test = x_test.reshape(10000,28,28)

plt.figure()
plt.imshow(x_test[0])
plt.show()

plt.figure(figsize=(10,10))
for i in range(25):
    plt.subplot(5,5,i+1)
    plt.xticks([])
    plt.yticks([])
    plt.imshow(x_test[i], cmap=plt.cm.binary)
    plt.xlabel(p_test[i])
plt.show()