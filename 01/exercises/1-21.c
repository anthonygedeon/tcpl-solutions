/// K&R Exercise 1-21
/// Write a program that takes as input text with spaces and produces as output 
/// visually equivalent text using tabs to the maximum extent possible.
/// 
/// For example, with tabstops every 8 characters, and showing spaces as '.' and tabs as '-';
/// 
/// input;
/// ".foo:...bar;......#comment"
/// output;
/// ".foo:-bar;-..#comment"
/// 
/// input;
/// ".......-foo:.....bar;......#comment"
/// output;
/// "-foo:-.bar;-...#comment"
/// 
/// Write the program so that tabstop parameter n can be varied, i.e. allow values of n other than 8. Be prepared to justify your decision to make n a constant, or alternatively a variable.

#include <stdio.h>

#define TABSTOP 8

/// Example input:
/// foo:   bar;      #comment
///			foo:     bar;      #comment

int main() {
	int col = 0;

	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			col = 0;
		}

		if (c == '\t') {
			++col;
		}

		if (c == '\t' || c == ' ') {
			if (col == TABSTOP) {
				putchar('-');
			}
		}
		
		++col;

		putchar(c);
	}
}

