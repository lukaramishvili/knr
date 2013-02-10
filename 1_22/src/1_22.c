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

#define BR 5

int main(void) {
	int c,pos=0;
	while((c=getchar())!=EOF){
		printf("%c",c);
		if(pos>=BR){
			pos=0;
			printf("\n");
		}
		else{
			('\n'==c) ? pos=0 : pos++;
		}
	}
	return EXIT_SUCCESS;
}
