#include <stdio.h>
#include <stdlib.h>

typedef double StackElementType;

typedef struct StackNode *StackPointer;

typedef struct StackNode{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

void TraverseStack(StackPointer Stack);
void platform(StackPointer *Stack, StackElementType Item);

/*KYRIWS PROGRAMMA*/
int main(){

    StackPointer truck;
    StackElementType weight;
    double value;

    /*DHMIOURGIA KENHS STOIBAS(truck)*/
    CreateStack(&truck);

    /*EISAGWGH TOU ARXIKOU FORTIOU STO FORTIGO(truck)*/
    Push(&truck, 3.0);
    Push(&truck, 2.0);
    Push(&truck, 1.0);
    Push(&truck, 0.5);
    Push(&truck, 0.4);

    /*EISAGWGH NEOU FORTIOU APO TON XRHSTH*/
    while (value>0 || weight>0) {
        printf("\nGive the weight: ");
        scanf("%lf", &weight);

        printf("Give the value: ");
        scanf("%lf", &value);

        if (value>(weight*300)) { //ELEGXOS EAN 8A GINEI H OXI H METAFORA TOU FORTIOU
            platform(&truck, weight);
        }
        else{
            printf("Not Enough Value.\n");
        }
    }

return 0;
}


/*SYNARTHSH: DHMIOURGIA MIAS KENHS STOIBAS*/
void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

/*SYNARTHSH: ELEGXOS EAN MIA STOIBA EINAI KENH*/
boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

/*SYNARTHSH: EISAGWGH ENOS STOIXEIOU STHN KORUFH MIAS STOIBAS*/
void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

/*SYNARTHSH: EKSAGWGH ENOS STOIXEIOU APO THN KORUFH MIAS STOIBAS*/
void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

/*SYNARTHSH: EKTYPWSH OLWN TWN STOIXEIWN MIAS STOIBAS*/
void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%.1lf \n", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}


void platform(StackPointer *Stack, StackElementType Item)
{
    StackPointer CurrPtr, tmpPtr;
    StackPointer tempTruck;

    CreateStack(&tempTruck);

    CurrPtr=*Stack;

    while (Item>CurrPtr->Data){
        Pop(&CurrPtr, &CurrPtr->Data);
        Push(&tempTruck, CurrPtr->Data);

        CurrPtr=CurrPtr->Next;
    }

    printf("--Platform--\n");
    TraverseStack(tempTruck);

    Push(&CurrPtr, Item); //EISAGWGH TOU NEOU FORTIOU
    tmpPtr=CurrPtr;

    while (!EmptyStack(tempTruck)){
        Pop(&tempTruck, &tmpPtr->Data);
        Push(&CurrPtr, tmpPtr->Data);

        tmpPtr=tmpPtr->Next;
    }

    printf("--Truck--\n");
    TraverseStack(CurrPtr);
}
