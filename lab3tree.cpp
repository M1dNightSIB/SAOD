#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct RST
{
	int data;
	RST *left, *right;
}
RST;

RST *root = NULL;

using namespace std;

void build(RST** t, int D) // Buildfunc of tree
{
	RST** p = t;
	while(*p)
	{
		if(D < (*p)->data)
			p = &((*p)->left);
		else if(D > (*p)->data)
			p = &((*p)->right);
		else
		{
			cout<<"Element "<<D<<" is already in the tree"<<endl;
			break;
		}
	}
	if( (*p) == NULL)
	{
		(*p) = new RST;
		(*p)->data = D;
		(*p)->left = (*p)->right = NULL;
	}
}
/*
void destroy(RST** root, int d)
{
	RST** p = root; 
	RST *q, *r, *s;
	while(*p != NULL)
	{
		if((*p)->data < d)
			p = &((*p)->right);
		else if((*p)->data > d)
			p = &((*p)->left); 
		else 
			break;
	}
	if(*p)
	{
		q = (*p);
		if(q->left = NULL)
			*p = q->right;
		else if(q->right = NULL)
			*p = q->left;
		else 	
			r = q->left;
			s = q;
		while(r->right != NULL)
		{
			s = r;
			r = r->right;
		}
		s->right = r->left;
		r->left = q->left;
		r->right = q->right;
		(*p) = r; 
	}
	if (q)	
		delete q;
	
}
*/
void ShowOnward(RST *t, int l)
{
	if(t!=NULL)
	{

		ShowOnward(t->right, l+5);
		for( int i=0;i<l;i++)
		{
			cout<<"  ";
		}
		cout<<t->data << endl;
		ShowOnward(t->left, l+5);

	}
}


void destroy(RST **root, int key)
{
	RST **p = root;
	RST *q, *s, *r;
	while(*p != NULL)
	{
		if (key<(*p)->data)
			p = &((*p)->left);
		else if (key>(*p)->data)
			p = &((*p)->right);
		else
		{
			cout<<"Found\n";
			break;
		}
	}
	if(*p != NULL)
	{
		q = *p;
		if(q->left == NULL)
			*p = q->right;
		else if(q->right == NULL)
			*p = q->left;
		else
		{
				r = q->left;
				s = q;		

			if (r->right == NULL)
			{
				r->right = q->right;
				*p = r;
			}	
			else
			{
				while(r->right != NULL)
				{	
					s = r;
					r = r->right;
				}
				s->right = r->left;
				r->left = q->left;
				r->right = q->right;
				*p = r;
			}
		}
	delete q;
	}
}

void Showleft(RST *t)
{
	if (t)
	{
		Showleft(t->left);
		cout<<t->data<<"\t";
		Showleft(t->right);
	}
}

bool checkRST(RST *p)
{
	int flag=1;
	if(p!=NULL && ((p->left)!=NULL && (p->data<=p->left->data || !(checkRST(p->left))) ||(p->right!=NULL && (p->data>=p->right->data || !checkRST(p->right)))))
	flag=0;
		return flag;
}

int search(RST *root, int x)
{
	RST *p = root;
	
	while (p)
	{
		if(p->data == x) 
		{
			cout<<"\n"<<x<<" found\n";
			cout<<"*******\n";			
			return p->data;
			
			break;
		}
		
		else p = (p->data > x) ? p->left : p->right;
	}
	
}


int main()
{
	int lenght, *mas, target, key;
	srand(time(0));
	cout<<"Please, input size of array mas[]: ";
	cin>>lenght;
	mas = new int[lenght];
	cout<<"Randarray: "<<endl;
	
	for (int i = 0; i < lenght; i++)
	{
		mas[i] = rand()%50;
		cout<<mas[i]<<"\t";
	}

	system("clear");

	cout<<"\nRST*****************"<<endl;
	for(int i = 0; i < lenght; i++)
		build(&root, mas[i]);
	ShowOnward(root, 3);
	cout<<"\n";
	cout<<"\n1. 1 Element\n2. Loop\n";
	cin>>key;
	switch(key)
	{
		case 1:  cout<<"Input target\n";
			 cin>>target;
			 destroy(&root, target);
			 break;
		case 2:  for(int i = 0; i < lenght; i++)
			 {
				cout<<"Input target\n";
			 	cin>>target;
				destroy(&root, target);
				target = 0;
				ShowOnward(root, 3);
			 }
			 break;
	}
	cout<<"Tree after clean:\n";
	ShowOnward(root, 3);
	cout<<endl;
	
	
	
}
