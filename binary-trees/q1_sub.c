#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int data;
  struct tree *left;
  struct tree *right;
} tree;

tree *createtree() {
  int x;
  printf("Enter value to be insert (-1 is NULL)\n");
  scanf("%d", &x);
  if (x == -1) {
    return NULL;
  }

  tree *root = (tree *)malloc(sizeof(tree));

  root->data = x;

  printf("Left Node \n");
  root->left = createtree();
  printf("Right Node");
  root->right = createtree();

  return root;
}

int height(tree *root) {
  if (root == NULL) {
    return -1;
  }
  int l = height(root->left);
  int r = height(root->right);

  return 1 + ((l > r) ? l : r);
}

int parent(tree *root, int key) {
  if (root == NULL) {
    printf("No parent");
    return 0;
  }

  if ((root->left && root->left->data == key) ||
      (root->right && root->right->data == key)) {
    printf("Pareent of %d is %d", key, root->data);
    return 1;
  }

  return parent(root->left, key) || parent(root->right, key);
}

int leafcount(tree *root) {
  if (root == NULL) {
    return 0;
  }
  if (root->left == NULL && root->right == NULL) {
    return 1;
  }
  return leafcount(root->left) + leafcount(root->right);
}

int ancestors(tree *root, int key) {
  if (root == NULL) {
    printf("No ancestors");
    return 0;
  }
  if (root->data == key) {
    return 1;
  }

  if (ancestors(root->left, key) || ancestors(root->right, key)) {
    printf("%d", root->data);
    return 1;
  }

  return 0;
}

void inorder(tree *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d", root->data);
  inorder(root->right);
}

void postorder(tree *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d", root->data);
}

void preorder(tree *root) {
  if (root == NULL) {
    return;
  }
  printf("%d", root->data);
  preorder(root->left);
  preorder(root->right);
}

int main() {
  int x, key;
  tree *root = malloc(sizeof(tree));
  do {
    printf("Choice\n1.Create \n2.Inorder "
           "\n3.Postorder\n4.Preorder\n5.Height\n6.Parent\n7.Leaf "
           "Count\n8.Ancestors\n9Exit");
    scanf("%d", &x);
    switch (x) {
    case 1:
      root = createtree();
      break;
    case 2:
      inorder(root);
      break;
    case 3:
      postorder(root);
      break;
    case 4:
      preorder(root);
      break;
    case 5:
      printf("Height = %d\n", height(root));
      break;
    case 6:
      printf("Enter key");
      scanf("%d", &key);
      parent(root, key);
      break;
    case 7:
      printf("Leaf count = %d\n", leafcount(root));
      break;
    case 8:
      printf("Enter key");
      scanf("%d", &key);
      ancestors(root, key);
    default:
      printf("Invalid Choice");
    }
  } while (x != 9);
}
