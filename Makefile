CC=gcc

bin/todays-fortune: src/main.c bin/words.o
	$(CC) -o bin/todays-fortune bin/words.o src/main.c

src/words.c: scripts/words.py words/* snippets/words/*
	scripts/words.py

bin/words.o: src/words.c src/words.h
	$(CC) -c -o bin/words.o src/words.c

.PHONY: run
run: bin/todays-fortune
	./bin/todays-fortune
