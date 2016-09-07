#include <iostream>
#include <stdlib.h>


using namespace std;
 
typedef struct Node
{
	int Val;
	struct Node *next;
}Node;

Node *DigitalSort(Node *l, int t)     // t- разрядность
{
    int i, j, d, m = 1;
    Node *temp, *out, *head[10], *tail[10];
    out=l;

    for(j=1; j<=t; j++)
    {
        for(i=0; i<=9; i++)
            head[i] = (tail[i]=NULL);

        while(l != NULL)
        {
            d = (l->Val/m )%10;
            temp = tail[d];
            if ( head[d]==NULL) head[d] = l;
            else temp->next = l;
            l = l->next;
            temp->next = NULL;


        }
        for(i=0; i<=9; i++)
            if(head[i] != NULL ) break;
        l = head[i];
        temp=tail[i];
        for(d = i+1; d<=9; d++)
        {
            if (head[d] != NULL)
            {
                temp->next = head[d];
                temp = tail[d];
            }
        }
        m*=10;
    }
    return (out);

}

void push(Node **head, int n)
{
	Node *p;  // указатель на первый элемент
	for(int i=0;i<n;i++){
		
		system("clear");
		p= new Node;
		
		cout<<"Введите значения:"<<endl;
		cin>>p->Val;

		p->next= (*head);// присваиваем укз адрес предыдущего элемента
		(*head)=p; // хэду присваиваем адрес нового узла
	}
}

void printlist(const Node *head)
{	
	int i=1;
	while(head){
	
	cout<<i<<")";
	cout<<head->Val<<endl;
	
	head=head->next;
	i++;
	}
	cout<<endl;
}


main()
{	
	Node *head = NULL;
	int N;
	cout<<"Сколько элементов в списке?";
	cin>>N;
	push (&head,N);
	printlist(head);
	DigitalSort(NULL,3);
	printlist(head);
	return 0;
	
	
}
