#include <stdbool.h>
#include <string.h>
#include "cli.h"

bool show_version = false;
bool show_help = false;

void cli_parse(int argc, char *argv[]) {
	for (int i = 0; i < argc; ++i) {
		const char *arg = argv[i];
		if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0) {
			show_version = true;
		} else if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
			show_help = true;
		}
	}
}

const char *const help_message =
	"todays-fortune [OPTIONS]\n"
	"OPTIONS:\n"
	"\t-h, --help\tShow this message and quit\n"
	"\t-v, --version\tShow the version and quit\n";
