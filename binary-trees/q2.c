#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int data;
  struct tree *left;
  struct tree *right;
} tree;

tree *createtree() {
  int x;
  printf("Enter data of node (-1 is NULL)");
  scanf("%d", &x);
  if (x == -1) {
    return NULL;
  }
  tree *root = malloc(sizeof(tree));

  root->data = x;

  printf("Left Child");
  root->left = createtree();
  printf("Right Child");
  root->right = createtree();

  return root;
}

int height(tree *root) {
  if (root == NULL) {
    return 0;
  }
  int l = height(root->left);
  int r = height(root->right);

  return 1 + ((l > r) ? l : r);
}
void printlevel(tree *root, int level) {
  if (root == NULL) {
    return;
  }
  if (level == 1) {

    printf("%d", root->data);
    return;
  }

  printlevel(root->left, level - 1);
  printlevel(root->right, level - 1);
}
void levelorder(tree *root) {

  int h = height(root);

  for (int i = 1; i <= h; i++) {
    printlevel(root, i);
  }
}
int main() {
  tree *root = createtree();
  levelorder(root);
}
