#include<iostream>
template <class t>
struct StackNode
{
	t value;
	Stackc* next;
};
template <class t>
class Stack
{
private:
	StackNode<T>* head;
	int NOelement;
public:
	 Stack();
	t pop();
	void push(t);
	t top();
};

