#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop 

function : init,insert ,print-
 ,length,is not empty
*/

typedef char ElemType;
typedef struct LNode {  
	ElemType data;	
   	struct LNode *next;			
} LinkList;
 //��ʼ�� 
void InitList(LinkList *&L) {
		//������صĿռ� 
       L=(LinkList *)malloc(sizeof(LinkList));
       //ͷ����ַ�� null 
       L->next=NULL;
}
//���� 
bool ListInsert(LinkList *&L,int i ,ElemType e){
	//	
  int j=0;
  LinkList *p =L,*s;
  
  //ѭ�� 
    while (j<i-1&&p!=NULL) {
  	j++;
  	//ָ����� 
	  p=p->next ;
  }
  	
	if(p==NULL)	
	return false;
	
else {
	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=e;
	// !
	s->next=p->next;
	p->next=s;
	return true;
}			
} 


//��� 
void DispList(LinkList *L){
	//�׽ڵ��ָ�� 
LinkList *p	=L->next;
while(p!=NULL){
	printf("%c",p->data);
	p=p->next; 
}
printf("\n");
}


//
int ListLength(LinkList *L)
{  int i=0;
//LinkList *p =l->next;
//while(p !=null); 
   LinkList *p=L;
   while (p->next!=NULL)
   {  i++;
      p=p->next;
   }
   return i;
} 


bool ListEmpty (LinkList *L){
	return (L->next==NULL);
}
bool ListDelete (LinkList *&L,int i ,ElemType e){
int j=0;
  LinkList *p =L,*q;
  
  //ѭ�� 
    while (j<i-1&&p!=NULL) {
  	j++;
  	//ָ����� 
	  p=p->next ;
  }
  	
	if(p==NULL)	{
	
	return false;
	}else {
	q=p->next;
	if(q==NULL){
	
	return false;
	e=q->data;
	p->next=q->next;
	free(q);
	return true;
	
	}
}
}

int main(){
 LinkList *h;
 ElemType e;
 printf("������Ļ����������£�\n");
 printf(" (1)��ʼ��������h\n");
 InitList(h);
 printf(" (2)���β���β�巨����a,b,c,d,eԪ��\n");
 ListInsert(h,1,'a');
 ListInsert(h,2,'b');
 ListInsert(h,3,'c');
 ListInsert(h,4,'d');
 ListInsert(h,5,'e');
 printf(" (3)���������h\n"); 
 DispList(h);
 printf(" (3)ɾ���������е�3��Ԫ��\n"); 
 ListDelete(h,3,e);
 printf(" (5)�ٴ����������h\n"); 
 DispList(h);
 printf("\nc%",e);
}







