/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 24, 2013, 7:38 PM
 */

#include <cstdlib>
#include "assert.h"
using namespace std;

/*
 * 
 */

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    int data;
};

const int MAX = 256;
// a fast lookup for inorder's element -> index
// binary tree's element must be in the range of [0, MAX-1]
int mapIndex[MAX];

void mapToIndices(int inorder[], int n) {
  for (int i = 0; i < n; i++) {
    assert(0 <= inorder[i] && inorder[i] <= MAX-1);
    mapIndex[inorder[i]] = i;
  }
}
 
// precondition: mapToIndices must be called before entry
BinaryTree *buildInorderPreorder(int in[], int pre[], int n, int offset) {
  assert(n >= 0);
  if (n == 0) return NULL;
  int rootVal = pre[0];
  int i = mapIndex[rootVal]-offset;  // the divider's index
  BinaryTree *root = new BinaryTree(rootVal);
  root->left = buildInorderPreorder(in, pre+1, i, offset);
  root->right = buildInorderPreorder(in+i+1, pre+i+1, n-i-1, offset+i+1);
  return root;
}

// precondition: mapToIndices must be called before entry
BinaryTree *buildInorderPostorder(int in[], int post[], int n, int offset) {
  assert(n >= 0);
  if (n == 0) return NULL;
  int rootVal = post[n-1];
  int i = mapIndex[rootVal]-offset;  // the divider's index
  BinaryTree *root = new BinaryTree(rootVal);
  root->left = buildInorderPostorder(in, post, i, offset);
  root->right = buildInorderPostorder(in+i+1, post+i, n-i-1, offset+i+1);
  return root;
}

int main(int argc, char** argv) {

    return 0;
}

