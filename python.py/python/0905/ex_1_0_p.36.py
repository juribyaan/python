import tensorflow as tf

mnist = tf.keras.datasets.fashion_mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0
x_train, x_test = x_train.reshape((60000, 784)), x_test.reshape((10000, 784))

model = tf.keras.Sequential([
tf.keras.layers.InputLayer(input_shape=(784,)),
tf.keras.layers.Dense(128, activation='relu'),
tf.keras.layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam', #학습
            loss='sparse_categorical_crossentropy', #E
            metrics=['accuracy'])


model.fit(x_train, y_train, epochs=5)
model.summary()
print(train_images.shape)
#https://wandb.ai/wandb_fc/korean/reports/-Keras---VmlldzoxODc4MDYx
#https://codetorial.net/matplotlib/index.html