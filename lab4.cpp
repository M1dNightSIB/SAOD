#include<cstdlib>
#include<stdio.h>
#include<ctime>
char rost;
struct vertex
{
	vertex *left;
 	vertex *right;
    int data;
    char bal;
};
         
void LL(vertex *&p)
{
	vertex *q;
	q = p->left;
	p->bal = 0;
	q->bal = 0;
	p->left = q->right;
	q->right = p;
	p = q;
}
void RR(vertex *&p)
{
	vertex *q;
	q = p->right;
	p->bal = 0;
	q->bal = 0;
	p->right = q->left;
	q->left = p;
	p = q;
} 
void LR(vertex *&p)
{
	vertex *q,*r;
	q = p->left;
	r = q->right;
     
	if(r->bal < 0)
		p->bal = 1;             
    else
		p->bal = 0;
	if(r->bal > 0)
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
void RL(vertex *&p)
{
     vertex *q,*r;
     q = p->right;
     r = q->left;
     if(r->bal > 0)
     	p->bal = -1;             
     else
     	p->bal = 0;
     
     if(r->bal < 0)
     	q->bal = 1;             
     else
     	q->bal = 0;
      
     r->bal = 0;
     p->right = r->left;
     q->left = r->right;
     r->left = p;
     r->right = q;
     p = r;  
     
     }               
       
void addavl(vertex *&p,int d)
{
     if(p == NULL)
	 {
     	p=new vertex;
     	p->data = d;
     	p->left = p->right = NULL;
     	p->bal = 0;
     	rost=1;            
     }
     else if(p->data > d)
          {
           	addavl(p->left,d);
            if(rost == 1)
            {
               if(p->bal > 0)
			   {
				   p->bal = 0; 
				   rost = 0;
			   }
               else if(p->bal == 0) p->bal = -1;
                    else if(p->left->bal < 0)
                    {
					 LL(p);
					 rost = 0;
					}
                    else 
					{
						LR(p);
						rost = 0;
					}   
            }
          }
          else 
          {
          addavl(p->right,d);
            if(rost == 1)
            {
               if(p->bal < 0)
			   {
				   p->bal = 0; 
				   rost = 0;
			   }         
               else if(p->bal == 0) 
	       p->bal = 1;
                    else if(p->right->bal > 0)
					{
						RR(p);
						rost=0;
					} 
                    else 
					{
						RL(p);
						rost=0;
					}      
                      
            } 
          }    
     
    } 
void avl(vertex *&root,int *a,int n)
{
     for(int i=0;i<n;i++)
     	addavl(root,a[i]);
}           
       
void FillRand(int *A, int n);       
void obhodlrp(vertex *p);       
void addv(vertex *&root,int d);
void sdp(vertex *&root,int *a,int n);  
void obhod(vertex *p,int &n,int &m,int &h,int &hsr);     
const int n=100;       
int re=0;          
main()
{
      srand(time(0));
      int j; 
      vertex *root=NULL,*root1=NULL,*p;
      int a[n];
      FillRand(a,n);
      avl(root,a,n);
      sdp(root1,a,n);
      obhodlrp(root);
      
      
      //3.
      int i=0,m=0,h=0,hsr=0;
      obhod(root1,i,m,h,hsr);
      printf("\n\n\n n=100   Ðàçìåð   Êîíòð.cóììà    Âûñîòà    Ñðåäí.Âûñîòà\n");
      
      printf("   ÑÄÏ   %6d   %11d   %7d    %12.2f\n",i,m,h,(float)hsr/n);
      i=0,m=0,h=0,hsr=0;
      obhod(root,i,m,h,hsr);
      printf("   ÀÂË   %6d   %11d   %7d    %12.2f",i,m,h,(float)hsr/n);
      
      
       printf("\n\n");
       system("PAUSE");
       return 0;
}



          
       
void FillRand(int *A, int n)
{    
     int i;
     for(i=0;i<n;i++)
     A[i]=rand()%100;
}       
void obhodlrp(vertex *p){
     if(p!=NULL){
     obhodlrp(p->left);
     printf("%3d ",p->data);
     obhodlrp(p->right);            
     }
     }
void addv(vertex *&root,int d){
     vertex **p;
     p=&root;
     while(*p!=NULL){
       if(d<(*p)->data) p=&((*p)->left);
       else p=&((*p)->right);
     } 
     (*p)=new vertex;
     (*p)->data=d;
     (*p)->left=NULL;
     (*p)->right=NULL;              
     }             
       
void sdp(vertex *&root,int *a,int n){
     for(int i=0;i<n;i++)
     addv(root,a[i]);
     }        
       
void obhod(vertex *p,int &n,int &m,int &h,int &hsr){ 
     if(p!=NULL){
     n++;m+=p->data;  
     hsr+=re+1;  
     re++;        
     obhod(p->left,n,m,h,hsr);
     obhod(p->right,n,m,h,hsr);
     if(re>h)h=re;    
     re--;        
     }
     }    
       
       
