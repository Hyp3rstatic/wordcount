.PHONY: all
all: main bin
	gcc build/obj/main.o build/obj/dl_list.o -o build/bin/wordcount

.PHONY: clean
clean:
	rm -rf build

bin: build
	mkdir -p build/bin

obj: build
	mkdir -p build/obj

build:
	mkdir -p build

main: src/main.c dl_list
	gcc -g -O -c src/main.c -o build/obj/main.o

dl_list: src/dl_list.c obj
	gcc -g -O -c src/dl_list.c -o build/obj/dl_list.o
