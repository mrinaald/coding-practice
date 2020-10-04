#include<iostream>
#include<string>

using namespace std;

void transform(string expr);
void Push(char op);
void Pop();

struct stack
{
	char ch;
	stack *next;
}*head;

int main()
{
	head = NULL;
	string expr;
	int t;
	cin>>t;
	for(int i=0; i<t; ++i)
	{
		cin>>expr;
		transform(expr);
		cout<<endl;
	}
	return 0;
}

void transform(string expr)
{
	for(int i=0; (expr[i])!='\0'; ++i)
	{
		switch(expr[i])
		{
			case '+'	:
			case '-'	:
			case '*'	:
			case '/'	:
			case '^'	:	Push(expr[i]);
							break;
			case ')'	:	Pop();
							break;
			default		:	if(expr[i]!='(')
								cout<<expr[i];
		}
	}
}

void Push(char op)
{
	stack *n;
	n = new stack;
	n->ch = op;
	n->next = NULL;

	if(head == NULL)
	{
		head = n;
		return;
	}
	else
	{
		n->next = head;
		head = n;
		return;
	}
}

void Pop()
{
	if(head == NULL)
		return;
	else
	{
		stack *n;
		n = head;
		cout<<(head->ch);
		head = head->next;
		delete n;
		return;
	}
}