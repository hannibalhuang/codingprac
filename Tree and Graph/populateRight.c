/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 24, 2013, 4:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Given a binary tree, Populate the nextRight pointers in each node.
 * You may assume that it is a full binary tree 
 * (ie, each node other than the leaves has two children.)
 */

struct NodeT{ 
  NodeT* leftChild;
  NodeT* rightChild;
  NodeT* nextRight;
} Node;

void connect(NodeT* p) {
  if (!p) return;
  if (p->leftChild)
  p->leftChild->nextRight = p->rightChild;
  if (p->rightChild)
    p->rightChild->nextRight = (p->nextRight) ?
                               p->nextRight->leftChild :
                               NULL;
  connect(p->leftChild);
  connect(p->rightChild);
}


int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

