//filename : HeapADT.c

#include <stdio.h>
#include "HeapADT.h"

void CreateMaxHeap(HeapType *Heap)
/* ����������: ���������� ��� ���� ����. 
   ����������: ��� ���� ���� 
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* �������:    ��� ���� Heap. 
   ����������: ������� �� � ����� ����� �����. 
   ����������: TRUE �� � ����� ����� �����, FALSE ����������� 
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* �������:    ��� ����. 
   ����������: ������� �� � ����� ����� �������. 
   ����������: TRUE �� � ����� ����� �������, FALSE �����������  
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMaxHeap(HeapType *Heap, HeapNode Item)
/*  �������:    ��� ���� Heap ��� ��� �������� ��������� Item . 
    ����������: ������� �� �������� Item ��� ����, �� � ����� ��� ����� �������. 
    ����������: ��� ������������� ����. 
    ������:     ������ ������� ����� �� � ����� ����� ������� 
*/
{
   int hole;

   if (!FullHeap(*Heap)) 
   {
          (*Heap).Size++;
          
          hole=(*Heap).Size;
          while (hole>1 && Item.key > Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }        
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMaxHeap(HeapType *Heap, HeapNode *Item)
/* �������:    ��� ���� Heap.  
   ����������: ������ ��� ��������� �� ���������� �������� ��� �����. 
   ����������: �� ���������� �������� Item ��� ����� ��� ��� ������������� ���� 
*/
{
   int parent, child;
   HeapNode last;
   boolean done;
 
   if (!EmptyHeap(*Heap))  
   {
        done=FALSE;
        (*Item)=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;
        
        parent=1; child=2;
        
        while (child<=(*Heap).Size && !done) 
        {
            if (child<(*Heap).Size) 
                if ((*Heap).Element[child].key < (*Heap).Element[child+1].key)  
                    child++;
            if (last.key >= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}


