#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, m;
  puts("Enter num of lines and num of symbols in line(n and m):");
  scanf("%d %d", &n, &m);
  getchar();
  puts("Enter text:");
  char **text = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    *(text + i) = (char *)malloc(sizeof(char) * m);
    gets(*(text + i));
  }
  for (int i = 0; i < n; i++) {
    printf("----------------------------\n");
    printf("Line %d\n", i);
    printf("----------------------------\n");
    for (int j = 0; j < strlen(*(text + i)); j++) {
      char sym = *(*(text + i) + j);
      if (sym == '#' || sym == '@' || sym == '$' || sym == '%' || sym == '&' ||
          isdigit(sym)) {
        printf("Finded symbol '%c' with adress %p\n", sym, *(text + i) + j);
        strcpy((*(text + i) + j), (*(text + i) + j + 1));
        j--;
      }
    }
  }
  printf("----------------------------\n");
  puts("New text:");
  printf("----------------------------\n");
  for (int i = 0; i < n; i++) {
    puts(*(text + i));
  }
}
