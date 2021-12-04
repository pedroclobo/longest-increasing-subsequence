CC = g++
CFLAGS = -std=c++11 -O3 -Wall -lm
SRC = ./src
EXE = proj

proj: $(SRC)/proj.cpp
	$(CC) $(CFLAGS) $(SRC)/proj.cpp -o $(SRC)/$(EXE)

run::
	$(SRC)/$(EXE)

clean::
	rm $(SRC)/$(EXE)

test::
	$(MAKE) $(MFLAGS) -C tests
