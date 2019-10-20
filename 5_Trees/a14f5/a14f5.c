#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*DOMH GIA TA STOIXEIA KATHE KATHIGHTH*/
typedef struct{
    char name[21];
    char phone[11];
    int code;
} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType Item, boolean *Found, BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

void menu(int *choice);
void BuildBST(BinTreePointer *Root, BinTreeElementType EmpRec);
void InorderTraversalCode(BinTreePointer Root, int tCode);


/*KYRIWS PROGRAMMA*/
int main(){

    int choice;
    BinTreePointer Aroot, LocPtr;
    BinTreeElementType EmpRec;
    char tName[21], tPhone[11];
    int tCode;
    boolean found;

    /*DHMIOURGIA KENOU DDA*/
    CreateBST(&Aroot);

    do{
    menu(&choice);

    switch(choice){

    case 1: { //1.Create BST
            BuildBST(&Aroot, EmpRec); //EISAGWGH KATHIGHTWN APO ARXEIO
            }break;
    case 2: { //2.Insert new teacher
            printf("Give teacher name? "); //EISAGWGH ONOMATOS KATHIGHTH APO TON XRHSTH
            scanf(" %[^\n]s", tName);
            fflush(stdin);
            strcpy(EmpRec.name, tName); //ANTIGRAFH ONOMATOS KATHIGHTH STH DOMH

            printf("Give teacher phone number? "); //EISAGWGH THLEFWNOU KATHIGHTH APO TON XRHSTH
            scanf("%s", tPhone);
            fflush(stdin);
            strcpy(EmpRec.phone, tPhone); //ANTIGRAFH THLEFWNOU KATHIGHTH STH DOMH

            printf("Give teacher code? "); //EISAGWGH KWDIKOU MATHIMATOS TOU KATHIGHTH APO TON XRHSTH
            scanf("%d", &tCode);
            fflush(stdin);
            EmpRec.code=tCode; //ANTIGRAFH KWDIKOU MATHIMATOS TOU KATHIGHTH STH DOMH

            BSTInsert(&Aroot, EmpRec); //EISAGWGH TWN STOIXEIWN TOU KATHIGHTH STO DDA
            }break;
    case 3: { //3.Delete a teacher
            if (EmptyBST(Aroot)) { //AN TO DENTRO EINAI KENO...
                printf("There are no teachers...\n");
            }
            else{
                printf("Enter a teacher's name for delete: "); //EISAGWGH ONOMATOS KATHIGHTH APO TON XRHSTH
                scanf(" %[^\n]s", tName);
                strcpy(EmpRec.name, tName); //ANTIGRAFH ONOMATOS KATHIGHTH STH DOMH
                fflush(stdin);
                BSTDelete(&Aroot, EmpRec); //DIAGRAFH KATHIGHTH APO TO DDA
                printf("Success! %s has deleted!\n", tName);
                }
            }break;
    case 4: { //4.Search for a teacher
            if (EmptyBST(Aroot)){
                printf("There are no teachers...\n");
            }
            else{
                printf("Enter a teacher's name: "); //EISAGWGH ONOMATOS KATHIGHTH APO TON XRHSTH
                scanf(" %[^\n]s", tName);
                fflush(stdin);
                strcpy(EmpRec.name, tName); //ANTIGRAFH ONOMATOS KATHIGHTH STH DOMH
                BSTSearch(Aroot, EmpRec, &found, &LocPtr); //ANAZHTHSH KATHIGHTH BASH ONOMATOS

                if (!found){ //AN DEN BRETHEI...
                    printf("Teacher not found...");
                }
                else{ //AN BRETHEI, EKTYPWSH TWN STOIXEIWN TOU.
                    InorderTraversal(LocPtr);
                }
            }
            }break;
    case 5: { //5.Search by subject
            if (EmptyBST(Aroot)){ //AN TO DENTRO EINAI KENO...
                printf("There are no teachers...\n");
            }
            else{
                printf("Enter the code of subject that you want to search: "); //EISAGWGH KWDIKOU MATHIMATOS APO TON XRHSTH
                scanf("%d", &tCode);
                fflush(stdin);
                EmpRec.code=tCode; //ANTIGRAFH KWDIKOU MATHIMATOS STHN DOMH
                InorderTraversalCode(Aroot, EmpRec.code); //ANAZHTHSH BASH TOU KWDIKOU MATHIMATOS KAI EMFANISH STOIXEIWN KATHIGHTH, EAN BRETHEI
            }
            }break;
    case 6: { //6.Print teachers
            if (EmptyBST(Aroot)){ //AN TO DENTRO EINAI KENO...
                printf("There are no teachers...\n");
            }
            else{
            printf("\nAll Teachers: \n\n");
            InorderTraversal(Aroot); //EMFANISH TWN STOIXEIWN OLWN TWN KATHIGHTWN
            }
            }break;
    }
    } while (choice!=7); //7.Quit

return 0;
}


/*SYNARTHSH: DHMIOURGIA ENOS KENOU DDA*/
void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

/*SYNARTHSH: ELEGXOS EAN ENA DDA EINAI KENO*/
boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

/*SYNARTHSH: EISAGWGH ENOS STOIXEIOU/KOMBOU SE ENA DDA*/
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;

    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item.name,LocPtr->Data.name) < 0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item.name,LocPtr ->Data.name) > 0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item.name);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item.name,Parent ->Data.name) < 0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

/*SYNARTHSH: ANAZHTHSH ENOS STOIXEIOU SE ENA DDA, ME BASH THN TIMH TOU KeyValue*/
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    (*LocPtr) = Root;
    (*Found) = FALSE;

    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue.name, (*LocPtr)->Data.name) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue.name, (*LocPtr)->Data.name) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (strcmp(KeyValue.name, (*LocPtr)->Data.name) < 0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (strcmp(KeyValue.name, (*LocPtr)->Data.name) > 0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }
}

/*SYNARTHSH: DIAGRAFH ENOS TOIXEIOU/KOMBOU APO ENA DDA, ME BASH THN TIMH TOU KeyValue*/
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue.name);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
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

/*SYNARTHSH: DIASXISH ENOS DDA KAI EMFANISH OLWN TWN STOIXEIWN TOU*/
void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s, %s, %d \n", Root->Data.name, Root->Data.phone, Root->Data.code);
        InorderTraversal(Root->RChild);
    }
}

/*SYNARTHSH: MENU EPILOGWN(1-7)*/
void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create BST\n");
    printf("2. Insert new teacher\n");
    printf("3. Delete a teacher\n");
    printf("4. Search for a teacher\n");
    printf("5. Search by subject\n");
    printf("6. Print teachers\n");
    printf("7. Quit\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

/*SYNARTHSH: ANOIGMA, DIABASMA ARXEIOU KAI KATAXWRHSH TWN STOIXEIWN TOU SE ENA DDA */
void BuildBST(BinTreePointer *Root, BinTreeElementType EmpRec)
{
    FILE *infile;
    char termch;

    /*ANOIGMA ARXEIOU*/
    infile=fopen("I14F5.TXT", "r");

    if (infile==NULL){ //AN DEN MPOREI NA ANOIKSEI TO ARXEIO, EMFANIZEI MHNUMA KAI TERMATIZEI TO PROGRAMMA...
        printf("Can't open this file...\n");
        exit(1);
    }
    else{
        /*DIABASMA TOU PERIEXOMENOU TOU ARXEIOU KAI KATAXWRHSH STIS METABHTES*/
        while (!feof(infile)){
            fscanf(infile, "%20[^,], %10[^,], %d%c", EmpRec.name, EmpRec.phone, &EmpRec.code, &termch);
            BSTInsert(&(*Root), EmpRec); //EISAGWGH TWN STOIXEIWN TOU ARXEIOU STO DDA
        }
    }
    /*KLEISIMO ARXEIOU*/
    fclose(infile);
}

/*SYNARTHSH: DIASXISH ENOS DDA KAI EMFANISH MONO TWN STOIXEIWN POU IKANOPOIOUN TO PEDIO code(tCode==Root->Data.code)*/
void InorderTraversalCode(BinTreePointer Root, int tCode)
{
    if (Root!=NULL) {
        InorderTraversalCode(Root->LChild, tCode);
        if (Root->Data.code == tCode){
            printf("%s, %s, %d\n", Root->Data.name, Root->Data.phone, Root->Data.code);
        }
        InorderTraversalCode(Root->RChild, tCode);
    }
}
