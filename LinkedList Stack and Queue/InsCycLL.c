/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 21, 2013, 7:29 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Given a node from a cyclic linked list which has been sorted, write a 
 * function to insert a value into the list such that it remains a cyclic sorted 
 * list. The given node can be any single node in the list.
 */
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void insert(Node *& aNode, int x) {
  if (!aNode) {
    aNode = malloc Node(x);
    aNode->next = aNode;
    return;
  }
 
  Node *p = aNode;
  Node *prev = NULL;
  do {
    prev = p;
    p = p->next;
    if (x <= p->data && x >= prev->data) break;   // For case 1)
    if ((prev->data > p->data) && (x < p->data || x > prev->data)) break; // For case 2)
  } while (p != aNode);   // when back to starting point, then stop. For case 3)
 
  Node *newNode = malloc Node(x);
  newNode->next = p;
  prev->next = newNode;
}


int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

