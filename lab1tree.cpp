#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



typedef struct tree
{
	int data;
	tree *left, *right;
}
tree;
tree *root = NULL;

void add2tree(tree **t, int *mas, int left, int right)
{	tree *p;
	int m;
	if(left>right) 
		return;
	else
	{
		m = (left+right)/2;
		p = new tree;
		p->data = mas[m];
		add2tree(&p->left, mas, left, m-1);
		add2tree(&p->right, mas, m+1, right);
		*t = p;
	}    
}

void ShowOnward(tree *t, int l)
{
	if(t!=NULL) 
	{ 
		
		ShowOnward(t->right, l+5);
		for( int i=0;i<l;i++) 
			cout<<"  "; 
		cout<<t->data << endl;
		ShowOnward(t->left, l+5);
		  
	}
}


void Showleft(tree *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<"\t";
		Showleft(p->left);
		Showleft(p->right);
	}
	
}



void Bubblesort(int *mas, int N)
{	
	bool swapped = true;
	int tmp,i=0;
	while(swapped)
	{
		swapped = false;
		i++;		
		for(int j=0; j<N-i; j++)
			{
				if(mas[j]>mas[j+1])
					{
						tmp = mas[j];
						mas[j] = mas[j+1];
						mas[j+1] = tmp;
						swapped = true;
					}
			}
	}
}

int sizeoftree(tree *p, int *size)
{	
	if(p == NULL)
		*size = 0;
	else
		*size = sizeoftree(p->left, size)+sizeoftree(p->right, size);
		
}	

int heightoftree(tree *p, int *height)
{
	if(p == NULL)
		*height = 0;
	else
		*height = 1+ max(heightoftree(p->left,height), heightoftree(p->right,height));
}

int middleheighttree(tree *p, int l, int *middleheight)
{
	if(p == NULL)
		*middleheight = 0;
	else 
		*middleheight = l+middleheighttree(p->left,l+1, middleheight)+middleheighttree(p->right, l+1, middleheight);
	
}

int checksum(tree *p, int *sum)
{
	if(p == NULL)
		*sum = 0;
	else 
		*sum = p->data + checksum(p->left, sum)+checksum(p->right, sum);
}


	

int main()
{	
	int lenght, size=1, height=1, middleheight=1, sum=1;
	srand(time(NULL));
	int *mas;
	cout<<"Please, input size of array mas[]: ";
	cin>>lenght;
	mas = new int[lenght];
	cout<<"Randarray:"<<endl;
	for(int i=0; i<lenght; i++)
	{
		mas[i] = rand()%100;
		cout<<mas[i]<<"\t";
	}
	
	Bubblesort(mas, lenght);
	
	cout<<"\nSorted array:"<<endl;
	for(int i=0; i<lenght; i++)
	{
		cout<<mas[i]<<"\t";
	}

	cout<<"\n1.BuildTree\n";
	cout<<"2.Showleft\n";
	cout<<"3.ShowOnward\n";
	int change;

	while(1)
	{	
		cin>>change;
		switch(change)
		{	
		case 1: 
			add2tree(&root, mas, 0, lenght);// Заполнение дерева
			cout<<"Done\n";	
		break;
	
		case 2:
			cout<<endl<<"It's tree: ";
			Showleft(root);
			sizeoftree(root, &size);
			heightoftree(root, &height);
			middleheighttree(root, 1, &middleheight);
			checksum(root, &sum);
			cout<<"\n\n\nSize\t"<<"Height\t"<<"Middleheight\t"<<"Checksum"<<endl;
			cout<<size<<"\t"<<height<<"\t"<<middleheight<<"\t\t"<<sum<<endl;
		break;

		case 3:
			cout<<endl<<"It's tree: ";
			ShowOnward(root, 0);
			sizeoftree(root, &size);
			heightoftree(root, &height);
			middleheighttree(root, 1, &middleheight);
			checksum(root, &sum);
			cout<<"\n\n\nSize\t"<<"Height\t"<<"Middleheight\t"<<"Checksum"<<endl;
			cout<<size<<"\t"<<height<<"\t"<<middleheight<<"\t\t"<<sum<<endl;
		break;
		}
		
	
	
	}
	return 0;
}
