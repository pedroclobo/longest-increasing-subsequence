CC = g++
CFLAGS = -std=c++11 -O3 -Wall -lm -g
MFLAGS += --no-print-directory

all:: proj

proj: src/proj.cpp
	$(CC) $(CFLAGS) src/proj.cpp -o src/proj

run:: proj
	./src/proj

clean::
	rm src/proj

tests:: proj
	@$(MAKE) $(MFLAGS) -C tests
