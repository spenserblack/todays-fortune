CC=gcc

bin/todays-fortune: src/main.c bin/cli.o bin/environment.o bin/words.o bin/version.o
	$(CC) -o bin/todays-fortune bin/cli.o bin/environment.o bin/words.o bin/version.o src/main.c

src/words.c: scripts/words.py words/* snippets/words/*
	scripts/words.py

bin/cli.o: src/cli.c src/cli.h
	$(CC) -c -o bin/cli.o src/cli.c

bin/environment.o: src/environment.c src/environment.h
	$(CC) -c -o bin/environment.o src/environment.c

bin/words.o: src/words.c src/words.h
	$(CC) -c -o bin/words.o src/words.c

bin/version.o: src/version.c src/version.h
	$(CC) -c -o bin/version.o src/version.c

.PHONY: run
run: bin/todays-fortune
	./bin/todays-fortune
