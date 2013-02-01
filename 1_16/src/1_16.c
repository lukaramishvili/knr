#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STARTSIZE 128
/* maximum input line length */

int our_getline(char line[], int lim);
void our_copy(char to[], char from[]);
char * get_full_line();
void copy_anysize(char to[], char from[], int length);

/* print the longest input line */
int main()
{
  int len;       /* current line length */
  int max = 0;   /* maximum length seen so far */
  char* line = (char *) malloc(STARTSIZE);    /* current input line */
  char* longest = (char *) malloc(STARTSIZE); /* longest line saved here */

  while ((len = strlen(line = get_full_line())) > 0) {
    if (len > max) {
      max = len;
      longest = realloc(longest, strlen(line));
      our_copy(longest, line);
    }
  }
  if (max > 0) { /* there was a line */
    printf("%d %s\n", max, longest);
  }
  return 0;
}
/* getline: read a line into s, return length */
int our_getline(char s[],int lim)
{
  int c, i;
  // && c!='0' added below because eclipse cannot use Ctrl+D to send EOF
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n' && c!='0'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
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
