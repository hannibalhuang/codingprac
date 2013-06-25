/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 24, 2013, 5:05 PM
 */

#include <cstdlib>
#include "limits.h"
using namespace std;

/*
 * Write a function isBST(BinaryTree *node) to verify
 * if a given binary tree is a Binary Search Tree (BST) or not.
 */

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    int data;
};

bool isBSTInOrderHelper(BinaryTree *p, int& prev) {
  if (!p) return true;
  if (isBSTInOrderHelper(p->left, prev)) {
    if (p->data > prev) {
      prev = p->data;
      return isBSTInOrderHelper(p->right, prev);
    } else {
      return false;
    }
  }
  else {
    return false;
  }
}

bool isBSTInOrder(BinaryTree *root) {
  int prev = INT_MIN;
  return isBSTInOrderHelper(root, prev);
}

// Find the largest BST subtree in a binary tree.
// If the subtree is a BST, return total number of nodes.
// If the subtree is not a BST, -1 is returned.
int findLargestBSTSubtree(BinaryTree *p, int &min, int &max, 
                   int &maxNodes, BinaryTree *& largestBST) {
  if (!p) return 0;
  bool isBST = true;
  int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes, largestBST);
  int currMin = (leftNodes == 0) ? p->data : min;
  if (leftNodes == -1 || 
     (leftNodes != 0 && p->data <= max))
    isBST = false;
  int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes, largestBST);
  int currMax = (rightNodes == 0) ? p->data : max;
  if (rightNodes == -1 || 
     (rightNodes != 0 && p->data >= min))
    isBST = false;
  if (isBST) {
    min = currMin;
    max = currMax;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = p;
    }
    return totalNodes;
  } else {
    return -1;   // This subtree is not a BST
  }
}
 
BinaryTree* findLargestBSTSubtree(BinaryTree *root) {
  BinaryTree *largestBST = NULL;
  int min, max;
  int maxNodes = INT_MIN;
  findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
  return largestBST;
}

// Find the largest BST in a binary tree.
// This code does not delete dynamically-allocated nodes,
// so memory will be leaked upon exit.
// The min and max values are passed top-down to check if
// including a node satisfies the current BST constraint.
// The child nodes are passed bottom-up to be assigned 
// to its parent.
// Returns the total number of nodes the child holds.
int findLargestBST(BinaryTree *p, int min, int max, int &maxNodes, 
                   BinaryTree *& largestBST, BinaryTree *& child) {
  if (!p) return 0;
  if (min < p->data && p->data < max) {
    int leftNodes = findLargestBST(p->left, min, p->data, maxNodes, largestBST, child);
    BinaryTree *leftChild = (leftNodes == 0) ? NULL : child;
    int rightNodes = findLargestBST(p->right, p->data, max, maxNodes, largestBST, child);
    BinaryTree *rightChild = (rightNodes == 0) ? NULL : child;
    // create a copy of the current node and 
    // assign its left and right child.
    BinaryTree *parent = new BinaryTree(p->data);
    parent->left = leftChild;
    parent->right = rightChild;
    // pass the parent as the child to the above tree.
    child = parent;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = parent;
    }
    return totalNodes;
  } else {
    // include this node breaks the BST constraint,
    // so treat this node as an entirely new tree and 
    // check if a larger BST exist in this tree
    findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);
    // must return 0 to exclude this node
    return 0;
  }
}
 
BinaryTree* findLargestBST(BinaryTree *root) {
  BinaryTree *largestBST = NULL;
  BinaryTree *child;
  int maxNodes = INT_MIN;
  findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largestBST, child);
  return largestBST;
}


int main(int argc, char** argv) {

    return 0;
}

