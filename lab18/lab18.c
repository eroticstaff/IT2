#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

Node *create_node(int data) {
  Node *result = (Node *)malloc(sizeof(Node));
  result->data = data;
  result->left = NULL;
  result->right = NULL;
  return result;
}

int digit_sum(int data) {
  int sum = 0;
  int N = data;
  int digit_count = 0;
  while (N > 1) {
    digit_count++;
    N /= 10;
  }
  int i;
  if (digit_count % 2 == 0) {
    i = 1;
  } else {
    i = 2;
  }
  while (data > 1) {
    if (i % 2 == 0) {
      sum += data % 10;
    }
    data /= 10;
    i++;
  }
  return sum;
}

void node_insert(Node *root, int data) {
  if (digit_sum(root->data) > digit_sum(data)) {
    if (root->left == NULL) {
      Node *new_node = create_node(data);
      root->left = new_node;
      new_node->parent = root;
    } else {
      node_insert(root->left, data);
    }
  } else {
    if (root->right == NULL) {
      Node *new_node = create_node(data);
      root->right = new_node;
      new_node->parent = root;
    } else {
      node_insert(root->right, data);
    }
  }
}

int check_number(int data) {
  int checked = 1;
  while (data > 1 && checked) {
    int number = data % 10;
    if (number % 2 != 0)
      checked = 0;
    data /= 10;
  }
  return checked;
}

void find_numbers(Node *root) {
  int isOkey = check_number(root->data);
  if (isOkey)
    printf("Number %d\n", root->data);
  if (root->left != NULL)
    find_numbers(root->left);
  if (root->right != NULL)
    find_numbers(root->right);
}

void print_tree(Node *root, int i, int isRight, int changed) {
  int new_changed = changed;
  if (isRight)
    new_changed = 1;
  if (root->right != NULL)
    print_tree(root->right, i + 1, 0, new_changed);
  printf("\n");
  for (int j = 0; j < i; j++) {
    if (j == i - 1)
      printf(".---");
    else {
      if (changed) {
        printf("|   ");
      } else
        printf("    ");
    }
  }
  printf("%d, %d", root->data, digit_sum(root->data));
  printf("\n");
  if (!isRight)
    new_changed = 1;
  else
    new_changed = 0;
  if (root->left != NULL)
    print_tree(root->left, i + 1, 1, new_changed);
}

Node *find_min_element(Node *root) {
  if (root->left == NULL) {
    return root;
  } else {
    return find_min_element(root->left);
  }
}

void delete_node(Node *root, int value) {
  if (root == NULL) {
    printf("No such value!");
  } else {
    printf("Current %d\n", root->data);
    if (root->data == value) {
      puts("Deleting... ");
      printf("Element is %d with adress %p\n", root->data, root);
      if (root->left == NULL && root->right == NULL) {
        printf("BOTH\n");
        if (root->parent->right != NULL) {
          if (root->parent->right == root) {
            root->parent->right = NULL;
            free(root);
          }
        }
        if (root->parent->left != NULL) {
          if (root->parent->left == root) {
            root->parent->left = NULL;
            free(root);
          }
        }
      } else if (root->left == NULL) {
        if (root->parent->right != NULL) {
          if (root->parent->right == root) {
            root->parent->right = root->right;
            root->right->parent = root->parent;
            free(root);
          }
        }
        if (root->parent->left != NULL) {
          if (root->parent->left == root) {
            root->parent->left = root->right;
            root->right->parent = root->parent;
            free(root);
          }
        }
      } else if (root->right == NULL) {
        if (root->parent->right != NULL) {
          if (root->parent->right == root) {
            root->parent->right = root->left;
            root->left->parent = root->parent;
            free(root);
          }
        }
        if (root->parent->left != NULL) {
          if (root->parent->left == root)
            root->parent->left = root->left;
          root->left->parent = root->parent;
          free(root);
        }

      } else if (root->right != NULL && root->left != NULL) {
        puts("NOBOTH");
        Node *min_element = find_min_element(root->right);
        printf("min element is %d\n", min_element->data);
        root->data = min_element->data;
        delete_node(min_element, min_element->data);
      }
    } else if (digit_sum(root->data) > digit_sum(value)) {
      delete_node(root->left, value);
    } else if (digit_sum(root->data) <= digit_sum(value)) {
      delete_node(root->right, value);
    }
  }
}

int main() {
  srand(time(NULL));
  Node *root = create_node(15);
  int n = 9;
  for (int i = 0; i < n; i++) {
    node_insert(root, rand() % 10000);
  }
  puts("Source tree:");
  print_tree(root, 0, 0, 0);
  while (1) {
    int n;
    puts("Enter n to delete:");
    scanf("%d", &n);
    printf("Trying to delete %d\n", n);
    delete_node(root, n);
    puts("New tree:");
    print_tree(root, 0, 0, 0);
  }
  find_numbers(root);
}
