CC = g++
CFLAGS = -lGLEW -lGL -lX11 -lGLU -lOpenGL -lglfw -lrt -lm -ldl -std=c++20
CFLAGS2 = -std=c++20

TARGET = examples/leia-tangram
TARGET2 = examples/example

all: $(TARGET) $(TARGET2)

$(TARGET): examples/tangram-test.cpp
	$(CC) -o $(TARGET) examples/tangram-test.cpp $(CFLAGS)

$(TARGET2): examples/test.cpp
	$(CC) -o $(TARGET2) examples/test.cpp $(CFLAGS2)

clean:
	$(RM) $(TARGET)
	$(RM) $(TARGET2)
