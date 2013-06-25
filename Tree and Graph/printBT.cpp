/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 24, 2013, 5:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "limits.h"
#include "queue"
#include "stack"

using namespace std;

/*
 * Given a binary tree, print out the tree in level order 
 * (ie, from left to right, level by level)
 * Output a newline after the end of each level.
 * Also do it with DFS, r/w a bt from file, serial/deserial it,
 * Print all edge nodes of a complete binary tree anti-clockwise.
 */

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    int data;
};

int maxHeight(BinaryTree *p) {
  if (!p) return 0;
  int left_height = maxHeight(p->left);
  int right_height = maxHeight(p->right);
  return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

void printLevelOrder(BinaryTree *root) {
  if (!root) return;
  queue<BinaryTree*> nodesQueue;
  int nodesInCurrentLevel = 1;
  int nodesInNextLevel = 0;
  nodesQueue.push(root);
  while (!nodesQueue.empty()) {
    BinaryTree *currNode = nodesQueue.front();
    nodesQueue.pop();
    nodesInCurrentLevel--;
    if (currNode) {
      cout << currNode->data << " ";
      nodesQueue.push(currNode->left);
      nodesQueue.push(currNode->right);
      nodesInNextLevel += 2;
    }
    if (nodesInCurrentLevel == 0) {
      cout << endl;
      nodesInCurrentLevel = nodesInNextLevel;
      nodesInNextLevel = 0;
    }
  }
}

void printLevelDFS(BinaryTree *p, int level) {
  if (!p) return;
  if (level == 1) {
    cout << p->data << " ";
  } else {
    printLevelDFS(p->left, level-1);
    printLevelDFS(p->right, level-1);
  }
}

void printLevelOrderDFS(BinaryTree *root) {
  int height = maxHeight(root);
  for (int level = 1; level <= height; level++) {
    printLevelDFS(root, level);
    cout << endl;
  }
}

void printLevelOrderZigZag(BinaryTree *root) {
  stack<BinaryTree*> currentLevel, nextLevel;
  bool leftToRight = true;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    BinaryTree *currNode = currentLevel.top();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->data << " ";
      if (leftToRight) {
        nextLevel.push(currNode->left);
        nextLevel.push(currNode->right);
      } else {
        nextLevel.push(currNode->right);
        nextLevel.push(currNode->left);
      }
    }
    if (currentLevel.empty()) {
      cout << endl;
      leftToRight = !leftToRight;
      swap(currentLevel, nextLevel);
    }
  }
}

void readBSTHelper(int min, int max, int &insertVal,
                   BinaryTree *&p, ifstream &fin) {
  if (insertVal > min && insertVal < max) {
    int val = insertVal;
    p = new BinaryTree(val);
    if (fin >> insertVal) {
      readBSTHelper(min, val, insertVal, p->left, fin);
      readBSTHelper(val, max, insertVal, p->right, fin);
    }
  }
}
 
void readBST(BinaryTree *&root, ifstream &fin) {
  int val;
  fin >> val;
  readBSTHelper(INT_MIN, INT_MAX, val, root, fin);
}

void writeBinaryTree(BinaryTree *p, ostream &out) {
  if (!p) {
    out << "# ";
  } else {
    out << p->data << " ";
    writeBinaryTree(p->left, out);
    writeBinaryTree(p->right, out);
  }
}

void readBinaryTree(BinaryTree *&p, ifstream &fin) {
  int token;
  bool isNumber;
  if (!readNextToken(token, fin, isNumber)) 
    return;
  if (isNumber) {
    p = new BinaryTree(token);
    readBinaryTree(p->left, fin);
    readBinaryTree(p->right, fin);
  }
}

void printLeftEdges(BinaryTree *p, bool print) {
  if (!p) return;
  if (print || (!p->left && !p->right))
    cout << p->data << " ";
  printLeftEdges(p->left, print);
  printLeftEdges(p->right, false);
}
 
void printRightEdges(BinaryTree *p, bool print) {
  if (!p) return;
  printRightEdges(p->left, false);
  printRightEdges(p->right, print);
  if (print || (!p->left && !p->right))
    cout << p->data << " ";
}
 
void printOuterEdges(BinaryTree *root) {
  if (!root) return;
  cout << root->data << " ";
  printLeftEdges(root->left, true);
  printRightEdges(root->right, true);
}

int main(int argc, char** argv) {

    return 0;
}

