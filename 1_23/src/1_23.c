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

#define IN 1
#define OUT 0

int main(void) {
	int prev=0,c, state = OUT;
	while((c=getchar())!=EOF){
		if(state == OUT){
			if(c == '/'){ prev = c; continue; }
			else if(prev == '/' && c == '*'){ state = IN; }
			else if(prev == '/'){ printf("%c%c",prev,c); }
			else { printf("%c",c); }
		}else if(state == IN){
			if(c == '*'){ prev = c; continue; }
			else if(prev == '*' && c == '/'){
				state = OUT; prev = 0; continue;/* a slash ending a comment cannot start another one */
			}
		} else {/* no state other than IN/OUT */}
		prev = c;
	}
	return EXIT_SUCCESS;
}
