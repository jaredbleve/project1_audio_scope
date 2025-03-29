CC = gcc
CFLAGS = -Wall -O2
TARGET = audio_scope

all: $(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c

clean:
	rm -f $(TARGET)
