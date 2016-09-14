#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct AVL
{
	int data;
	char bal;
	AVL *right;
	AVL *left;
}AVL;

void LL(AVL *&p)
{
	AVL *q;
	q = p->left;
	p->bal = q->bal = 0;
	p->left = q->left;
	q->right = p;
	p = q;
}

void RR(AVL *&q)
{
	AVL *p;
	p = q->right;
	p->bal = q->bal = 0;
	p->right = q->left;
	q->left = p;
	p = q;
}

void LR(AVL *&p)
{
	AVL *q, *r;
	q = p->left;
	r = q->right;
	
	if(r->bal<0)
		p->bal = 1;
	else
		p->bal = 0;
	if(r->bal>0)
		q->bal = -1;
	else
		q->bal = 0;
	r->bal = 0;
	p->left = r->right;
	q->right = r->left;
	r->left = q;
	r->right = p;
	p = r;
}

void RL(AVL *&p)
{
	AVL *q, *r;
	q = p->right;
	r = q->left;
	if(r->bal>0)
    	p->bal=-1;             
    else
    	p->bal=0;
     
    if(r->bal<0)
     	q->bal=1;             
    else
     	q->bal=0;
     r->bal=0;
     p->right=r->left;
     q->left=r->right;
     r->left=p;
     r->right=q;
     p=r;  
}

int main()
{
	int *array, size;
	cout<<"Введите количество вершин дерева: ";
	cin>>size;
	array = new int[size];
	
	cout<<"Исходный массив: \n";
	for(int i = 0; i < size; i++)
	{
		array[i] = rand()%100;
		cout<<array[i]<<"\t";
	}
	cout<<endl;
	
	for(int i = 0; i < size; i++)
		insert(root, array[i]);
	
	cout<<"АВЛ дерево"<<endl;
	showtree(root);
	
	return 0;
}
