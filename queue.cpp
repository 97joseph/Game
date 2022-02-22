queue.h
#ifndef queue_h
#define queue_h
struct QueueNode
{
int val;
QueueNode *next;
QueueNode *prev;
};
//a circular queue class
class Queue
{
private:
QueueNode* head;
public:
Queue();
bool isEmpyty();
void addBack(int val);
int getFront();
void removeFront();
void printQueue();
~Queue();
};
#endif /* queue_h */
======
queue.cpp
Expert Answer
#include "queue.h"
#include <iostream>
using namespace std;
Queue::Queue()
{
head = NULL;
}
bool Queue::isEmpyty()
{
return head == NULL;
}
void Queue::addBack(int val)
{
if(isEmpyty())
{
head = new QueueNode;
head->val = val;
head->next = head;
head->prev = head;
}
else
{
QueueNode* last = head->prev;
//create a new node and set it prev and next value
QueueNode* n = new QueueNode;
n->val = val;
n->prev = last;
n->next = head;
//make old last node's next to point to n
last->next = n;
//make head's previous to be new node n
head->prev = n;
}
}
int Queue::getFront()
{
return head->val;
}
void Queue::removeFront()
{
if(isEmpyty())
return;
else if(head == head->next) //single element
{
delete head;
head = NULL;
}
else
{
QueueNode* temp = head;
head = head->next;
head->prev = temp->prev;
head->prev->next = head;
delete temp;
}
}
void Queue::printQueue()
{
if(!isEmpyty())
{
QueueNode* curr = head;
while(curr->next != head)
{
cout << curr->val << " ";
curr = curr->next;
}
cout << curr->val << endl;
}
cout << endl;
}
Queue::~Queue()
{
while(!isEmpyty())
removeFront();
}
