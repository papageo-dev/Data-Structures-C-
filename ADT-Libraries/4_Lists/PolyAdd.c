//filename PolyAdd.c
//                 *�������� ����������*
//          ��������� ���� ���������� �� ����������� ����� �� ����� ������

#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"


boolean EmptyList(PolyPointer List)
/* DEXETAI:    MIA SYNDEDEMENH LISTA ME TON PRWTO KOMBO NA DEIKTODOTEITAI APO TON
               DEIKTH List.
   LEITOYRGIA: ELEGXEI AN H SYNDEDEMENH LISTA EINAI KENH.
   EPISTREFEI: True AN H SYNDEDEMENH LISTA EINAI KENH, false DIAFORETIKA 
*/
{
  return (List==NULL);
}

void Attach(CoefficientType Co,int Ex, PolyPointer *Last)
/* �������:    ���� ���������� Coef, ���� ������ Exp ��� ���� ������ Last. 
   ����������: ���������� ���� ����� ��� �������� ���� Coef ��� Exp, 
                ��� ������� �� ��� ����� ���� ����� ������� � Last ��� ����� 
                ��� Last �� ������� �' ����� ��� ��� �����. 
   ����������: ��� ������������� ������ Last 
*/
{ 
  PolyPointer TempPtr;

  TempPtr= (PolyPointer)malloc(sizeof(struct PolyNode));
  TempPtr->Coef=Co;
  TempPtr->Expo=Ex;
  TempPtr->next=NULL;
  (*Last)->next=TempPtr;
  *Last=TempPtr;
}

void LinkedPolyAdd(PolyPointer P,PolyPointer Q,PolyPointer *W)
/* �������:   ��� ���������, P ��� Q. 
  ����������: ���������� �� �������� W = P + Q. 
  ����������: �� ��������� W. 
  ��������:   �� ��������� ������������� �� ������������ ������ �� ����� ������ 
*/
{
    PolyPointer ptrP,ptrQ,ptrW,TempPtr;
    CoefficientType sum;

    ptrP=P->next;
    ptrQ=Q->next;
    *W=(PolyPointer)malloc(sizeof(struct PolyNode));

    ptrW=*W;
    while (ptrP!=NULL && ptrQ!=NULL) 
    {
      if (ptrP->Expo<ptrQ->Expo)             //��������� ��� ���� ��� �� �
      {
          Attach(ptrP->Coef, ptrP->Expo,&ptrW);
	      ptrP=ptrP->next;
	   }
      else
            if (ptrQ->Expo<ptrP->Expo)     //��������� ��� ���� ��� �� Q
            {
                Attach(ptrQ->Coef, ptrQ->Expo,&ptrW);
	            ptrQ=ptrQ->next;
	        }
	        else                           //����� �������
            {
	               sum=ptrP->Coef+ptrQ->Coef;
   	                if (sum!=0) 
	                   Attach(sum,ptrP->Expo,&ptrW);
	      
	               ptrP=ptrP->next;
	               ptrQ=ptrQ->next;
	       }
    }
    //��������� ��� ��������� ���� ��� P � ��� Q ��� W
    if (ptrP!=NULL) 
        TempPtr=ptrP;
    else
        TempPtr=ptrQ;
    while (TempPtr!=NULL) 
    {
        Attach(TempPtr->Coef, TempPtr->Expo, &ptrW);
        TempPtr=TempPtr->next;
    }
    ptrW->next=NULL;
}

void LinkedTraverse(PolyPointer List)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
   ����������: ��������� �� ����������� ����� ���
                ������������� ���� �������� ������� ��� ����.
   ������    : ��������� �� �������� ��� ������������ ������ �� �� ����� ���� 
                ����������� ��������� ������
*/
{
    PolyPointer CurrPtr;

    if (!EmptyList(List)) 
    {
        CurrPtr=List;
        while (CurrPtr!=NULL) 
        {
          printf("(%d %d)", CurrPtr->Coef, CurrPtr->Expo);
          CurrPtr=CurrPtr->next;
        }
        printf("\n");
   }
  else printf("Empty List\n");
}

