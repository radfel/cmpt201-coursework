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

    // Make program terminate if users press enter
    if (charRead <= 1) {
      printf("No text was entered. Program terminated.");
      free(input);
      return 0;
    }

    // ensure getline worked properly
    if (charRead < 0) {
      perror("getline failed.");
      free(input);
      exit(EXIT_FAILURE);
    }

    // print first token of the sentence
    token = strtok_r(input, " ", &saveptr);
    printf("Tokens:");

    // print all other tokens
    while (token != NULL) {
      printf("\n\t%s", token);
      token = strtok_r(NULL, " ", &saveptr);
    }
  }

  free(input);
  return 0;
}
