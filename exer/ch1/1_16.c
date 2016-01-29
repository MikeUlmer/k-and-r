#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	
	/*char l;
	for (l = 'a'; l < 'k'; ++l) {
		for (max = 0; max < 100; ++max) {
			putchar(l);
		}
	}
	printf("\n");*/
		
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	
	if (max > 0) {
		printf("\nLength of longest: %d\n", max);
		printf("\n%s\n", longest);
	}
	return 0;
}

int get_line(char s[], int lim) {
	int c, i;
	
	for (i = 0; (c=getchar()) != EOF && c != '\n'; i++) {
		if (i < lim - 1) {
			s[i] = c;
		}
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i - 1;
}

void copy(char to[], char from[]) {
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
