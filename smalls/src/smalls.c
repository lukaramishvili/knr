/*
 ============================================================================
 Name        : imu.c
 Author      : Luka Ramishvili
 Version     :
 Copyright   : copyleft
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main_FizzBuzz(void) {
	printf("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int i = 0;
	while(i < 100){
		if(0 == i % 3 || 0 == i % 5){
			printf((0 == i % 3)?"Fizz":"");
			printf((0 == i % 5)?"Buzz":"");
		}
		else{
			printf("%d",i);
		}
		i++;
		printf("\n");
	}
	return 0;
}

int main_CountWhiteSpace(void){
	int count = 0, c;
	while((c = getchar()) != EOF){
		if(' ' == c
				|| '\t' == c
				|| '\n' == c)
			++count;
	}
	printf("%d",count);
	return 0;
}

int main_StripMultiSpaces(void){
	int prevWasSpace = 0, c;
	while((c = getchar()) != EOF){
		if(!(prevWasSpace && ' ' == c))
			putchar(c);
		prevWasSpace = (' ' == c);
	}
	return 0;
}

int main_ReadPipe(void){
	FILE *pipe;
	int  count = 0;
	char c;
	if((pipe = (FILE*)popen("dir","r"))){//sadly, now im on mingw
		while((c = fgetc(pipe)) != EOF){
			if(/*' ' == c
					|| '\t' == c
					|| */'\n' == c)
				++count;
			printf("%c",c);
		}
		pclose(pipe);
		printf("%d",count);
	}
	else{
		printf("error.\n");
		return 1;
	}
	return 0;
}

int main_Testwc(void){
	//char curWd[256]; getcwd(curWd, 256);
	//printf("%s\n",curWd);
	//chdir("C:\\Users\\lramishvili\\workspace\\imu\\Debug\\");
	FILE *pipe;
	char c;
	if((pipe = (FILE*)popen(
"echo \"More Words now. New words Now.\\n Now is new word. \\nend line 3rd \" | wc"
			,"r"))){
		while((c = fgetc(pipe)) != EOF){
			printf("%c",c);
		}
		pclose(pipe);
	}
	else{
		printf("error.\n");
		return 1;
	}
	return 0;
}

int main_OneWordPerLine(void){
	int c, fPrevWasSpace = 0;
	while((c = getchar()) != EOF){
		//printf("%s", (c == ' ' || c == '\t' || c == '\n')? '\n' : c);
		if(c == ' ' || c == '\t' || c == '\n'){
			if(!fPrevWasSpace) {
				printf("\n");
			}
			fPrevWasSpace = 1;
		}else{
			printf("%c", c);
			fPrevWasSpace = 0;
		}
	}
	return 0;
}

int main_charHistogram(void){
	char* charBag = malloc(sizeof(char)*100);
	charBag[99] = 3;
	printf("%c", charBag[99]);
	return 0;
}

int main(void){
	return main_charHistogram();
}
