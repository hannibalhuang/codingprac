/* 
 * File:   main.c
 * Author: zhipengh
 *
 * Created on June 24, 2013, 12:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Flatten a multi-level doubly linked list to a single level one
 * and vice versa
 */

typedef struct nodeT {
    struct nodeT* next;
    struct nodeT* prev;
    struct nodeT* child;
    int value;
} node;

void Append(node* child, node** tail)
{
    node* curNode;
    
    /*Append the child child list to the end*/
    (*tail)->next = child;
    child->prev = *tail;
    
    /*Find the new tail, which is the end of the child child list*/
    for(curNode = child; curNode->next; curNode = curNode->next)
        ;/*Body intentionally empty*/
    
    /*Update the tail pointer now that curNode is the new tail*/
    *tail = curNode;
}

void FlattenList(node* head, node** tail)
{
    node* curNode = head;
    while(curNode) {
        if(curNode->child) {
            Append(curNode->child,tail);
        }
        curNode = curNode->next;
    }
}

void ExploreAndSeperate(node* childListStart)
{
    node* curNode = childListStart;
    
    while(curNode) {
        if(curNode->child) {
            /*Terminates the child list before the child*/
            curNode->child->prev->next = NULL;
            /*Starts the child list beginning with the child*/
            curNode->child->prev = NULL;
            ExploreAndSeperate(curNode->child);
        }
        curNode = curNode->next;
    }
}

void Unflatten(node* start, node** tail)
{
    node* curNode;
    ExploreAndSeperate(start);
    
    /*Update the tail pointer*/
    for(curNode = start; curNode->next; curNode = curNode->next)
        ;/*Body intentionally empty*/
    *tail = curNode;
}



int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

