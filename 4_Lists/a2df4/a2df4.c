#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType; /*TYPOS TWN STOIXEIWN THS SYNDEDEMENHS LISTAS*/

typedef struct ListNode *ListPointer; /*TYPOS TWN DEIKTWN TWN KOMBWN*/

typedef struct ListNode {
    ListElementType Data;
    ListPointer Next;
} ListNode;

/*TYPOS Boolean METABLHTWN*/
typedef enum {
    FALSE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);

void DeleteAll(ListPointer *List, ListPointer PredPtr);


/*KYRIWS PROGRAMMA*/
int main(){

    /*DHLWSH METABLHTWN*/
    ListElementType i, n, item;
    ListPointer AList, PredPtr;

    /*ARXIKOPOIHSH PredPtr*/
    PredPtr=NULL;

    /*DHMIOURGIA LISTAS*/
    CreateList(&AList);

    /*EISAGWGH TOU MEGETHOUS THS LISTAS.*/
    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &n);

    /*EISAGWGH STOIXEIWN STHN LISTA*/
    for (i=0; i<n; i++){
        printf("DWSE ARI8MO GIA EISAGWSH STHN ARXH THS LISTAS: ");
        scanf("%d", &item);
        LinkedInsert(&AList, item, PredPtr);
    }

    /*EMFANISH TWN STOIXEIWN THS LISTAS*/
    printf("\nARXIKH LISTA: \n");
    LinkedTraverse(AList);

    /*DIAGRAFH OLWN TWN STOIXEIWN THS LISTAS*/
    DeleteAll(&AList, PredPtr);

    /*EMFANISH TWN STOIXEIWN THS LISTAS(EMPTY LIST)*/
    printf("\n\nTELIKH LISTA, META THN KLHSH THS 'DeleteAll()': \n");
    LinkedTraverse(AList);

return 0;
}


/*SYNARTHSH: DHMIOURGIA MIAS KENHS SYNDEDEMENHS LISTAS.*/
void CreateList(ListPointer *List)
{
	*List = NULL;
}

/*SYNARTHSH: ELEGXOS AN H LISTA EINAI KENH.*/
boolean EmptyList(ListPointer List)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� �� � ����������� ����� ����� ����.
  ����������: True �� � ����� ����� ���� ��� false �����������
*/
{
	return (List==NULL);
}

/*SYNARTHSH: EISAGWGH ENOS NEOU KOMBOU/STOIXEIOU STHN LISTA.*/
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����,
                ��� �������� ��������� Item ��� ���� ������ PredPtr.
   ����������: ������� ���� �����, ��� �������� �� Item, ���� ����������� �����
                ���� ��� ��� ����� ��� �������������� ��� ��� PredPtr
                � ���� ����  ��� ������������ ������,
                �� � PredPtr ����� ���������(NULL).
  ����������:  ��� ������������� ����������� ����� �� ��� ����� ����� ���
                �� �������������� ��� ��� List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

/*SYNARTHSH: DIAGRAFH ENOS KOMBOU/STOIXEIOU APO THN LISTA.*/
void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� ����� ���
                 ��� ���� ������ PredPtr.
   ����������: ��������� ��� �� ����������� ����� ��� ����� ��� ����
                ��� ����������� ��� ����� ���� ����� ������� � PredPtr
                � ��������� ��� ����� �����, �� � PredPtr ����� ���������,
                ����� ��� �� � ����� ����� ����.
   ����������: ��� ������������� ����������� ����� �� ��� ����� �����
                �� �������������� ��� ��� List.
   ������:     ��� ������ ����� ������ �� � ����������� ����� ���� ���� .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

/*SYNARTHSH: EMFANISH OLWN TWN STOIXEIWN THS LISTAS.*/
void LinkedTraverse(ListPointer List)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
   ����������: ��������� �� ����������� ����� ���
                ������������� ���� �������� ������� ��� ����.
   ����������: ��������� ��� �� ����� ��� ������������.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
    {
        CurrPtr = List;

         while (CurrPtr!=NULL){
                printf("%d ",(*CurrPtr).Data);
                CurrPtr = CurrPtr->Next;
        }
   }
}

/*SYNARTHSH: ANAZHTHSH KOMBOU/STOXEIOU SE MIA MH TAKSINOMHMENH SYNDEDEMENH LISTA.*/
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� ��� �������� ��������� ���� �� ������������ �����������
              ����� ��� ���� ����� ��� �� �������� �� �������� Item.
  ����������: �� � ��������� ����� �������� � Found ����� true, � CurrPtr �������
                ���� ����� ��� �������� �� Item ��� � PredPtr ���� ����������� ���
                � ����� nil �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

/*ANAZHTHSH KOMBOU/STOXEIOU SE MIA MH TAKSINOMHMENH SYNDEDEMENH LISTA.*/
void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* �������:    ��� �������� Item ��� ��� ������������ ����������� �����,
                ��� �������� �������� ��������� �� ������� ������� ��� ���� �����
                � ������� List ������� ���� �����  �����.
   ����������: ������� �������� ��������� ��� ������������ ������������� ������
                ��� ��� ����� ����� ��� �������� �� �������� Item � ��� ��� ����
                ��� �� ������� ��� ��� ����� ��� �� �������� �� �������� Item.
   ����������: �� � ��������� ����� �������� � Found ����� true,
                � CurrPtr ������� ���� ����� ��� �������� �� Item ���
                � PredPtr ���� ����������� ��� � ����� nil �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}


/*SYNARTHSH: DIAGRAFH OLWN TWN STOIXEIWN MIAS LISTAS.*/
void DeleteAll(ListPointer *List, ListPointer PredPtr)
{
    while (!EmptyList(*List)) {
        LinkedDelete(List, PredPtr);
    }
}


