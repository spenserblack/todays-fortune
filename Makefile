CC=gcc

bin/todays-fortune: src/main.c bin/environment.o bin/words.o
	$(CC) -o bin/todays-fortune bin/environment.o bin/words.o src/main.c

src/words.c: scripts/words.py words/* snippets/words/*
	scripts/words.py

bin/environment.o: src/environment.c src/environment.h
	$(CC) -c -o bin/environment.o src/environment.c

bin/words.o: src/words.c src/words.h
	$(CC) -c -o bin/words.o src/words.c

.PHONY: run
run: bin/todays-fortune
	./bin/todays-fortune
