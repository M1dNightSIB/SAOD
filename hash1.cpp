#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
struct node
{
    node *next; 
   	int data;
};
struct queue{node *head; node *tail;}Q;
//------------------------------------------------------------------------------
void add(node *&pt, int x)
{
	node *t = new node;
    t->data=x;
	t->next=NULL;
	pt=pt->next=t;
}
//------------------------------------------------------------------------------
void print(node *ph)
{
	while(ph)
	{
		cout<<ph->data<<" ";
        ph=ph->next;
	}
	cout<<endl;
}
//------------------------------------------------------------------------------
int h(int a, int m)
{
	return a%m;
}

void Build(int* a, int n, queue* q, int m)
{
	for(int i=0;i<n;++i)
		add(q[h(a[i],m)].tail, a[i]);
}

void Print(queue* q, int m)
{
	for(int i=0;i<m;++i)
	{
		printf("%2d:  ",i);
		if(q[i].tail!=(node*)&(q[i].head))
			print(q[i].head);
		else cout<<"-"<<endl;
	}
}

void Search(int k, queue* q, int m)
{
	int i=h(k,m);
	bool f=false;
	if(q[i].tail!=(node*)&(q[i].head))
	{
		while(q[i].head)
		{
			if(q[i].head->data == k) f=true;
        	q[i].head=q[i].head->next;
		}
	}
	if(f) cout<<"Found"<<endl;
	else cout<<"Not found"<<endl;		
}
//------------------------------------------------------------------------------
int main()
{
	srand(time(NULL));
	const int n=15;// кол-во элементов в массиве
	int a[n];
	cout<<"Massive: "<<endl;
	for(int i=0;i<n;++i) // заполняем массив
	{
		a[i]=rand()%50;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	const int m=11; //размер хеш таблицы
	queue q[m];
	
	for(int i=0;i<m;++i) 
		q[i].tail=(node*)&(q[i].head);
		
	Build(a,n,q,m);
	cout<<"\nTable: "<<endl;
	Print(q,m);
	cout<<"\nEnter data for search >> ";
	int k;
	cin>>k;
	Search(k,q,m);
    system("pause");
}
