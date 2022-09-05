import tensorflow as tf

mnist = tf.keras.datasets.fashion_mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0
x_train, x_test = x_train.reshape((60000, 28,28,1)), x_test.reshape((10000, 28,28,1))

model = tf.keras.Sequential([
tf.keras.layers.Conv2D(filter=32, kernel_size=(5,5) , strides=(1,1), padding = 'same',
                    #(32는 필터의 갯수 , 필터 사이즈 , 필터 이동 , 여백을 이용해 사이즈 유지)
                    activation='relu' , input_shape=(28,28,1)),
tf.keras.layers.MaxPooling2D(pool_size=(2,2),strides=(2,2)),
tf.keras.layers.Dropout(0.2),
tf.keras.layers.Flatten(),
tf.keras.layers.Dense(128, activation='relu'),
tf.keras.layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam', 
            loss='sparse_categorical_crossentropy', 
            metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5)

#https://hmkim312.github.io/posts/MNIST_%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%A1%9C_%ED%95%B4%EB%B3%B4%EB%8A%94_CNN(Convolution_Neral_Network)/