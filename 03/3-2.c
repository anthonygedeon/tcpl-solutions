#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape(const char* s, char* t);
void unescape(const char* s, char* t);

int main(void) {
	char target_1[1024];

	const char* source = "Hello,\tWorld!\nGoodbye,\tWorld!\n";
	escape(source, target_1);
	printf("%s\n", target_1);

	char target_2[1024];
	source = "Hello,\\tWorld!\\nGoodbye,\\tWorld!\\n";
	unescape(source, target_2);
	printf("%s\n", target_2);

	return EXIT_SUCCESS;
}

void unescape(const char* s, char* t) {
	char escape = ' ';
	int state = 1;
	int j = 0;
	for (int i = 0; i < strlen(s); i += 1) {
		switch (s[i]) {
			case '\\': 
				if (s[i+1] == 'n') {
					state = 0;
					escape = '\n';
				} else if (s[i+1] == 't')  {
					state = 0;
					escape = '\t';
				}
				break;
			default:
				if (state == 1) {
					t[j] = s[i];
					j += 1;
				} else {
					t[j] = escape;
					state = 1;
					j += 1;
				}
				break;
		}
	}
	t[j] = '\0';
}

void escape(const char* s, char* t) {
	int j = 0;
	for (int i = 0; i < strlen(s); i += 1) {
		switch (s[i]) {
			case '\n': 
				t[j] = '\\';
				t[j+1] = 'n';
				j += 2;
				break;
			case '\t': 
				t[j] = '\\';
				t[j+1] = 't';
				j += 2;
				break;
			default:
				t[j] = s[i];
				j += 1;
				break;
		}
	}
	t[j] = '\0';
}
