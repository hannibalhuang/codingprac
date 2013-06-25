/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 24, 2013, 4:41 PM
 */

#include <cstdlib>
#include "stack"

using namespace std;

/*
 * Given a binary tree, find its maximum height.No recursive
 */

typedef struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
};

int maxDepthIterative(BinaryTree *root) {
  if (!root) return 0;
  stack<BinaryTree*> s;
  s.push(root);
  int maxDepth = 0;
  BinaryTree *prev = NULL;
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left)
        s.push(curr->left);
      else if (curr->right)
        s.push(curr->right);
    } else if (curr->left == prev) {
      if (curr->right)
        s.push(curr->right);
    } else {
      s.pop();
    }
    prev = curr;
    if (s.size() > maxDepth)
      maxDepth = s.size();
  }
  return maxDepth;
}

int main(int argc, char** argv) {

    return 0;
}

