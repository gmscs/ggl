CC = g++
CFLAGS = -lGLEW -lGL -lX11 -lGLU -lOpenGL -lglfw -lrt -lm -ldl -std=c++20

TARGET = build/leia-tangram
TARGET2 = build/example
TARGET3 = build/cloth

all: build $(TARGET) $(TARGET2) $(TARGET3)

build:
	@mkdir -p build

$(TARGET): src/tangram-test.cpp
	$(CC) -o $(TARGET) src/tangram-test.cpp $(CFLAGS)

$(TARGET2): src/test.cpp
	$(CC) -o $(TARGET2) src/test.cpp $(CFLAGS)

$(TARGET3): src/cloth.cpp
	$(CC) -o $(TARGET3) src/cloth.cpp $(CFLAGS)


clean:
	$(RM) $(TARGET)
	$(RM) $(TARGET2)
	$(RM) $(TARGET3)
