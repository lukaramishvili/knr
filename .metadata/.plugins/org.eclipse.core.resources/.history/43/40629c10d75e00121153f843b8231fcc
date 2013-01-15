#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 32

int main(){
	int nlength[MAX_WORD_LENGTH], c, state = OUT, i, j, lastlen = 0, maxlen = 0, maxtimes = 0;
	for(i = 0; i < MAX_WORD_LENGTH; i++) nlength[i]=0;
	while((c=getchar())!=EOF){/* && c != '0' - eclipse cannot send EOF*/
		if(' ' == c || '\n' == c || '\t' == c){
			state=OUT;
			if(lastlen > 0){
				nlength[lastlen-1]++;
				if(nlength[lastlen-1] > maxtimes)
					maxtimes = nlength[lastlen-1];
			}
			if(lastlen > maxlen){
				maxlen = lastlen;
			}
			lastlen = 0;
		}
		else{
			state = IN;
			lastlen++;
		}
	}
	//horizontal bars
	for(i = 0; i < MAX_WORD_LENGTH; i++){
		if(0==nlength[i]) continue;
		printf("%d\t",i+1);
		for(j = 0; j < nlength[i]; j++){
			printf("=");
		}
		printf(" %d times.\n",nlength[i]);
	}
	//vertical histogram
	for(i = -1; i < maxtimes; i++){
		for(j=0; j<MAX_WORD_LENGTH; j++){
			if(0==nlength[j]) continue;
			if(-1==i){
				printf("%d\t", j+1);
				continue;
			}
			if(maxtimes-i <= nlength[j]) printf("H");
			printf("\t");
		}
		printf("\n");
	}
	printf("end");
	return 0;
}
