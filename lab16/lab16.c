#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *string, int i) {
  if (i >= strlen(string))
    return 1;
  if (i == 0) {
    if (!((*(string) <= 'Z' && *(string) >= 'A') ||
          (*(string) >= 'a' && *(string) <= 'z')))
      return 0;
    else
      return check(string, i + 1);
  } else {
    if ((*(string + i) <= 'Z' && *(string + i) >= 'A') ||
        (*(string + i) >= 'a' && *(string + i) <= 'z') ||
        (*(string + i) >= '1' && *(string + i) <= '9')) {
      return check(string, i + 1);
    } else {
      return 0;
    }
  }
}

int main() {
  char *string = (char *)malloc(sizeof(char) * 100);
  puts("Enter string:");
  gets(string);
  int result = check(string, 0);
  if (result) {
    puts("Yes");
  } else {
    puts("No");
  }
}
