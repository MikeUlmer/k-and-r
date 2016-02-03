/* Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 * 
 */ 
#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main() {
	int len;
	char line[MAXLINE];
	
	// No reversing of blank lines
	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line);
		printf("\nReversed Line:\n%s\n", line);
	}

	return 0;
}

int get_line(char s[], int lim) {
	int c, i;
	
	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) { //Cut out intermediary line breaks
		s[i] = c;
	}
	// Add a final line break
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
/*
 * Note (again) I'm passing in the VALUE of the s's address.
 */ 
void reverse(char s[]) {
	char t;
	int i = 0, j = 0;
	int end = 0;
	
	// Is there a way to introspect s's structure and discover its length? I calculated it via 'len' above,
	// but due to directions could not pass it in.
	while (s[i] != '\0') {
		++i;
		end = i;
	}
	
	for (i = 0, j = end - 2; i < end / 2; ++i, --j) {  //note end - 2; Due to char terminator & line break
		//The end / 2 limit tripped me up. Didn't have it before and my string looked exactly the same!
		// I was reverse-reversing it!
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
