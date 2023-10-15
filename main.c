#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
file encryption system don't get mad If I spelt it wrong
*/

void encrypt(char text[], int shift) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
    } else if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
    }
  }
}

void unencrypt(char text[], int shift) {
  encrypt(text, 26 - shift);
}

int main() {
  char fil[50];
  printf("Enter a file name: ");
  scanf("%s", fil);

  FILE *file = fopen(fil, "r");
  FILE *pfile = fopen("encript.txt", "w");

  if (file == NULL) {
    printf("File not found or unable to open.\n");
    return 1;
  }

  char words[1000];
  int shift = 3;

  while (fgets(words, sizeof(words), file) != NULL) {
    encrypt(words, shift);
    fprintf(pfile, "%s \n", words);
    printf("> encrypted: %s", words);

    
    unencrypt(words, shift);
    printf("> decrypted: %s", words);
  }

  fclose(file);
  fclose(pfile);

  return 0;
}
