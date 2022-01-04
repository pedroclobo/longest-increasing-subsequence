CC = g++
CFLAGS = -std=c++11 -O3 -Wall -lm
MFLAGS += --no-print-directory
EXE=../src/proj

all:: run

random_k: random_k.cpp
	$(CC) $(CFLAGS) random_k.cpp -o random_k

run:: random_k
	rm 1.txt 2.txt
	bash benchmark.sh 1
	bash benchmark.sh 2

clean::
	rm random_k 1.txt 2.txt sequence
