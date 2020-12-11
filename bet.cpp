#include <iostream>
#include "bet.h"


using namespace std;


	BET::BET()		//Constructor
	{
		root=NULL;
		
	}
	BET::~BET( )            // Destructor
	{
		makeEmpty();
	}

	bool BET::isEmpty () const
	{
		if(root==NULL)
		{
			return true;
		}		
		else
		{
			return false;
		}
	}


	void BET::makeEmpty() //empty the node
	{	
		makeEmpty(root);
	}
	void BET::makeEmpty( BETPtr& t ) const
	{
		if(t!=NULL)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			t=NULL;
			delete t;
		}
	}
    	
	void BET::insertPrefixOperator(char token)
	{
		BETPtr ptr = new BinaryNode;
		ptr->info.theContent.opsymbol = token;
		ptr->info.whichType = OPERATOR;
		ptr->left = s.top();
		s.pop();
		ptr->right = s.top();
		s.pop();
		s.push(ptr);
		root = s.top();	
	}

	void BET::insertPostfixOperator(char token)
	{
		BETPtr ptr = new BinaryNode;
		ptr->info.theContent.opsymbol = token;
		ptr->info.whichType = OPERATOR;
		ptr->right = s.top();
		s.pop();
		ptr->left = s.top();
		s.pop();
		
		s.push(ptr);
		root = s.top();
	}

	void BET::insertOperand(char token)
	{
		BETPtr ptr = new BinaryNode;
		ptr->info.theContent.variable = token;
		ptr->info.whichType = OPERAND;
		ptr->left=NULL;
		ptr->right=NULL;
		s.push(ptr);
	}

	void BET::preorder() const
	{
		//Post: Function prints the preorder transversal
		if(isEmpty())
	    {
    	   cout<<"The tree is empty"<<endl;
       	}
		else
		{
			preorder(root);
		}
	}
	
	void BET::preorder( BETPtr t) const
	{
		//Post: Function prints preorder transversal for public preorder


		if ( t!= NULL)
                {
                        if(t->info.whichType==OPERAND)
                                cout<< t->info.theContent.variable << " ";
                        else
                                cout<< t->info.theContent.opsymbol << " " ;
						preorder(t->left);
                        preorder( t->right);
                }
	}

	void BET::inorder() const
	{
		// POST: Function prints inorder transversal 

		if(isEmpty())
		{
			cout<<"The tree is empty"<<endl;
		}
		else
		{
			inorder(root);
		}
	}

	void BET::inorder( BETPtr t) const
	{	
		//Post: Function prints inorder transversal for public inorder
		
		if ( t!= NULL)
		{
			if(t->left!=NULL)
				cout<<"( ";
			inorder(t->left);
			if( t->info.whichType==OPERAND)
				cout<< t->info.theContent.variable << " ";
			else
				cout<< t->info.theContent.opsymbol << " " ;
			inorder( t->right);
			if( t-> right != NULL)
				cout<< ") ";
		}
	}

	void BET::postorder() const
	{
		//Post: Function print post order transversal
		
		if(isEmpty())
                {
                        cout<<"The tree is empty"<<endl;
                }
                else
                {
                        postorder(root);
                }

	}

	void BET::postorder( BETPtr t ) const
	{
		//Post: Function prints post order transversal for public postorder
		
		if ( t!= NULL)
                {
                        
                        postorder(t->left);
                        postorder( t->right);
			if(t->info.whichType==OPERAND)
                                cout<< t->info.theContent.variable << " ";
                        else
                                cout<< t->info.theContent.opsymbol << " " ;
                        
                }


	}
  

