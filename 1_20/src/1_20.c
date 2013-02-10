/*
 ============================================================================
 Name        : 1_20.c
 Author      : Luka Ramishvili
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB 4

int main(void) {
	int c=0, i=1;
	while((c=getchar()) != EOF){
		if('\n'==c){
			i=1;
			printf("%c",c);
		}
		else if('\t'==c){
			printf(" ");
			while(i++ % TAB != 0)
				printf(" ");
			i=1;
		}
		else{
			printf("%c",c);
			i++;
		}
	}
	return EXIT_SUCCESS;
}
