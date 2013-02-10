/*
 ============================================================================
 Name        : 1_21.c
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
	int c,prev=EOF,i=1,accum=0;
	while((c=getchar()) != EOF){
		if('\t'==c){
			if('\t'==prev){ accum += TAB; }
			else{ accum += TAB - (i-1)%TAB; } /*increment accum by what's left to the next tab stop*/
		}
		else if(' '==c){
			accum++;
		}
		else{
			//first, insert spaces (or a tab, if enough accum) to fill to the nearest tab stop
			int until_tabstop = TAB - (i-1)%TAB;
			if(accum >= until_tabstop){ printf("\t"); accum -= until_tabstop; i+= until_tabstop; }
			while(accum > 0 && (i - 1) % TAB != 0){
				printf(" ");
				accum--;
				i++;
			}
			//then print as many tabs as will fit in accum
			while(accum/TAB > 0){
				printf("\t"); accum -= TAB;
			}
			while(accum--){
				printf(" ");
				i++;
			}
			//reset blank counting, reset tab stop counting on newline
			accum=0;
			if('\n'==c) i=1; else i++;
			printf("%c",c);
		}
		prev = c;
	}
	return EXIT_SUCCESS;
}
