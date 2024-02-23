CC = g++
CFLAGS = -O3
TARGET = main
SOURCES = src/*.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf $(TARGET)