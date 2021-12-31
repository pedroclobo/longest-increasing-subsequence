CC = g++
CFLAGS = -std=c++11 -O3 -Wall -lm -g
MFLAGS += --no-print-directory
EXE=../src/proj

all:: run

benchmark: benchmark.c
	$(CC) $(CFLAGS) benchmark.c -o benchmark

random_k: random_k.cpp
	$(CC) $(CFLAGS) random_k.cpp -o random_k

run:: benchmark random_k
	./benchmark

clean::
	rm benchmark random_k 1.txt 2.txt arr.in
