# Compiler and flags
CC = c++
CFLAGS = -Wall -Wextra -std=c99
TARGET = battleship

# Source files
SOURCES = src/*/$(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Targets
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean