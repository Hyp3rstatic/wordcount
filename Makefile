.PHONY: all
all: main bin
	gcc build/obj/main.o build/obj/dl_list.o build/obj/wordcount.o -o build/bin/wordcount

.PHONY: clean
clean:
	rm -rf build

bin: build
	mkdir -p build/bin

obj: build
	mkdir -p build/obj

build:
	mkdir -p build

main: src/main.c wordcount
	gcc -g -O -c src/main.c -o build/obj/main.o

dl_list: src/dl_list.c obj
	gcc -g -O -c src/dl_list.c -o build/obj/dl_list.o

wordcount: src/wordcount.c dl_list obj
	gcc -g -O -c src/wordcount.c -o build/obj/wordcount.o

.PHONY: tclean
tclean:
	rm -rf test/build

tbin: tbuild
	mkdir -p test/build/bin

tojb: tbuild
	mkdir -p test/build/obj

tbuild:
	mkdir -p test/build

test_dl_list: tojb tbin dl_list test/src/test_dl_list.c
	gcc -g -O -c test/src/test_dl_list.c -o test/build/obj/test_dl_list.o
	gcc build/obj/dl_list.o test/build/obj/test_dl_list.o -o test/build/bin/test_dl_list