#include <stdio.h>
#include <stdlib.h>

int n,M,C;
struct Tspis {Tspis *next; int data;};
struct Queue {Tspis *head; Tspis *tail;} Q;
void fillincQ(int n) {
     Tspis *p;
     int i;
     p=new Tspis;
     p->data=1;
     p->next=NULL;
     Q.head=p;
     Q.tail=p;
     for (i=1;i<n;i++) {
         p=new Tspis;
         p->data=i+1;
         p->next=NULL;
         Q.tail->next=p;
         Q.tail=p;
     }
}
void filldecQ(int n) {
     Tspis *p;
     int i;
     p=new Tspis;
     p->data=n;
     p->next=NULL;
     Q.head=p;
     Q.tail=p;
     for (i=n-1;i>0;i--) {
         p=new Tspis;
         p->data=i;
         p->next=NULL;
         Q.tail->next=p;
         Q.tail=p;
     }
}
void fillrandQ(int n) {
     Tspis *p;
     int i;
     p=new Tspis;
     p->data=rand()%n;
     p->next=NULL;
     Q.head=p;
     Q.tail=p;
     for (i=n-1;i>0;i--) {
         p=new Tspis;
         p->data=rand()%n;
         p->next=NULL;
         Q.tail->next=p;
         Q.tail=p;
     }
}
void printQ(Tspis *t) {
     while (t!=NULL) {
           printf("%2d ",t->data);
           t=t->next;
     }
     printf("\n");
}
void freeQ(Tspis *t) {
     Tspis *p;
     while (t!=NULL) {
           p=t->next;
           delete t;
           t=p;
     }
}
int sum(Tspis *t) {
     if (t==NULL) return 0; else
        return (t->data+sum(t->next));
}
int RunNumber (Tspis *t) {
     Tspis *p;
     p=t;
     t=p->next;
     int c=0;
     while (t!=NULL) {
           if (t->data < p->data) c++;
           p=p->next;
           t=t->next;
     }
     return(c+1);
}
void Split(Tspis *S, Tspis *&a, Tspis *&b, int &n) { //разделение, n-кол-во
     Tspis *k,*p;	//элементов в списке S , k & p- рабочие
     a=S;              //указатели, a & b- рабочие списки
     b=S->next;
     n=1;
     k=a;
     p=b;
     while (p!=NULL) {
           n++;
           k->next=p->next;
           k=p;
           p=p->next;
     }
}
void MergeSort(Tspis *S) {				//тело сортировки
     Tspis *a,*b;// a & b - рабочие указаетели
     Queue c[2];
     int p,i,m,q,r; //p-предпол. размер серии, i-номер актив. серии, m-текущий размер списков а и в, q & r -фактический размер серий в а и в
     Split(S,a,b,n);
     p=1;
     C=M=0;
     while (p<n) {
           c[0].tail=(Tspis *)&c[0].head; //инииализация очередей
           c[1].tail=(Tspis *)&c[1].head;
           i=0;
           m=n;
           while (m > 0) {
                 if (m >= p) q = p; else q = m;
                 m-=q;
                 if (m >= p) r = p;  else r = m;
                 m-=r;
                 while ((q!=0)&(r!=0)) {//слияние q-серий из А с r-серией из B
                       C++;
                       if (a->data <= b->data) {// сравнения
                          c[i].tail->next=a; //помещаем элемент из А в очередь С
                          c[i].tail=a;
                          a=a->next;
                          q--;
                          M+=2;
                       }  else {
                          c[i].tail->next=b; //помещаем элемент из B в очередь С
                          c[i].tail=b;
                          b=b->next;
                          r--;
                          M+=2;
                       }
                 }
                 while (q > 0) {
                       c[i].tail->next=a; //Перемещаем элемент из списка А в оч. С
                       c[i].tail=a;
                       a=a->next;
                       q--;
                       M+=2;
                 }
                 while (r > 0) {
                       c[i].tail->next=b; //-//-//-//-
                       c[i].tail=b;
                       b=b->next;
                       r--;
                       M+2;
                 }
                 i=1-i;
           }
           a=c[0].head;
           b=c[1].head;
           p=2*p;
     }
     c[0].tail->next=NULL;
     S=c[0].head;
     Q.head=S;
}
void FillInc (int a[], int n) {
     a[0]=rand()%20-10;
     for (int i=1; i<n; i++) a[i]=a[i-1]+rand()%4;
}
void FillDec (int a[], int n) {
     a[0]=rand()%20+10;
     for (int i=1; i<n; i++) a[i]=a[i-1]-rand()%4;
}
void FillRand (int a[], int n) {
     for (int i=0; i<n; i++) a[i]=rand()%20-10;
}
void Heap (int a[], int l, int r) {
     int x=a[l],i=l,j;
     while (1) {
    	j=2*i;
    	C++;
    	if (j>r) break;
    	C+=2;
    	if ((j<r)&(a[j+1]>=a[j])) j++;
    	C++;
        if (x>=a[j]) break;
        a[i]=a[j];
        i=j;
        M++;
     }
     a[i]=x;
}
void HeapSort(int a[], int n) {
     int l=n/2;
     int k;
     M=C=0;
     while (l>=0) {
           Heap(a,l,n-1);
           l--;
     }
     int r=n;
     while (r>0) {
           k=a[0];
           a[0]=a[r-1];
           a[r-1]=k;
           M++;
           r--;
           Heap(a,0,r-1);
     }
}
void QuickSort(int a[], int l, int r) {
     int i=l,j=r,q,x;
     x=a[l];
     while (i<j) {
           while (a[i]<x) {i++; C++;}
           while (a[j]>x) {j--; C++;}
           C++;
           if (i<=j) {
              q=a[i];
              a[i]=a[j];
              a[j]=q;
              M++;
              i++;
              j--;
           }
     }
     C++;
     if (l<j) QuickSort(a,l,j);
     C++;
     if (i<r) QuickSort(a,i,r);
}
int main() {
    Tspis *p;
    int i,j;
    n=15;
    int A[1000];
    // inc
    p=new Tspis;
    p->data=0;
    p->next=NULL;
    Q.head=p;
    Q.tail=p;
    fillincQ(n);
    printQ(Q.head);
    printf("sum = %d, RunNumber = %d\n",sum(Q.head),RunNumber(Q.head));
    MergeSort(Q.head);
    printQ(Q.head);
    printf("sum = %d, RunNumber = %d\n\n",sum(Q.head),RunNumber(Q.head));
    freeQ(Q.head);
    // dec
    p=new Tspis;
    p->data=0;
    p->next=NULL;
    Q.head=p;
    Q.tail=p;
    filldecQ(n);
    printQ(Q.head);
    printf("sum = %d, RunNumber = %d\n",sum(Q.head),RunNumber(Q.head));
    MergeSort(Q.head);
    printQ(Q.head);
    printf("sum = %d, RunNumber = %d\n\n",sum(Q.head),RunNumber(Q.head));
    freeQ(Q.head);
    // rand
    p=new Tspis;
    p->data=rand()%n;
    p->next=NULL;
    Q.head=p;
    Q.tail=p;
    fillrandQ(n);
    printQ(Q.head);
    printf("sum = %d, RunNumber = %d\n",sum(Q.head),RunNumber(Q.head));
    MergeSort(Q.head);
    printQ(Q.head);
    printf("sum = %d, RunNumber = %d\n\n",sum(Q.head),RunNumber(Q.head));
    freeQ(Q.head);
    printf("  n  |            MergeSort        |\n");
    printf("     |   inc   |   dec   |   rand  |\n");
    for (n=100;n<501;n+=100) {
        printf(" %3d |",n);
        p=new Tspis;
        p->data=0;
        p->next=NULL;
        Q.head=p;
        Q.tail=p;
        fillincQ(n);
        MergeSort(Q.head);
        printf(" %7d |",M+C);
        freeQ(Q.head);
        p=new Tspis;
        p->data=n;
        p->next=NULL;
        Q.head=p;
        Q.tail=p;
        filldecQ(n);
        MergeSort(Q.head);
        printf(" %7d |",M+C);
        freeQ(Q.head);
        p=new Tspis;
        p->data=rand()%n;
        p->next=NULL;
        Q.head=p;
        Q.tail=p;
        fillrandQ(n);
        MergeSort(Q.head);
        printf(" %7d |\n",M+C);
        freeQ(Q.head);
    }
    system("pause");

      system("pause");

}
