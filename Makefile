all: bin/main bin/test
bin/main: build/main.o build/func.o
	gcc -Wall -Werror build/main.o build/func.o -o bin/main

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/func.o: src/func.c
	gcc -Wall -Werror -c src/func.c -o build/func.o

bin/test: build/test/main.o build/func.o build/test/test.o
	gcc -Wall -Werror build/test/main.o build/test/test.o build/func.o -o bin/test -lm

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/test.o: test/test.c
	gcc -I thirdparty -Wall -Werror -c test/test.c -o build/test/test.o


.PHONY: clean
clean: build/*.o
	rm -rf build/*.o
