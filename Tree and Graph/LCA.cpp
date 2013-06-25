/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 24, 2013, 7:27 PM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree* parent;
    int data;
};

//For BST
BinaryTree *LCA(BinaryTree *root, BinaryTree *p, BinaryTree *q) {
  if (!root || !p || !q) return NULL;
  if (max(p->data, q->data) < root->data)
    return LCA(root->left, p, q);
  else if (min(p->data, q->data) > root->data)
    return LCA(root->right, p, q);
  else
    return root;
}

//For BT
BinaryTree *LCA(BinaryTree *root, BinaryTree *p, BinaryTree *q) {
  if (!root) return NULL;
  if (root == p || root == q) return root;
  BinaryTree *L = LCA(root->left, p, q);
  BinaryTree *R = LCA(root->right, p, q);
  if (L && R) return root;  // if p and q are on both sides
  return L ? L : R;  // either one of p,q is on one side OR p,q is not in L&R subtrees
}

//BT with parent pointer
int getHeight(BinaryTree *p) {
  int height = 0;
  while (p) {
    height++;
    p = p->parent;
  }
  return height;
}
 
// As root->parent is NULL, we don't need to pass root in.
BinaryTree *LCA(BinaryTree *p, BinaryTree *q) {
  int h1 = getHeight(p);
  int h2 = getHeight(q);
  // swap both nodes in case p is deeper than q.
  if (h1 > h2) {
    swap(h1, h2);
    swap(p, q);
  }
  // invariant: h1 <= h2.
  int dh = h2 - h1;
  for (int h = 0; h < dh; h++)
    q = q->parent;
  while (p && q) {
    if (p == q) return p;
    p = p->parent;
    q = q->parent;
  }
  return NULL;  // p and q are not in the same tree
}
int main(int argc, char** argv) {

    return 0;
}

