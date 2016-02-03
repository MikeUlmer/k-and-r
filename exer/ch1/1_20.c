/* Write a program, detab, that replaces tabs in the iput with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops,
 * say every n columns. Should n be a variable or a symbolic parameter?
 * 
 */ 
#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

main() {
	int len;
	extern int max = 0;
	extern char longest[];
	
	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	
	if (max > 0) {
		printf("%s", longest);
	}
	return 0;
}

int get_line(void) {
	extern char line[];
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copy(void) {
	int i = 0;
	extern char line[], longest[];
	while ((longest[i] = line[i]) != '\0') {
		++i;
	}
}
