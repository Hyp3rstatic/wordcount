CC = gcc
SRC = src
OBJ = build/obj
BIN = build/bin
OBJS = $(OBJ)/main.o $(OBJ)/wc_utils.o $(OBJ)/wc_qsort.o $(OBJ)/wc_entry.o $(OBJ)/dl_list.o $(OBJ)/prand.o

all: main bin
	$(CC) $(OBJS) -o $(BIN)/wordcount

clean:
	rm -rf build

bin: build
	mkdir -p $(BIN)

obj: build
	mkdir -p $(OBJ)

build:
	mkdir -p build

main: $(SRC)/main.c wc_qsort
	$(CC) -g -O -c $(SRC)/main.c -o $(OBJ)/main.o

dl_list: src/dl_list.c obj
	$(CC) -g -O -c $(SRC)/dl_list.c -o $(OBJ)/dl_list.o

wc_qsort: $(SRC)/wc_qsort.c wc_utils prand
	$(CC) -g -O -c $(SRC)/wc_qsort.c -o $(OBJ)/wc_qsort.o

wc_utils: $(SRC)/wc_utils.c wc_entry dl_list
	$(CC) -g -O -c $(SRC)/wc_utils.c -o $(OBJ)/wc_utils.o

wc_entry: $(SRC)/wc_entry.c obj
	$(CC) -g -O -c $(SRC)/wc_entry.c -o $(OBJ)/wc_entry.o

prand: $(SRC)/prand.c obj
	$(CC) -g -O -c $(SRC)/prand.c -o $(OBJ)/prand.o
