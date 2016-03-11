/*
 * Write a program entab that replaces strings of blanks by the minimum 
 * number of tabs and blanks to achieve the same spacing. Use the same 
 * tab stops as for detab. When either a tab or a single blank would 
 * suffice to reach a tab stop, which should be given preference?
 * 
 * Ran into weird stuff with tabs here--think it's TTY-related. I would 
 * tab and it would take up 4 spaces, next tab would take up 8, next take
 * diff # etc.
 * Instead of trying to figure that out, I output a 'T' for where a tab
 * should be and a '-' to output spaces.
 */

#include <stdio.h>

#define MAXLINE 1024
#define SPACE ' '
#define NEW_SPACE '-'
#define NEW_TAB 'T'
#define TAB_STOP 4

int get_line(char line[], int maxline);

int main(void) {
	int len, i, blank_count, num_tabs, num_spaces, output;
	char line[MAXLINE];
	// Decided against copying blank-replaced string into a, say, new_line[MAXLINE] 
	// and printing that line although it wouldn't be such a bad thing:
	// "line" would always be as long or shorter than MAXLINE due to 
	// reducing number of chars (conv space to char).
	
	while ((len = get_line(line, MAXLINE)) > 0) {
		for (i = 0; i < len; ++i) {
			if (line[i] != SPACE) {
				putchar(line[i]);
				continue;
			}
			
			//// START Blank substitution
			blank_count = 0;
			while (line[i] == SPACE) {
				++blank_count;
				++i;
			}
			num_tabs = blank_count / TAB_STOP;
			num_spaces = blank_count % TAB_STOP != 0 ? blank_count - (TAB_STOP * num_tabs) : 0;
			//printf("\nNumber tabs: %d\n", num_tabs);
			//printf("\nNumber spaces: %d\n", num_spaces);
			for(output = 0; output < num_tabs; ++output) {
				putchar(NEW_TAB);
			}
			for(output = 0; output < num_spaces; ++output) {
				putchar(NEW_SPACE);
			}
			//// END Blank substitution
			
			putchar(line[i]);
		}
	}
		
	return 0;
}

int get_line(char line[], int maxline) {
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
