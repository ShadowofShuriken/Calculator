#include "Stack.h"
template <class t>
Stack< t>::Stack() 
{
	head = NULL;
	NOelement = 0;
}
template <class t>
  t Stack<t>:: pop()
{
	  int temp = 0;
	  if (this->NOelement != 0)
	  {
		  temp = head->value;
		  this->head = this->head->next;
		  this->NOelement--;
	  }
	  return temp;
}
  template <class t>
  void push(t) 
  {
	  StackNode<t>* node = new StackNode<t>();
	  node->value = data;
	  node->next = this->head;
	  this->head = node;
	  numberOfElements++;
  }