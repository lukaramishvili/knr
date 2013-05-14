/*
 ============================================================================
 Name        : 1_22.c
 Author      : Luka Ramishvili
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN 1
#define IN_SINGLELINE 2

int main(void) {
	int prev=0,c, state = OUT;
	while((c=getchar())!=EOF){
		if(state == OUT){
			if(prev == '/' && c == '/'){ state = IN_SINGLELINE; }
			else if(prev == '/' && c == '*'){ state = IN; }
			else if(c == '/'){ prev = c; continue; }
			else if(prev == '/'){ printf("%c%c",prev,c); }
			else { printf("%c",c); }
		}else if(state == IN){
			if(c == '*'){ prev = c; continue; }
			else if(prev == '*' && c == '/'){
				state = OUT; prev = 0; continue;/* a slash ending a comment cannot start another one */
			}
		}else if(state == IN_SINGLELINE){
			if(c == '\n'){ state = OUT; printf("%c",c); }
		} else {/* no state other than IN/OUT */}
		prev = c;//in soviet russia, this comment reads you!
	}
	return EXIT_SUCCESS;
}
