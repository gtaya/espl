/* $Id: count-words.c 858 2010-02-21 10:26:22Z tolpin $ */

#include <stdio.h>
#include <string.h>

/* return string "word" if the count is 1 or "words" otherwise */
void words(int count, char * chars) {
  if(count==1) 
    chars[strlen(chars)-1] = '\0';
}

/* print a message reportint the number of words */
int print_word_count(char **argv) {
  int count = 0;
  char **a = argv;
  char chars[] = "words";
  while(*(a++))
    ++count;
  words(count, chars);
  printf("The sentence contains %d %s.\n", count, chars);
  return count;
}

/* print the number of words in the command line and return the number as the exit code */
int main(int argc, char **argv) {
  return print_word_count(argv+1);
}

   
