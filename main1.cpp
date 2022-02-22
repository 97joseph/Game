main.cpp
#include "queue.h"
#include <iostream>
using namespace std;
void add(Queue &q);
void add(Queue &q)
{
int val;
while(true)
{
cout << "Enter a positive value: ";
cin >> val;
if(val <= 0)
cout << "The entered value is not +ve value! " << endl;
else
break;
}
q.addBack(val);
}
int main()
{
int choice;
bool stop = false;
Queue que;
int val;
while(!stop)
{
cout << "1. Add value to back of queue" << endl;
cout << "2. Display first node (front) of queue" << endl;