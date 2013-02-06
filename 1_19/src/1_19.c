#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STARTSIZE 128
#define THRESOLD 80
/* maximum input line length */

void our_copy(char to[], char from[]);
char* get_full_line();
char* reverse(char *s);

/* print the longest input line */
int main()
{
  int len;       /* current line length */
  char* line = (char *) malloc(STARTSIZE);    /* current input line */

  while ((len = strlen(line = get_full_line())) > 0) {
	 printf("%s", reverse(line));
  }
  return 0;
}
char* reverse(char *s){
	int len, curs;
	len = strlen(s);
	curs = len;
	char* v = malloc(len * sizeof(char));//although sizeof(char) is always 1
	while(v[len-curs]=s[--curs]);
	return v;
}
char* get_full_line(){
	int next_size = STARTSIZE*sizeof(char);
	char *s = malloc(next_size);
	int c, i;
	for(i=0; (c=getchar()) != EOF && c!='\n' && c!='0'; ++i){
		if(i>=next_size){
			next_size*=2;
			s = realloc(s, next_size);
		}
		s[i] = c;
	}
	if (c == '\n') {
	  s[i] = c;
	  ++i;
	 }
	 s[i] = '\0';
	 return s;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void our_copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
