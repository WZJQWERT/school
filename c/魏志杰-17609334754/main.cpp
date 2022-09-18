#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;		//����˳���������Ԫ��Ϊint����
typedef struct
{  ElemType data[MaxSize];	//���˳����Ԫ��
   int length;			//˳����ʵ�ʳ���
} SqList;

//��ʼ�� 
void InitList(SqList &L) {
		//����LҪ�ش���ʵ�Σ���������������
       L.length=0;
}
//���� 
void CreateList(SqList &L,ElemType a[],int n)
{  int i,k=0;			//k�ۼ�˳���L�е�Ԫ�ظ���
   for (i=0;i<n;i++)
   {  L.data[k]=a[i];		//��L�����һ��Ԫ��
      k++;			//L��Ԫ�ظ�����1
   }
   L.length=k;			//����L�ĳ���
}
//���� 
void DestroyList(SqList L)
{    }
 
//���� 
int GetLength(SqList L)
{
 return L.length;
}

//Ԫ�� 
int GetElem(SqList L,int i,ElemType &e)
{  if (i<1 || i>L.length)	//��Ч��iֵ����0
      return 0;
   else{ 
        e=L.data[i-1];		//ȡԪ��ֵ������1
      return 1;
   }
}
//���� 
int Locate(SqList L,ElemType x)	
{  int i=0;
   while (i<L.length && L.data[i]!=x)
     i++; 	//����ֵΪx�ĵ�1��Ԫ��,���ҷ�ΧΪ0��L.length-1
   if (i>=L.length) return(0);  //δ�ҵ�����0
   else return(i+1);		   //�ҵ��󷵻����߼����
}
//���� 
int InsElem(SqList &L,ElemType x,int i)
{  int j;
   if (i<1 || i>L.length+1)	//��Ч�Ĳ���i
      return 0;
   for (j=L.length;j>i;j--)	//��λ��Ϊi�Ľ�㼰֮��Ľ�����
      L.data[j]=L.data[j-1];
   L.data[i-1]=x;		//��λ��i������x
   L.length++;			//���Ա�����1
   return 1;
}
    int DelElem(SqList &L,int i)
{  int j;
   if (i<1 || i>L.length)	//��Ч�Ĳ���i
      return 0;
   for (j=i;j<L.length;j++)	//��λ��Ϊi�Ľ��֮��Ľ��ǰ��
      L.data[j-1]=L.data[j];
   L.length--;			//���Ա��ȼ�1
   return 1;
}
//ɾ�� 
void DispList(SqList L)
{  int i;
   for (i=0;i<L.length;i++)
	printf("%d ",L.data[i]);
   printf("\n");
}
//�������ֵ����Сֵ 
void swap(ElemType &x,ElemType &y)	//����x��y
{  ElemType tmp=x;
   x=y;  y=tmp;
}

void Swapmaxmin(SqList &L)	//����L�����ֵԪ������СֵԪ��
{  int i,maxi,mini;
   maxi=mini=0;
   for (i=1;i<L.length;i++)
     if (L.data[i]>L.data[maxi])
         maxi=i;
     else if (L.data[i]<L.data[mini])
         mini=i;
   swap(L.data[maxi],L.data[mini]);
}
//Ԫ��Ǩ�� 
int Deletek(SqList &L,int i,int k){ 
	 int j;
   if (i<1 || k<1 || i+k-1>L.length)
      return 0;			//�ж�i��k�Ƿ�Ϸ�
   for (j=i+k-1;j<L.length;j++)   	//��Ԫ��ǰ��k��λ��
      L.data[j-k]=L.data[j];
   L.length-=k;			//L�ĳ��ȼ�k
   return 1;
}
//���Ա���ǰż�� 
void Move(SqList &L)
{  int i=0,j=L.length-1;
   while (i<j)
   {  while (L.data[i]%2==1) i++;	//��ǰ�����ż��
      while (L.data[j]%2==0) j--;	//�Ӻ���ǰ������
      if (i<j)
         swap(L.data[i],L.data[j]);	//��������Ԫ��
   }
}




int main(){
    SqList L;
    ElemType a[10]={10,20,30,40,50} ,e=0;
    int j ,menuno,elemValue,elemno,elemj;
do{
		printf("\n       ���˵�               \n");
		printf("\n    1.��ʼ�����Ա�          \n");
		printf("\n    2.���崴��˳���        \n");
		printf("\n    3.�������Ա�            \n");
		printf("\n    4.�����Ա��Ȳ���ʾ    \n");
		printf("\n    5.�����Ա��е�i��Ԫ�ز���ʾ   \n");
		printf("\n    6.��ֵ��������          \n");
		printf("\n    7.����Ԫ�������㷨      \n");
		printf("\n    8.ɾ��Ԫ�������㷨      \n");
		printf("\n    9.���Ԫ��ֵ����        \n");
		printf("\n    10.���ֵԪ������СֵԪ�ؽ���          \n");
		printf("\n    11.���Ա���ǰż����������          \n");
		printf("\n    0.������������          \n");
		printf("\n             \n");
		printf("\n-------------------------------\n");
		printf("\n���������ѡ��1��2��3��4��5��6��7��8��9��10��11��0��\n");
		scanf("%d",&menuno);
		switch(menuno){
			case 1:{
				InitList(L);
				printf("���Ա��ʼ���ɹ���\n");
				break;
			}
			case 2:{
				CreateList(L,a,5);
				printf("���崴��˳���ɹ���\n");
				break;
			}
			case 3:{
				DestroyList(L);
				printf("���Ա������٣�\n");
				break;
			}
			case 4:{
				printf("���Ա���Ϊ%d\n",GetLength(L));
				break;
			}
			case 5:{
				printf("������Ҫ���ҵ�Ԫ���߼���ţ�\n");
				scanf("%d",&elemno);
				GetElem(L,elemno,e);
				printf("���Ա��е�%d��Ԫ����%d\n",elemno,e);
				break;
			}
			case 6:{
				printf("������Ҫ���ҵ�Ԫ�أ�\n");
				scanf("%d",&e);
				if(Locate(L,e)){
					printf("ֵΪ%d��Ԫ�������Ա��еĵ�%d����\n",e,Locate(L,e));
				}else printf("���Ա���û��ֵΪ%d��Ԫ�ء�\n",e); 
				break;
			}

			case 7:{
				printf("������Ҫ�������Ա��Ԫ��ֵ��\n");
				scanf("%d",&elemValue);
				printf("������Ҫ�������Ա���߼���ţ�\n");
				scanf("%d",&elemno);
				if(InsElem(L,elemValue,elemno))     //�������Ա����ĵ��� 
					printf("���Ա����һ�����ݳɹ���\n");
				else printf("����Ԫ��λ�ô���\n");;        
				
				break;
			}
			case 8:{
				printf("������Ҫɾ����Ԫ����ţ�");
				scanf("%d",&elemno);
				DelElem(L,elemno);
				printf("���Ա�ɾ��һ��Ԫ�سɹ���\n");
				break;
			}
			case 9:{
				DispList(L);
				break;
				
			}
			case 10:{
				Swapmaxmin(L);
				printf("���ֵԪ������СֵԪ�ؽ����ɹ���\n");
				break;
			}
			case 11:{
				Move(L);
				printf("���Ա���ǰż���������гɹ���\n");
				break;
			}
			case 0:{
				printf("����ִ�н����ˣ�");
				exit(0);
			}
		}
	}while(menuno<=12);

}
