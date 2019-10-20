// Filename   BstADT.c
/*                 ��������� ��� �������� �� �������
                    �� �������� ��� ������ ��� ��� ����� ����� int*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "BstADT.h"

void CreateBST(BinTreePointer *Root) 
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item) 
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item. 
   ����������:  ������� �� �������� Item ��� ���. 
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ��� 
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %c EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, 
                BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue. 
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.  
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ��� 
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������. 
                ����������� � Found ���� ���� FALSE 
*/
{
  
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue > (*LocPtr)->Data)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    } 
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, 
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue. 
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ��� 
                ��� ��� ������ ��� ������ �����. 
   ����������: � Found ���� ���� TRUE, � ������� LocPtr ������� ���� ����� ��� 
                �������� ��� ���� KeyValue ��� � Parent ������� ���� ������ 
                ����� ��� ������, �� � ��������� ����� ��������. 
                ����������� � Found ���� ���� FALSE. 
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue. 
  ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ���� 
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���, 
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer  
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n 
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ��� 
                ������ ��� n ���� �� ������� ���� ������� */
                n->Data = nNext->Data;
                n = nNext;
          } //����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 �����
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)      
                  Parent->LChild = SubTree;
               else                            
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���. 
   ����������: ������� ���������������� �������� ��� �������� ������� ��� 
                ������������� ���� ����� ������� ��� ����.  
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������ 
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%d ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}



