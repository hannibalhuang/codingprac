/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 23, 2013, 4:36 PM
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


void FrontBackSplit(Node *head, Node **front, Node **back) {
  if (!head) return;  // Handle empty list
  Node *front_last_node;
  Node *slow = head;
  Node *fast = head;
  while (fast) {
    front_last_node = slow;
    slow = slow->next;
    fast = (fast->next) ? fast->next->next : NULL;
  }
  front_last_node->next = NULL;  // ends the front sublist
  *front = head;
  *back = slow;
}


int main(int argc, char** argv) {

    return 0;
}

