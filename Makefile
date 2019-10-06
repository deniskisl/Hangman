all: bin/main 
bin/main: build/main.o build/func.o
	gcc -Wall -Werror build/main.o build/func.o -o bin/main

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/func.o: src/func.c
	gcc -Wall -Werror -c src/func.c -o build/func.o 

.PHONY: clean
clean: build/*.o
	rm -rf build/*.o