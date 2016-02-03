#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

main() {
	int len;
	// Common practise is to place all external definitions @ beginning of source file & omit all
	// "extern" declarations.
	// The extern keyword usage within functions of this file is redundant since I use them after they're declared.
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
