CC = g++
CFLAGS = -lGLEW -lGL -lX11 -lGLU -lOpenGL -lglfw -lrt -lm -ldl -std=c++20
CFLAGS2 = -std=c++20

TARGET = examples/leia-tangram
TARGET2 = examples/example
TARGET3 = examples/cloth

all: $(TARGET) $(TARGET2) $(TARGET3)

$(TARGET): examples/tangram-test.cpp
	$(CC) -o $(TARGET) examples/tangram-test.cpp $(CFLAGS)

$(TARGET2): examples/test.cpp
	$(CC) -o $(TARGET2) examples/test.cpp $(CFLAGS2)

$(TARGET3): examples/cloth.cpp
	$(CC) -o $(TARGET3) examples/cloth.cpp $(CFLAGS)

clean:
	$(RM) $(TARGET)
	$(RM) $(TARGET2)
	$(RM) $(TARGET3)
