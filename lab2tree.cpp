#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int length, *mas, *mas2;

typedef struct PBST //идсп
{
	int data;
	PBST *left, *right;
}
PBST;
PBST *proot=NULL;


typedef struct RST //сдп
{
	int data;
	RST *left, *right;
} 
RST;
RST *root=NULL;
RST *root1=NULL;

/******************************************************************************************************************************************************************/
void add2PBST(PBST **t, int *mas, int left, int right) //добавление в идсп
{	
	PBST *p;
	int m;
	if(left>right)
		return;
	else
	{
		m = (left+right)/2;
		p = new PBST;
		p->data = mas[m];
		add2PBST(&p->left, mas, left, m-1);
		add2PBST(&p->right, mas, m+1, right);
		*t = p;
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

void ShowleftPBST(PBST *p)
{
	if(p!=NULL)
	{	ShowleftPBST(p->left);
		cout<<p->data<<"\t";
		
		ShowleftPBST(p->right);
	}

}


int sizeofPBST(PBST *p)
{	
	int size;
	if(p == NULL)
			size = 0;
	else
		 size = 1+sizeofPBST(p->left)+sizeofPBST(p->right);
	return size;
}

int checksumPBST(PBST *p)
{	
	int sum;
	if(p == NULL)
		sum = 0;
	else
		sum = p->data + checksumPBST(p->left)+checksumPBST(p->right);
	return sum;
}

double middleheightofPBST(PBST *p, int l)
{	
	double middleheight;
	if(p == NULL)
		middleheight = 0;
	else
		middleheight = l+middleheightofPBST(p->left,l+1)+middleheightofPBST(p->right, l+1);
	return middleheight;
}

int heightofPBST(PBST *p)
{	
	int height;
	if(p == NULL)
		height = 0;
	else
		height = 1+ max(heightofPBST(p->left), heightofPBST(p->right));
	return height;
}

/******************************************************************************************************************************************************************/


void add2RST(RST** t, int D)
{
	RST** p = t;
	while( (*p)!= NULL)
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
 
void RECadd2RST(RST *&t, int D)
{	
	if( t == NULL)
	{
		t = new RST;
		t-> data = D;
		t->left = t->right = NULL;
	}
	else if (t->data < D)
		RECadd2RST(t->right, D);
	else if ( t->data > D)
		RECadd2RST(t->left, D);
}


void menuRST()
{
	int change;
	cout<<"\n\nSelect the method of construction"<<endl;
	cout<<"1.Recursion"<<endl;
	cout<<"2.The method of double indirection"<<endl;
	cin>>change;
	system ("clear");	
	//switch(change)
	//{
		//case 2:
			for(int i = 0; i < length; i++)
				add2RST(&root1, mas2[i]);
		//break;
		
		//case 1:
			for(int i = 0; i < length; i++)
				RECadd2RST(root, mas2[i]);
		//break;
	//}
}


void ShowleftRST(RST *t)
{
	if(t)
	{
		ShowleftRST(t->left);
		cout<<t->data<<"\t";
		ShowleftRST(t->right);
	}
}

int sizeofRST(RST *p)
{	
	int size;
	if(p == NULL)
			size = 0;
	else
		 size = 1+sizeofRST(p->left)+sizeofRST(p->right);
	return size;
}

int heightofRST(RST *p)
{	
	int height;
	if(p == NULL)
		height = 0;
	else
		height = 1+ max(heightofRST(p->left), heightofRST(p->right));
	return height;
}

double middleheightRST(RST *p, int l)
{	
	double middleheight;
	if(p == NULL)
		middleheight = 0;
	else
		middleheight = l+middleheightRST(p->left,l+1)+middleheightRST(p->right, l+1);
	return middleheight;
}

int checksumRST(RST *p)
{	
	int sum;
	if(p == NULL)
		sum = 0;
	else
		sum = p->data + checksumRST(p->left)+checksumRST(p->right);
	return sum;
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


/******************************************************************************************************************************************************************/

int main()
{
	srand(time(0));
	cout<<"Please, input size of array mas[]: ";
	cin>>length;
	mas = new int[length];
	mas2 = new int[length];
	cout<<"Randarray:"<<endl;
	for (int i = 0; i < length; i++)
	{
		mas[i] = rand()%2000;
		cout<<mas[i]<<"\t";
		mas2[i] = mas[i];
	}
	
	
	system("clear");
	
			
			menuRST();
			cout<<"RST"<<endl;
			ShowleftRST(root);
			cout<<"\n********************************************************************************************\nRST2:\n";			
			ShowleftRST(root1);
	
			Bubblesort(mas,length);
			add2PBST(&proot, mas, 0, length-1);
			cout<<"\nPBST"<<endl;
			ShowleftPBST(proot);
	


	cout<<"\n\nn="<<length<<"\tSize\t"<<"Checksum\t"<<"Height\t"<<"Middleheight"<<endl;
	
	cout<<"PBST\t"<<sizeofPBST(proot)<<"\t"<<checksumPBST(proot)<<"\t\t"<<heightofPBST(proot)<<"\t"<<middleheightofPBST(proot, 1)/sizeofPBST(proot);
	
	cout<<"\nRST"<<"\t"<<sizeofRST(root)<<"\t"<<checksumRST(root)<<"\t\t"<<heightofRST(root)<<"\t"<<middleheightRST(root, 1)/sizeofRST(root);

	cout<<"\nRST2"<<"\t"<<sizeofRST(root1)<<"\t"<<checksumRST(root1)<<"\t\t"<<heightofRST(root1)<<"\t"<<middleheightRST(root1, 1)/sizeofRST(root1);
	cout<<endl;
	cout<<endl;

	int Search;

	cout<<"Search tree flag: "<<checkRST(root)<<endl;

	cout<<"What do we look for?"<<endl;
	cin>>Search;
	cout<<search(root, Search)<<"\n";
}





