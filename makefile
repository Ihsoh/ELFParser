TARGET=bin/elfparser
TEST=bin/test
CC=gcc
CFLAGS=-O2 -std=c99 -m32 -march=i386 -mtune=i386

all: $(TARGET)

$(TARGET): *.c
	-mkdir bin
	$(CC) $(CFLAGS) $^ -o $@
	cp $(TARGET) $(TEST)
	./$(TARGET) $(TEST)	

clean:
	-rm bin/*

.PHONY: clean all
