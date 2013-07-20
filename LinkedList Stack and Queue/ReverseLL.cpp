/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 25, 2013, 4:02 PM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
struct Node {
    Node* next;
    int data;
};

//Iterative
void reverse(Node*& head) {
  if (!head) return;
  Node* prev = NULL;
  Node* curr = head;
  while (curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

//Recursive
void reverse(Node*& p) {
  if (!p) return;
  Node* rest = p->next;
  if (!rest) return;
  reverse(rest);
  p->next->next = p;
  p->next = NULL;
  p = rest;
}
int main(int argc, char** argv) {

    return 0;
}

