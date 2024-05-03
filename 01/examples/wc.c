#include <stdio.h>

int main() {
	int nl = 0;
	int nc = 0;
	int nw = 0;

	int is_word = 0;

	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			nl++;
		}

		if (c == '\n' || c == '\t' || c == ' ') {
			is_word = 1;
		} else if (is_word) {
			nw++;
			is_word = 0;
		}

		nc++;
  }

	printf("Newlines: %i\tWords: %i\tChars: %i\n", nl, nw, nc);

	return 0;
}
