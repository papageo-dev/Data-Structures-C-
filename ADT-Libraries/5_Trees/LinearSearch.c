
#include <stdlib.h>

#define ListLimit 50    /*���� �������� ��� ������������ ������,
                            ���������� ������ ��� �� 50*/

typedef int ListElementType; /*����� ��������� ��� �� �������� ��� ������������ ������,
                                ���������� ���������� � ����� int */

typedef ListElementType ListType[ListLimit] ;

typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void LinearSearch(ListType L, int n, ListElementType Item, boolean *Found, int *Location);
void LinkedLinearSearch(ListPointer List, ListElementType Item, boolean *Found, ListPointer *LocPtr); 

main()
{
}

void LinearSearch(ListType L, int n, ListElementType Item, boolean *Found, int *Location) 

{
   boolean Loc;
  *Found = FALSE;
  (*Location) =1;
  while (!(*Found) && (*Location) <=n) 
    if (Item==L[*Location])
      (*Found) = TRUE;
    else
      (*Location)++;
}

void LinkedLinearSearch(ListPointer List, ListElementType Item, boolean *Found, ListPointer *LocPtr)
{
  *Found=FALSE;
  *LocPtr=List;
  while (!Found && (*LocPtr)!= NULL) 
    if (Item==(*LocPtr)->Data)
      (*Found)=TRUE;
    else
      (*LocPtr)=(*LocPtr)->Next;
}
