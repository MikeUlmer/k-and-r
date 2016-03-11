/* Write a program, detab, that replaces tabs in the iput with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops,
 * say every n columns. Should n be a variable or a symbolic parameter?
 * 
 */ 
#include <stdio.h>

#define MAXLINE 1000
#define TAB_TO_SPACE 4
#define SPACE '-'

int get_line(char line[], int maxline);

int main() {
	int len;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("\nSpaced Line:\n%s\n%d in length\n", line, len);
	}
	return 0;
}

int get_line(char line[], int maxline) {
	int c, i, space;

	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		if (c == '\t') {
			for (space = 0; space < TAB_TO_SPACE; ++space, ++i) {
				line[i] = SPACE;
			}
			// My TAB_TO_SPACE loop increments i when the condition fails so 
			// I subtract to get i back to the right index in "line"
			--i;  
		} else {
			line[i] = c;
		}
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
