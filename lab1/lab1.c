// Felicia Radjab
// September 19, 2026
// A program that takes input from a user, tokenizes it with a delimeter, and prints out each token
// on a new line

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *input = NULL;
  size_t len = 0;

  char *saveptr = NULL;
  char *token;
  int index = 0;

  while (index < 10) {
    printf("Please enter some text: ");
    ssize_t charRead = getline(&input, &len, stdin);

    if (charRead <= 1) {
      printf("No text was entered. Program terminated.");
      free(input);
      return 0;
    }

    token = strtok_r(input, " ", &saveptr);
    printf("Tokens:");

    while (token != NULL) {
      printf("\n\t%s", token);
      token = strtok_r(NULL, " ", &saveptr);
    }
  }

  free(input);
  return 0;
}
