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

void destroy(RST** root, int d)
{
	RST** p = root; 
	RST *q, *r, *s;
	while (*p)
	{
		if((*p)->data < d)
			p = &((*p)->right);
		else if((*p)->data > d)
			p = &((*p)->left); 
		else 
			break;
	}
	if(*p)
		q = (*p);
		if (q->left = NULL)
			*p = q->right;
		else if(q->right = NULL)
			*p = q->left;
		else 
			r = q->left;
			s = q;
		
	
	
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
	int lenght, *mas;
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

	cout<<"\nRST"<<endl;
	for(int i = 0; i < lenght; i++)
		build(&root, mas[i]);
	Showleft(root);
	
}
