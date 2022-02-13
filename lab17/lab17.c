#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  char *string;
  struct list *next;
  struct list *prev;
} list;

void print_list(list *f_list) {
  while (f_list != NULL) {
    printf("%s", f_list->string);
    f_list = f_list->next;
  }
}

list *swap_elements(list *first, list *second, list *f_list) {
  list *new_begining = f_list;
  if (first->prev != NULL)
    first->prev->next = second;
  else
    new_begining = second;
  if (second->next != NULL)
    second->next->prev = first;
  list *temp1 = second->next;
  second->next = first;
  first->next = temp1;
  list *temp2 = first->prev;
  first->prev = second;
  second->prev = temp2;
  return new_begining;
}

list *sort_list(list *f_list) {
  int go = 1;
  list *current = f_list;
  while (go) { // sorting alphabet
    int changed = 0;
    while (current->next != NULL) {
      list *temp = current->next;
      if (current->string[0] > current->next->string[0]) {
        f_list = swap_elements(current, current->next, f_list);
        current = temp;
        changed = 1;
      }
      current = current->next;
    }
    current = f_list;
    if (!changed)
      go = 0;
  }
  go = 1;
  current = f_list;
  char current_letter = current->string[0];
  list *start = f_list;
  while (go) { // sorting length
    int changed = 0;
    int checked = 0;
    while (!checked) {
      if (current->next != NULL) {
        if (current->next->string[0] == current_letter) {
          if (strlen(current->string) > strlen(current->next->string)) {
            if (current == start)
              start = current->next;
            list *temp = current->next;
            f_list = swap_elements(current, current->next, f_list);
            current = temp;
            changed = 1;
          }
          current = current->next;

        } else {
          if (!changed) {
            current_letter = current->next->string[0];
            current = current->next;
            start = current;
          } else {
            checked = 1;
          }
        }
      } else {
        checked = 1;
      }
    }
    current = start;
    if (!changed)
      go = 0;
  }
  return f_list;
}

list *delete_line(list *f_list, int i) {
  int j = 1;
  int flag = 0;
  list *result = f_list;
  while (f_list != NULL && !flag) {
    if (j == i) {
      if (f_list->prev != NULL)
        f_list->prev->next = f_list->next;
      else
        result = f_list->next;
      if (f_list->next != NULL)
        f_list->next->prev = f_list->prev;
      flag = 1;
    }
    j++;
    f_list = f_list->next;
  }
  return result;
}

int main() {
  FILE *f = fopen("text.txt", "r");
  list *f_list; // first list element
  list *current;
  char *string = (char *)malloc(sizeof(char) * 100);
  int first = 1;
  int n_lines = 0;
  while (fgets(string, 100, f) != NULL) {
    if (first) {
      f_list = (list *)malloc(sizeof(list));
      f_list->string = string;
      f_list->prev = NULL;
      f_list->next = NULL;
      current = f_list;
      first = 0;
    } else {
      list *new_element = (list *)malloc(sizeof(list));
      new_element->string = string;
      new_element->prev = current;
      new_element->next = NULL;
      current->next = new_element;
      current = new_element;
    }
    n_lines++;
    string = (char *)malloc(sizeof(char) * 100);
  }
  fclose(f);
  f_list = sort_list(f_list);
  puts("Text:");
  print_list(f_list);
  int n;
  puts("Enter number of line to delete:");
  scanf("%d", &n);
  if (n > n_lines) {
    puts("You entered number that is bigger than count of lines!");
  } else {
    f_list = delete_line(f_list, n);
    puts("New text:");
    print_list(f_list);
  }
  return 0;
}
