/* Pointers on C - Kenneth Reek
 * Chapter 1 : Quick Start
 */

/*  Program ch1_1.c - version 1 
 ** this program controls the reading of characters
 ** the user is asked to enter a list of an even number 
 ** of integers terminated by -1 the user may enter space
 ** Author : skandaar
 ** Date : Nov 15 2021 (Imintanoute - Morocco)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 300

int buffer[BUFSIZE] = {0};
char str[BUFSIZE] = {0};

int main() {
  
  int c; 
  int i, j, buf_size; 
  int step = 2; 
  
  i = 0;
  scanf("%d", &c);
  while (c != -1 && c >= 0) {
    buffer[i] = c;
    i++;
    scanf("%d", &c);
  }
  buffer[i] = -1;
  buf_size = i + 1;
  printf("buf_size : %d\n", buf_size);
  
  /* make sure the buffer array is sorted */

  for (i = 0; i < buf_size - 2; i++) {
    if (buffer[i] > buffer[i + 1]) {
      printf("The numbers are not sorted! Abort.\n");
      exit(0);
    }
  }
  printf("The numbers are sorted\n");
  
  /* make sure the buffer contains an even number of intgers */
  
  if ((buf_size - 1) % 2) {
    printf("but not even number! Abort\n");
    exit(0);
  }
  printf("and even numbers\n");

  /* now the array is sorted and contains an even number of digits 
   * the next step is to read a stream of characters */
  
  j = 0;
  char ch;
  while ((ch = getchar()) != EOF) {
    if (ch == 10) 
      continue;
    str[j] = ch;
    j++;
  }
  str[j] = '\0';
  j = 0;
  printf("Original stream:\n");
  while (str[j] != '\0') {
    printf("%c", str[j]);
    j++;
  }
  int str_size = j + 1;
  printf(" :stream size = %d\n", str_size);
  
  /* cut the string */
  printf("Rearranged string:\n");
  char new_str[BUFSIZE] = {0};
  int k = 0;
  for (i = 0; i < buf_size - 1; i = i + step) {
    for (j = buffer[i]; j <= buffer[i + 1]; j++) {
      new_str[k] = str[j];
      k++;
    }
  }
  new_str[k] = '\0';
  int new_str_size = k + 1;

  for (k = 0; k < new_str_size - 1; k++) {
    printf("%c", new_str[k]);
  }
  printf("\n");
  
  return EXIT_SUCCESS;
}
