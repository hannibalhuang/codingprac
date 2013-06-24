/* 
 * File:   main.cpp
 * Author: zhipengh
 *
 * Created on June 23, 2013, 4:47 PM
 */

#include <cstdlib>

using namespace std;

/*
 * Implement Stack using linked list
 */

class stack {
public:
    stack();
    ~stack();
    void push(void* data);
    void* pop();
protected:
    //Element struct needed only internally
    typedef struct elementT{
        struct elementT* next;
        void* data;
    } element;
    
    element* firstEl;
    element* head;
    element* tail;
public:
    int Delete(element* elem);
    int InsertAfter(element* elem, int data);
    void RemoveHead(element** head);
    element* FindMToLastElement(element* head, int m);
};

stack::stack() {
    firstEl = NULL;
    return;
}

stack::~stack() {
    element* next;
    while(firstEl) {
        next = firstEl->next;
        delete firstEl;
        firstEl = next;
    }
    return;
}

void stack::push(void* data) {
    //Allocation error will throw exceptions
    elementT* element = new element;
    element->data = data;
    element->next = firstEl;
    firstEl = element;
    return;
}

void* stack::pop() {
    element* popElement = firstEl;
    void* data;
    
    //Assume StackError Class is defined elsewhere
    /*if(firstEl == NULL)
        throw StackError(E_EMPTY);*/
    
    data = firstEl->data;
    firstEl = firstEl->next;
    delete popElement;
    return data;
}

int stack::Delete(element* elem)
{
    elementT* curPos = head;
    
    if(!elem)
        return 0;
    
    if(elem == head)
    {
        head = elem->next;
        delete elem;
        //special case for one element list
        if(!head)
            tail = NULL;
        
        return 1;
    }
    
    while(curPos) {
        if(curPos->next == elem) {
            curPos->next = elem->next;
            delete elem;
            if(curPos->next == NULL)
                tail = curPos;
            return 1;
        }
        curPos = curPos->next;
    }
    
    return 0;
}

int stack::InsertAfter(element* elem, int data)
{
    element* curPos = head;
    element* newElem = new element;
    
    if(!newElem)
        return 0;
    newElem->data = data;
    
    //Insert at the beginning of the list
    if(!elem)
    {
        newElem->next = head;
        head = newElem;
        
        //Special case for empty list
        if(!tail)
            tail = newElem;
        return 1;
    }
    
    while(curPos) {
        if(curPos == elem) {
            newElem->next = curPos->next;
            curPos->next = newElem;
            
            //Special case for inserting at the end
            if(!newElem->next)
                tail = newElem;
            return 1;
        }
        curPos = curPos->next;
    }
    //Insert position not found
    delete newElem;
    return 0;
}

void stack::RemoveHead(element** head)
{
    element* temp;
    if(!(*head)) {
        temp = (*head)->next;
        delete *head;
        *head = temp;
    }
}

stack::element* stack::FindMToLastElement(element* head, int m)
{
    element* current, *mBehind;
    int i;
    
    //Advance current m elements from beginning
    //checking for the end of the list
    current = head;
    for(i = 0; i < m; i++) {
        if(current->next) {
            current = current->next;
        } else {
            return NULL;
        }
    }
    
    //Start mBehind at beginning and advance pointers
    //together until current hits last element
    mBehind = head;
    while(current->next) {
        current = current->next;
        mBehind = mBehind->next;
    }
    
    return mBehind;
    
}

int main(int argc, char** argv) {

    return 0;
}

