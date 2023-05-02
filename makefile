CC = g++
CFLAGS = -lGLEW -lGL -lX11 -lGLU -lOpenGL -lglfw -lrt -lm -ldl -std=c++20

TARGET = leia-tangram

all: $(TARGET)

$(TARGET): tangram-test.cpp
	$(CC) -o $(TARGET) tangram-test.cpp $(CFLAGS)

clean:
	$(RM) $(TARGET)
