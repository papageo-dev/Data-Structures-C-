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

void Larger(ListPointer InList, ListElementType number, ListPointer *OutList);


/*KYRIWS PROGRAMMA*/
int main(){

    /*DHLWSH METABLHTWN*/
    ListElementType i, n, item, number;
    ListPointer AList, PredPtr, BList;

    /*ARXIKOPOIHSH PredPtr*/
    PredPtr=NULL;

    /*DHMIOURGIA LISTAS*/
    CreateList(&AList);

    /*EISAGWGH TOU MEGATHOUS THS LISTAS.*/
    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &n);

    /*EISAGWGH STOIXEIWN STHN LISTA*/
    for (i=0; i<n; i++){
        printf("DWSE ARI8MO GIA EISAGWSH STHN ARXH THS LISTAS: ");
        scanf("%d", &item);
        LinkedInsert(&AList, item, PredPtr);
    }

    /*EMFANISH TWN STOIXEIWN THS LISTAS(AList)*/
    printf("\nINPUT LIST: ");
    LinkedTraverse(AList);

    /*DIAXWRISMOS LISTAS. DHMIOURGIA NEAS LISTAS 'OutList', ME TA STOIXEIA POU EINAI >= 'number'.*/
    printf("\n\nDWSE ENAN ARI8MO/ORIO(THRESHOLD), GIA TA STOIXEIA THS BList: ");
    scanf("%d", &number);
    Larger(AList, number, &BList);

    /*EMFANISH TWN STOIXEIWN THS LISTAS(BList)*/
    printf("\nLARGER LIST (THRESHOLD %d): ", number);
    LinkedTraverse(BList);

return 0;
}


/*SYNARTHSH: DHMIOURGIA MIAS KENHS SYNDEDEMENHS LISTAS.*/
void CreateList(ListPointer *List)
{
	*List = NULL;
}

/*SYNARTHSH: ELEGXOS AN H LISTA EINAI KENH.*/
boolean EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
	return (List==NULL);
}

/*SYNARTHSH: EISAGWGH ENOS NEOU KOMBOU/STOIXEIOU STHN LISTA.*/
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
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
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο της
                 και έναν δείκτη PredPtr.
   Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα τον κόμβο που έχει
                για προηγούμενό του αυτόν στον οποίο δείχνει ο PredPtr
                ή διαγράφει τον πρώτο κόμβο, αν ο PredPtr είναι μηδενικός,
                εκτός και αν η λίστα είναι κενή.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο
                να δεικτοδοτείται από τον List.
   Έξοδος:     Ένα μήνυμα κενής λίστας αν η συνδεδεμένη λίστα ήταν κενή .
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
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
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
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Εκτελεί μια γραμμική αναζήτηση στην μη ταξινομημένη συνδεδεμένη
              λίστα για έναν κόμβο που να περιέχει το στοιχείο Item.
  Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true, ο CurrPtr δείχνει
                στον κόμβο που περιέχει το Item και ο PredPtr στον προηγούμενό του
                ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
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
/* Δέχεται:    Ένα στοιχείο Item και μια ταξινομημένη συνδεδεμένη λίστα,
                που περιέχει στοιχεία δεδομένων σε αύξουσα διάταξη και στην οποία
                ο δείκτης List δείχνει στον πρώτο  κόμβο.
   Λειτουργία: Εκτελεί γραμμική αναζήτηση της συνδεδεμένης ταξινομημένης λίστας
                για τον πρώτο κόμβο που περιέχει το στοιχείο Item ή για μια θέση
                για να εισάγει ένα νέο κόμβο που να περιέχει το στοιχείο Item.
   Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true,
                ο CurrPtr δείχνει στον κόμβο που περιέχει το Item και
                ο PredPtr στον προηγούμενό του ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
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


/*SYNARTHSH: DIAXWRISMOS LISTAS. DHMIOURGIA NEAS LISTAS 'OutList', ME TA STOUXEIA POU EINAI MEGALUTERA TOU 'number'.*/
void Larger(ListPointer InList, ListElementType number, ListPointer *OutList)
{
    ListPointer CurrPtr, PrevPtr;

    CurrPtr=InList;
    PrevPtr=NULL;

    /*DHMIOURGIA LISTAS*/
    CreateList(OutList);

    while (CurrPtr!=NULL){ //OSO DEN EXW FTASEI STO TELOS THS ARXIKHS LISTAS...
            if (CurrPtr->Data>=number){ //AN TO TRAXON STOIXEIO THS ARXIKHS LISTAS >= number, EISAGWGH STHN DEUTERH LISTA.
                LinkedInsert(OutList, CurrPtr->Data, PrevPtr);
                if (PrevPtr==NULL) { //AN EINAI TO PRWTO STOIXEIO POU EISAGETAI...
                    PrevPtr=*OutList; //TO PrevPtr NA DEIXNEI STO MONADIKO STOIXEIO THS LISTAS.
                }
                else{
                    PrevPtr=PrevPtr->Next; //ALLIWS, TO PrevPtr NA DEIXNEI STO TELEYTAIO STOIXEIO THS LISTAS.
                }
            }
            CurrPtr=CurrPtr->Next; //ENHMERWSH TOY CurrPtr, NA DEIXNEI STO EPOMENO STOIXEIO THS LISTAS.
    }
}
