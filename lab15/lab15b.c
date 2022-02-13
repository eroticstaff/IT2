#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n;
  srand(time(NULL));
  puts("Enter number of numbers:");
  scanf("%d", &n);
  FILE *f = fopen("f1.bin", "wb");
  for (int i = 0; i < n; i++) {
    int num = rand() % 100 - 50;
    fwrite(&num, sizeof(num), 1, f);
  }
  fclose(f);
  f = fopen("f1.bin", "rb");
  FILE *g = fopen("f2.bin", "wb");
  int num;
  puts("Numbers:");
  int i = 1;
  while (fread(&num, sizeof(num), 1, f) != NULL) {
    printf("%d ", num);
    if (i % 2 == 1) {
      fwrite(&num, sizeof(num), 1, g);
    }
    i++;
  }
  puts("");
  fclose(f);
  fclose(g);
  g = fopen("f2.bin", "rb");
  puts("New file:");
  while (fread(&num, sizeof(num), 1, g) != NULL) {
    printf("%d ", num);
  }
  fclose(g);
  return 0;
}
