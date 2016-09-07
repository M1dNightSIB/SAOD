#include <stdlib.h>
#include <stdio.h>
#include <math.h>  
#include <iostream>
  const int N=10;
   
  typedef struct st {  
             int data; 
             st *next; 
  } stack;
             
  stack* DecStack(void) {
      stack *head, *p;
	  head = NULL;                  
	  for (int i = 0; i < N; i++) {
		  p = new stack;           
		  p->data = i;           
		  p->next = head;        
		  head = p;                
      }
      return head;
  }  
 
  stack* IncStack(void){
	  stack *head, *p;
	  head = NULL;
	  for (int i = 0; i < N; i++) {
		  p = new stack;
		  p->data = N - i;
		  p->next = head;
		  head = p;
      }
      return head;
  }    
    
  stack* RandStack(void){
	  stack *head, *p;
	  head = NULL;
	  for (int i = 0; i < N; i++) {
		  p = new stack;
		  p->data = rand() % N;
		  p->next = head;
		  head = p;
      }
	  return head;
  }   
      
  int SumStack(st *head) {
	  stack *p;
	  int summ = 0;
	  p = head;
      while (p!= NULL) {
		     
		      summ += p->data;
			p=p->next;
      }
	  return summ;
  }    
  int SeriesStack(st *head){
	  st *p;
	  int next = head->data, series = 1;
	  p = head;
	  while (head->next != NULL){
		    head = p->next;
		    p = head;
		    if (next > head->data) series++;
		    next = head->data;
      }
	  return series;
  }
  
  void PrintStack(st *head){
	   st *p;
	   p = head;
	   printf("%d ",head->data);
	   while (head->next != NULL) {
		     head = p->next;
		     p = head;	
		     printf("%d ",head->data);
       }
  }
  
  int main(int argc, char *argv[]){
      setlocale(LC_ALL, "Russian"); 
      stack *head, *tail, *p;
      
      printf("Возрастание: \n");
      head = IncStack();
      PrintStack(head);
      
      printf("\n\nУбывание: \n");
      head = DecStack();
      PrintStack(head);
      
      printf("\n\nРандом: \n");  
      head = RandStack();
      PrintStack(head);
      
      printf("\n\nСумма последнего : %d \n",SumStack(head));
      
      printf("Количество серий в последнем: %d \n",SeriesStack(head));

  system("PAUSE");
  return 0;
}


