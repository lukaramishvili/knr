#include <stdio.h>
#define MAXLINE 1000
/* maximum input line length */

int our_getline(char line[], int maxline);
void our_copy(char to[], char from[]);

/* print the longest input line */
int main()
{
  int len; /* current line length */
  int max; /* maximum length seen so far */
  char line[MAXLINE]; /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = our_getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      our_copy(longest, line);
    }
  if (max > 0) /* there was a line */
    printf("%s", longest);
  return 0;
}
/* getline: read a line into s, return length */
int our_getline(char s[],int lim)
{
  int c, i;
  // && c!='0' added below because eclipse cannot use Ctrl+D to send EOF
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n' && c!='0'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void our_copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
