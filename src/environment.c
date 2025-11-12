#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "environment.h"

static const char *username_variables[] = {"USERNAME", "USER"};

bool get_username(char *buf, const unsigned char buflen) {
  for (unsigned int i = 0; i < sizeof(username_variables) / sizeof(char*); ++i) {
    const char *username = getenv(username_variables[i]);
    if (username != NULL) {
      strncpy(buf, username, buflen - 1);
      buf[buflen - 1] = '\0';

      return false;
    }
  }

  return true;
}
