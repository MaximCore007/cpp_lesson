CC := g++
CFLAGS := -g -Wall

all:
	$(info Enter file name)

modifiers: class_modifiers.cpp
	$(CC) $(CFLAGS) -o run_program class_modifiers.cpp

constructor: class_constructor.cpp
	$(CC) $(CFLAGS) -o run_program class_constructor.cpp

clean:
	*.o run_program
