#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

/*struct node
{
    node *next; 
   	int data;
};
struct queue{node *head; node *tail;}Q;
*/
int C;

int h(int a, int m)
{
	return a%m;
}

void Insert1(int k, int* t, int m)
{
	int j=h(k,m);// хеш функция
	while(j<m)
	{
		if(t[j]==0)
		{
			t[j]=k;
			return;
		}
		else{
		j=(j+1)%m;
		++C;}
	}
}

int Search1(int k, int* t, int m)
{
	int j=h(k,m);
	while(t[j]!=0 && j<m)
	{
		if(t[j]==k)
			return j;
		++j;
	}
	return -1;
}

void Insert2(int k, int* t, int m)
{
	int j=h(k,m);
	int inc=1;
	while(inc<m)
	{
		if(t[j]==0)
		{
			t[j]=k;
			return;
		}
		else{
		j=(j+inc)%m;
		inc+=2;
		++C;}
	}
}

int Search2(int k, int* t, int m)
{
	int j=h(k,m);
	int inc=1;
	while(t[j]!=0 && inc<m)
	{
		if(t[j]==k)
			return j;
		else{
		j=(j+inc)%m;
		inc+=2;}
	}
	return -1;
}
//------------------------------------------------------------------------------
int main()
{
	srand(time(NULL));
	const int n=10;
	int a[n];
	
	cout<<"Massive: "<<endl;
	a[0]=rand()%10+1;
	cout<<a[0]<<" ";
	for(int i=0;i<n;++i)
	{
		a[i]=rand()%10+a[i-1]+1;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	const int m=11;
	int t1[m], t2[m];
	for(int i=0;i<m;++i) 
		t1[i]=0, t2[i]=0;
		
	printf("\n\n  Table   Number of   Number of collisions\n");
	printf("  size     symbols    Linear     Quadratic\n");
	printf("   %d        %d         ",m,n);
	
	C=0;
	for(int i=0;i<n;++i)
		Insert1(a[i],t1,m);
	printf("%d           ",C);	

	C=0;
	for(int i=0;i<n;++i)
		Insert2(a[i],t2,m);
	printf("%d\n\n",C);
	
	cout<<"\nTable1: "<<endl;
	for(int i=0;i<m;++i)
		printf("%4d",i);
	cout<<endl;
	for(int i=0;i<m;++i)
		printf("%4d",t1[i]);
	cout<<endl;
	
	cout<<"\nTable2: "<<endl;
	for(int i=0;i<m;++i)
		printf("%4d",i);
	cout<<endl;
	for(int i=0;i<m;++i)
		printf("%4d",t2[i]);
	cout<<endl;
		
	int search1;
	cout<<"\nEnter data for search in table1 >> ";
	cin>>search1;
	if(Search1(search1,t1,m)==-1) cout<<"Not found";
	else cout<<Search1(search1,t1,m);
	cout<<endl;
	int search2;
	cout<<"\nEnter data for search in table2 >> ";
	cin>>search2;
	if(Search2(search2,t1,m)==-1) cout<<"Not found";
	else cout<<Search2(search2,t2,m);
	cout<<endl;
	
    system("pause");
}
