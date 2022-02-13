#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = fopen("first.txt", "w");
  int n;
  puts("Enter number of students:");
  scanf("%d", &n);
  getchar();
  char *student_name = (char *)malloc(sizeof(char) * 100);
  char *student_surname = (char *)malloc(sizeof(char) * 100);
  int mark_1, mark_2, mark_3, mark_4;
  for (int i = 0; i < n; i++) {
    printf("Enter %d student(Surname Name M A R K):\n", i + 1);
    scanf("%s %s %d %d %d %d", student_surname, student_name, &mark_1, &mark_2,
          &mark_3, &mark_4);
    fprintf(f, "%s %s %d %d %d %d\n", student_surname, student_name, mark_1,
            mark_2, mark_3, mark_4);
  }
  fclose(f);
  f = fopen("first.txt", "r");
  FILE *g = fopen("second.txt", "w");
  char *line;
  puts("--------------------");
  puts("You entered:");
  while (fgets(line, 100, f) != NULL) {
    sscanf(line, "%s %s %d %d %d %d\n", student_surname, student_name, &mark_1,
           &mark_2, &mark_3, &mark_4);
    printf("%s %s %d %d %d %d\n", student_surname, student_name, mark_1, mark_2,
           mark_3, mark_4);
    *(student_name + 1) = '.';
    *(student_name + 2) = '\0';
    int marks = mark_1 + mark_2 + mark_3 + mark_4;
    double mean = (double)marks / 4.0;
    fprintf(g, "%s %s %lf\n", student_surname, student_name, mean);
  }
  fclose(f);
  fclose(g);
  return 0;
}
