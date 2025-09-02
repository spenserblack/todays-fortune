#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "words.h"

bool is_vowel(const char letter) {
  const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  for (int i = 0; i < sizeof(vowels); ++i) {
    if (letter == vowels[i]) {
      return true;
    }
  }
  return false;
}

int main(void) {
  time_t t = time(NULL);
  struct tm *tm_info = localtime(&t);

  // NOTE This combines the current day into one unique integer
  const unsigned int seed = tm_info->tm_yday + (tm_info->tm_year * 1000);
  srand(seed);

  const char* adjective = get_random_adjective();
  const char* noun = get_random_noun();
  const char* verb = get_random_verb();
  char *article = is_vowel(adjective[0]) ? "an" : "a";

  printf("You will %s %s %s %s.\n", verb, article, adjective, noun);
}
