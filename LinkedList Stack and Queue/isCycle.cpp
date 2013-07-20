/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 18, 2013, 8:49 AM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */

class ListNode {
public:
  ListNode();
  ~ListNode();
  ListNode * ListConstructor( int* key, int length);
  int value;
  ListNode * next;

};

ListNode::ListNode* ListConstructor( int* key, int length)
{
    ListNode * head,temp;
    head = NULL;
    int i = length - 1;
        
    temp.value = *(key + i);
    temp.next = head;
    head = temp;
      
    while(head.next != NULL && i >= 0)
    {
        if(i > 0)
        {
            head.next.value = *(key+i);
            head.next.next = head.next;
            head = head.next;
        }
        else if(i = 0)
        {
            head.next.value = *key;
            head.next.next = head.next;
            head = head.next;
        }
        
    }
    
    return temp;
}

bool hasLoops( ListNode * myList ) {
    
  ListNode *fast, *slow;
  fast = myList;
  slow = myList;
  while(1)
  {
      if(!fast || !fast->next)
          return false;
      else if(fast == slow || fast->next == slow)
          return true;
      else
      {
          slow = slow->next;
          fast = fast->next->next;
      }
  }

} 
int main(int argc, char** argv) {

    
    return 0;
}

