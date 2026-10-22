#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int data;
  struct tree *left;
  struct tree *right;
} tree;

void inorder(tree *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d", root->data);
  inorder(root->right);
}

void postorder(tree *root) {
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d", root->data);
}

void preorder(tree *root) {
  if (root == NULL)
    return;
  printf("%d", root->data);
  preorder(root->left);
  preorder(root->right);
}

tree *createtree() {
  int x;
  printf("Enter Value (-1 is no root)");
  scanf("%d", &x);
  if (x == -1) {
    return NULL;
  }
  tree *root = malloc(sizeof(tree));
  root->data = x;

  printf("Enter Left Child");
  root->left = createtree();

  printf("Enter Right Child");
  root->right = createtree();

  return root;
}

int main() {
  int x;

  tree *root = createtree();

  printf("Select Trvaersal \n 1.Inorder 2.Postorder 3.Preorder");
  scanf("%d", &x);

  switch (x) {
  case 1:
    printf("Inorder Traversal Results");
    inorder(root);

  case 2:
    printf("Postorder Traversal Results");
    postorder(root);

  case 3:
    printf("Preorder Traversal Results");
    preorder(root);
  }
}
