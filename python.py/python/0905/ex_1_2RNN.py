import tensorflow as tf

mnist = tf.keras.datasets.fashion_mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0


model = tf.keras.Sequential([
tf.keras.layers.SimpleRNN(128, input_shape=(28,28)),
                          #ㄴ은닉층 node 갯수
tf.keras.layers.Dense(128, activation='relu'),
tf.keras.layers.Dense(1)#,activation='linear')
])

model.compile(optimizer='adam', 
            loss='mse', #'sparse_categorical_crossentropy'
            metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5)
