CC=gcc
CCFLAGS=-Wall -Wextra -Werror -std=c99 -pedantic -O2
LDFLAGS= -lm
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET = exato


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) 


%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

run: all
	valgrind ./$(TARGET)
