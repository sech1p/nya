CC=gcc

nya:
	-mkdir build
	$(CC) main.c -o build/nya

clean:
	-rm build/nya

all: clean nya