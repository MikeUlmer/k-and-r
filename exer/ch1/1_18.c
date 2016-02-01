/* Original instructions: 
 * Remove trailing blanks & tabs from each line and delete entireley blank lines
 * 
 * What I decided to do: 
 * Remove (ANY) trailing blanks & tabs from each line and delete entireley blank lines
 */ 

#include <stdio.h>

#define MAXLINE 1000
#define IN 1
#define OUT 0

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("Modified Line: %s\n", line);
		printf("Type new input...\n");
	}
	
	return 0;
}

int get_line(char s[], int lim) {
	int c, i, j, found_offending;
	int state = OUT;
	char previous;
	
	for (i = 0, j = 0; i < lim - 1 && (c=getchar()) != EOF; i++) {
		found_offending = (c == ' ' || c == '\t' || c == '\n');
		
		if (state == OUT && found_offending) {
			continue;
		} else if (found_offending) {
			state = OUT;
		} else if (state == OUT && !found_offending) {
			state = IN;
			if (previous == ' ' || previous == '\t' || previous == '\n') {
				s[j] = previous;
				++j;
			}
		}
		
		if (state == IN) {
			s[j] = c;
			++j;
		}
		
		previous = c;  // Use previous--any offending chars are considered trailing.
	}
	if (c == '\n') {
		s[j] = c;
		++j;
	}
	s[j] = '\0';
	return j;
}
