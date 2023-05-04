CC = g++
CFLAGS = -lGLEW -lGL -lX11 -lGLU -lOpenGL -lglfw -lrt -lm -ldl -std=c++20
CFLAGS2 = -std=c++20

TARGET = leia-tangram
TARGET2 = example

all: $(TARGET) $(TARGET2)

$(TARGET): tangram-test.cpp
	$(CC) -o $(TARGET) tangram-test.cpp $(CFLAGS)

$(TARGET2): test.cpp
	$(CC) -o $(TARGET2) test.cpp $(CFLAGS2)

clean:
	$(RM) $(TARGET)
	$(RM) $(TARGET2)
