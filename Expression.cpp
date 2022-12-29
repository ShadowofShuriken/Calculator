#include <string>

using namespace std;

int pre(char ch)
{
	if (ch == '*' || ch == '/')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}
struct StackC
{
	char ope;
	StackC* nextC;
};
StackC* headC = NULL;
int NOElement = 0;

void pushc(char data)
{
	StackC* node = new StackC();
	node->ope = data;
	node->nextC = headC;
	headC = node;
	NOElement++;
}
char popC()
{
	char temp = 0;
	if (NOElement != 0)
	{
		temp = headC->ope;
		headC = headC->nextC;
		NOElement--;
	}
	return temp;
}
char top()
{
	if (NOElement!=0)
	{
		char temp = headC->ope;
		return temp;
	}
}
	


struct Stack
{
	int value;
	Stack* next;
};
Stack* head = NULL;
int numberOfElements = 0;

void push(int data)
{
	Stack* node = new Stack();
	node->value = data;
	node->next = head;
	head = node;
	numberOfElements++;
}
int pop()
{
	int temp=0;
	if (numberOfElements!=0)
	{
		temp = head->value;
		head = head->next;
		numberOfElements--;
	}
	return temp;
}


string Infix2Postfix(string &s) {
	string result;
	for (int i = 0; i <s.length(); i++)
	{
		if (isdigit(s[i])||s[i]==' ')
		{
			result += s[i];
		}
		else if (s[i]=='(')
		{
			pushc(s[i]);
		}
		else if (s[i]==')')
		{
			while (NOElement!=0)
			{
				if (top() == '(')
				{
					char c = popC();
					break;
				}
				char c = popC();
				result += ' ';
				result += c;
			}
			
		}
		else
		{
			result += ' ';
			while (NOElement!=0&&pre(s[i])<=pre(top()))
			{
				char c = popC();
				result += ' ';
				result += c;
			}
			pushc(s[i]);
		}
	}
	while (NOElement!=0)
	{
		char c = popC();
		result += ' ';
		result += c;
	}


	return result;
} // end-Infix2Postfix


int EvaluatePostfixExpression(string& s) {
	int temp1 = 0, temp2 = 0;
	
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			continue;
		}
		else if (isdigit(s[i]))
		{
			int value = 0;
			while (i<s.length() && isdigit(s[i]))
			{
				value = (value * 10) + (s[i] - '0');
				i++;
			}
			push(value);
		}
		else
		{
			temp2 = pop();
			temp1 = pop();
			switch (s[i])
			{
			case '+': 
			{
				push(temp1 + temp2);
				break;
			}
			case '-':
			{
				push(temp1 - temp2);
				break;
			}
			case '*':
			{
				push(temp1 * temp2);
				break;
			}
			case '/':
			{
				push(temp1 / temp2);
				break;
			}
			default:
				break;
			}
		}
	}
	temp1 = pop();
	return temp1;
} // end-EvaluatePostfixExpression
