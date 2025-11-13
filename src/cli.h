#ifndef TODAYS_FORTUNE_CLI_H
#define TODAYS_FORTUNE_CLI_H
#include <stdbool.h>
/**
 * Should the version be shown?
 */
extern bool show_version;
/**
 * Should the help message be shown?
 */
extern bool show_help;

/**
 * Parses the arguments and updates the external variables.
 */
void cli_parse(int argc, char *argv[]);

/**
 * The help message for the CLI.
 */
extern const char *const help_message;
#endif
