#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "environment.h"
#include "words.h"

bool is_vowel(const char letter) {
	switch (letter) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
	}
	return false;
}

unsigned int get_username_seed() {
	#define USERNAME_LEN 30
	unsigned int seed = 0;
	char buf[USERNAME_LEN];
	unsigned char i;
	char c;
	if (get_username(buf, USERNAME_LEN)) {
		return 0;
	}

	for (i = 0; (c = buf[i]) != '\0'; ++i) {
		seed += c;
	}

	return seed;
	#undef USERNAME_LEN
}

int main(void) {
	time_t t = time(NULL);
	struct tm *tm_info = localtime(&t);

	// NOTE This combines the current day into one unique integer
	const unsigned int time_seed = tm_info->tm_yday + (tm_info->tm_year * 1000);

	const unsigned int username_seed = get_username_seed();

	srand(time_seed + username_seed);

	const char *const adjective = get_random_adjective();
	const char *const noun = get_random_noun();
	const char *const verb = get_random_verb();
	const char *const article = is_vowel(adjective[0]) ? "an" : "a";

	printf("You will %s %s %s %s.\n", verb, article, adjective, noun);
}
