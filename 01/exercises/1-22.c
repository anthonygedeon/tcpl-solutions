///
/// I think this exercise is basically emulating a "word-wrap" function you might see on a text editor. "blank" would mean "whitespace", e.g. space or tab characters.
/// 
/// Example:
/// 
/// "Once upon a time"
/// 
/// If you were asked to "fold" that line after the 14th column of input, the 14th character is the "i" in "time". Your output should be two lines: "Once upon a", "time".
/// 
/// The question also says to be intelligent with very long lines.
/// 
/// For example,
/// 
/// "Once upon a time Once upon a time Once upon a time"
/// 
/// If you were splitting this line at 14 characters, you should consider the fact that the line must be split into more than two lines.
/// 
/// There is also the case when a word could be very long, preventing you from splitting it:
/// 
/// "Deoxyribonucleicacid is DNA"
/// 
/// If you split that at 14 characters, you would not find any whitespace characters until " is", so the word should be split.
///

#include <stdio.h>
#include <stdlib.h>

#define COLUMN  10
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
	int len;
	int location = 0;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0) {
		for (int i = 0; i < len; i += 1) {
			if (line[i] == ' ') {
				line[i] = '\n';
			}
		}
		
		location += 1;
	}

	printf("%s\n", line);

	return EXIT_SUCCESS;
}

int get_line(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i += 1) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i += 1;
	}
	s[i] = '\0';
	return i;
}

