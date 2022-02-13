#include <stdio.h>
#include <stdlib.h>

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

void node_insert(Node *root, int data) {
  if (root->data < data) {
    if (root->left == NULL) {
      Node *new_node = create_node(data);
      root->left = new_node;
    } else {
      node_insert(root->left, data);
    }
  } else {
    if (root->right == NULL) {
      Node *new_node = create_node(data);
      root->right = new_node;
    } else {
      node_insert(root->right, data);
    }
  }
}

void print_tree(Node *root, int i, int isRight, int changed) {
  int new_changed = changed;
  if (isRight)
    new_changed = 1;
  if (root->left != NULL)
    print_tree(root->left, i + 1, 0, new_changed);
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
  printf("%d,%d", root->data, changed);
  printf("\n");
  if (!isRight)
    new_changed = 1;
  else
    new_changed = 0;
  if (root->right != NULL)
    print_tree(root->right, i + 1, 1, new_changed);
}

int main() {
  Node *root = create_node(15);
  node_insert(root, 10);
  node_insert(root, 32);
  node_insert(root, 20);
  node_insert(root, 14);
  node_insert(root, 9);
  node_insert(root, 7);
  node_insert(root, 10);
  node_insert(root, 1);
  node_insert(root, 6);
  node_insert(root, 16);
  node_insert(root, 38);
  node_insert(root, 35);
  node_insert(root, 17);
  node_insert(root, 13);
  node_insert(root, 12);

  print_tree(root, 0, 0, 0);
}
