/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 23, 2013, 4:10 PM
 */

#include <cstdlib>

using namespace std;

/*
 * Given a singly linked list where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 */

struct ListNode {
    ListNode* next;
    int data;
};

struct BinaryTree {
    BinaryTree* parent;
    BinaryTree* left;
    BinaryTree* right;
};

BinaryTree* sortedListToBST(ListNode *& list, int start, int end) {
  if (start > end) return NULL;
  // same as (start+end)/2, avoids overflow
  int mid = start + (end - start) / 2;
  BinaryTree *leftChild = sortedListToBST(list, start, mid-1);
  BinaryTree *parent = new BinaryTree(list->data);
  parent->left = leftChild;
  list = list->next;
  parent->right = sortedListToBST(list, mid+1, end);
  return parent;
}
 
BinaryTree* sortedListToBST(ListNode *head, int n) {
  return sortedListToBST(head, 0, n-1);
}

int main(int argc, char** argv) {

    return 0;
}

