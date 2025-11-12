#ifndef FORTUNE_ENVIRONMENT_H
#define FORTUNE_ENVIRONMENT_H
#include <stdlib.h>
#include <stdbool.h>
/**
 * Fills the environment's username into the buffer. Does not permit long usernames.
 *
 * Returns `true` on failure, `false` on success.
 */
bool get_username(char *buf, const unsigned char buflen);
#endif
