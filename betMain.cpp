#include <iostream>
#include <string>
#include "bet.h"


using namespace std;

int precedenceCheck(char c);
void printMenu();
void preBst(string s);
void infix2PostBst(string s);
void postBst(string s);
void print(BET b);
char buildAnother();


int main()
{
	char choice;
	string expression;
	do
	{
		printMenu();
		cin>>choice;
		switch (choice)
		{
			case '1':
			{
				cout<<"Your Expression ==>"<<endl;
				cin.ignore();
				getline(cin, expression);
				preBst(expression);
				break;
			}
			case '2':
			{
				cout<<"Your Expression ==>"<<endl;
				cin.ignore();
				getline(cin, expression);
				infix2PostBst(expression);
				break;
			}
			case '3':
			{
				cout<<"Your Expression ==>"<<endl;
				cin.ignore();
				getline(cin, expression);
				postBst(expression);
				break;
			}
			default : cout<< "\tError. Try Again."<<endl;
		}
		choice=buildAnother();		
	}while(choice != 'N');
	cout<<"Program now deconstructing Tree & Exiting..."<<endl;

}

void printMenu()
{
		cout<< "&&&&&&&&&&&& BUILDING BINARY EXPRESSION TREES &&&&&&&&&&&&"<<endl;
		cout<< "\t(1) Prefix \t(2)Infix \t (3)Postfix"<<endl<<endl;
		cout<<"Your Expression Type==>"<<endl;
}


void preBst(string s) //turns a prefix into a BST
{
	BET b;
	char c;
	for(int x=s.length()-1; x>=0; x--)
	{
		c=s[x];
		if(c==' ')
		{
			//skip it
		}
		else if(c=='+')
		{
			b.insertPrefixOperator(c);
		}
		else if(c=='-')
		{
			b.insertPrefixOperator(c);
		}
		else if(c=='*')
		{
			b.insertPrefixOperator(c);
		}
		else if(c=='/')
		{
			b.insertPrefixOperator(c);
		}
		else
		{
			b.insertOperand(c);
		}
		
	}
	print(b);
			
}

void infix2PostBst(string s)
{
	stack<char> infix;
	char c;
	string newfix;
	s+=')';
	s='('+s;
	infix.push(s[0]);
	for(int x=1; x<s.length(); x++)
	{
		
		c=s[x];
		if(c==' ')
		{
			//skip it
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
		{
			char k=infix.top();
			if(c=='(')
			{
				infix.push(c);
				
			}
			else if(c==')')
			{
				while(infix.top()!='(')
				{
					newfix = newfix + infix.top();
					infix.pop();
				}
				infix.pop();
			}
			else if(precedenceCheck(c)<=precedenceCheck(k))
			{
				while(precedenceCheck(c)<=precedenceCheck(k))
				{
					
					infix.pop();
					newfix = newfix + k;
					k=infix.top();
				}
				infix.push(c);
				
			}
			else
			{
				infix.push(c);
			}
		}
		else
		{
			newfix=newfix + c;			
		}
	}
	postBst(newfix);
}

int precedenceCheck(char c)
{
	if(c=='*' || c=='/')								
	{
		return 2;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else if(c==')')
	{
		return 5;
	}
	else
	{
		return 0;
	}
	
}
void postBst(string s)
{
	BET b;
	char c;
	for(int x=0; x<s.length(); x++)
	{
		c=s[x];
		if(c==' ')
		{
			//skip it
		}
		else if(c=='+')
		{
			b.insertPostfixOperator(c);
		}
		else if(c=='-')
		{
			b.insertPostfixOperator(c);
		}
		else if(c=='*')
		{
			b.insertPostfixOperator(c);
		}
		else if(c=='/')
		{
			b.insertPostfixOperator(c);
		}
		else
		{
			b.insertOperand(c);
		}
		
	}
	print(b);
}

void print(BET b)
{
	cout<<endl;
	cout<<"Prefix Expression Produced From Tree : "<<endl;
	b.preorder();
	cout<<endl;
	cout<<"Infix Expression Produced From Tree : "<<endl;
	b.inorder();
	cout<<endl;
	cout<<"Postfix Expression Produced From Tree : "<<endl;
	b.postorder();
	cout<<endl;
}

char buildAnother()
{
	char build;
	cout<<"Would you like to build another tree? (Y/N)"<<endl;
	cin>>build;
	return toupper(build);
	
}




