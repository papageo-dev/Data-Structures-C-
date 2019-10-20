#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*DOMH GIA TA STOIXEIA KATHE YPALLHLOU*/
typedef struct{
    char LastName[21];
    char name[21];
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
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

void menu(int *choice);
void BuildBST(BinTreePointer *Aroot, BinTreePointer *Broot, BinTreePointer *Croot, BinTreeElementType empRec);
void TraversalBST(BinTreePointer Root, BinTreePointer LocPtr);


/*KYRIWS PROGRAMMA*/
int main(){

    int choice;
    BinTreePointer Aroot, Broot, Croot, tempRoot, LocPtr;
    BinTreeElementType empRec;
    char empLastName[21], empName[21];
    int empCode;
    boolean found;

    /*DHMIOURGIA TWN DDA*/
    CreateBST(&Aroot); //YPALLHLOI GRAFEIOU
    CreateBST(&Broot); //ERGATES
    CreateBST(&Croot); //ANTIPROSWPOI

    do
   {
   	menu(&choice);
      switch(choice)
      {
        case 1: { //1. Create BSTs from file
                BuildBST(&Aroot, &Broot, &Croot, empRec); //EISAGWGH ERGAZOMENWN APO ARXEIO
                }break;
        case 2: { //2. Insert new employee
                 printf("Give employee's last name? "); //EISAGWGH EPWNUMOU ERGAZOMENOU APO TON XRHSTH
                 scanf(" %[^\n]s", empLastName);
                 fflush(stdin);
                 strcpy(empRec.LastName, empLastName); //ANTIGRAFH EPWNUMOU ERGAZOMENOU STH DOMH

                 printf("Give employee's first name? "); //EISAGWGH ONOMATOS ERGAZOMENOU APO TON XRHSTH
                 scanf("%s", empName);
                 fflush(stdin);
                 strcpy(empRec.name, empName); //ANTIGRAFH ONOMATOS ERGAZOMENOU STH DOMH

                 printf("Give employee's code? "); //EISAGWGH KWDIKOU ERGZOMENOU APO TON XRHSTH
                 scanf("%d", &empCode);
                 fflush(stdin);
                 empRec.code=empCode; //ANTIGRAFH KWDIKOU ERGAZOMENOU STH DOMH

                 if (empRec.code==1){ //EISAGWGH YPALLHLOU GRAFEIOU
                    RecBSTInsert(&Aroot, empRec);
                 }
                 else if (empRec.code==2){ //EISAGWGH ERGATH
                    RecBSTInsert(&Broot, empRec);
                 }
                 else if (empRec.code==3){ //EISAGWGH ANTIPROSWPOU
                    RecBSTInsert(&Croot, empRec);
                 }
                 else{ //AN DWTHEI LATHOS KWDIKOS ERGAZOMENOU
                    printf("ATTENTION! You cant use: %d as employee's code! Try again with codes:(1 or 2 or 3).", empRec.code);
                 }
                }break;
        case 3: { //3. Search for an employee
                printf("Give employee's last name: "); //EISAGWGH EPWNUMOU ERGAZOMENOU APO TON XRHSTH
                scanf(" %[^\n]s", empLastName);
                fflush(stdin);
                strcpy(empRec.LastName, empLastName); //ANTIGRAFH EPWNUMOU ERGAZOMENOU STH DOMH
                printf("Give employee's code? "); //EISAGWGH KWDIKOU ERGZOMENOU APO TON XRHSTH
                scanf("%d", &empCode);
                fflush(stdin);
                empRec.code=empCode; //ANTIGRAFH KWDIKOU ERGAZOMENOU STH DOMH

                if (empRec.code==1){ //ANAZHTHSH GIA YPALLHLO GRAFEIOU
                    tempRoot=Aroot;
                    RecBSTSearch(tempRoot, empRec, &found, &LocPtr);
                }
                else if (empRec.code==2){ //ANAZHTHSH GIA ERGATH
                    tempRoot=Broot;
                    RecBSTSearch(tempRoot, empRec, &found, &LocPtr);
                }
                else if (empRec.code==3){ //ANAZHTHSH GIA ANTIPROSWPO
                    tempRoot=Croot;
                    RecBSTSearch(tempRoot, empRec, &found, &LocPtr);
                }
                if (!found){ //AN DEN BRETHEI...
                    printf("Employee with Last Name: '%s' not found...", empRec.LastName);
                }
                else { //AN BRETHEI, EKTYPWSH TWN STOIXEIWN TOU
                    TraversalBST(tempRoot, LocPtr);
                }
                }break;
        case 4: { //4. Print employees
                printf("\nYPALLHLOI GRAFEIOU:\n"); //EKTYPWSH YPALLHLWN GRAFEIOU
                RecBSTInorder(Aroot);
                printf("\nERGATES:\n"); //EKTYPWSH ERGATWN
                RecBSTInorder(Broot);
                printf("\nANTIPROSWPOI:\n"); //EKTYPWSH ANTIPROSWPWN
                RecBSTInorder(Croot);
                }break;
      }
   } while (choice!=5); //5. Quit

return 0;
}


void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (strcmp(Item.name,(*Root) ->Data.name) < 0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (strcmp(Item.name,(*Root) ->Data.name) > 0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %s EINAI HDH STO DDA\n", Item.name);
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{
    boolean stop;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (strcmp(KeyValue.LastName, Root->Data.LastName) < 0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (strcmp(KeyValue.LastName, Root->Data.LastName) > 0)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ����� ������ �� KeyValue �� �� ������ *)
        printf("to %s DeN BRE8HKe STO DDA\n", KeyValue.name);
     else
         //* ��������� ���������� ��� ����� ��� �������� ��� ���� KeyValue ��� �������� ���
          if (strcmp(KeyValue.name, (*Root)->Data.name) < 0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* �������� ��������� *
          else
            if (strcmp(KeyValue.name, (*Root)->Data.name) > 0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ����  ��������� *
            else                                       //* TO KeyValue ������� �������� ��� ������ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ��� ���� �������� ����� *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ���� �������� �����, ���� ��� ���� *)
                        free(TempPtr);
                   }
                   else                               //* ���� 2 ������ *)
                   {
                        //* ������ ��� INORDER �������� ��� *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ���������� ��� �������� ��� ����� ��� ����������
                        ��� ���������� ��� �������� ��� �������� ������ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("<%s, %s, %d>, ", Root->Data.LastName, Root->Data.name, Root->Data.code);
        RecBSTInorder(Root->RChild);
    }
}

void RecBSTPreorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ��������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        printf("/%d ",Root->Data,"/");
        printf("L");
        RecBSTPreorder(Root->LChild);
        printf("R");
        RecBSTPreorder(Root->RChild);
    }
    printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        printf("L");
        RecBSTPostorder(Root->LChild);
        printf("R");
        RecBSTPostorder(Root->RChild);
        printf("/%d ",Root->Data,"/");
    }
    printf("U");
}


/*SYNARTHSH: EMFANISH MENU EPILOGWN*/
void menu(int *choice)
{
    printf("\n                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create BSTs from file\n");
    printf("2. Insert new employee\n");
    printf("3. Search for an employee\n");
    printf("4. Print employees\n");
    printf("5. Quit\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>4);
}

/*SYNARTHSH: EISAGWGH STOIXEIWN APO ARXEIO SE DDA, BASH THS TIMHS TOU EmpRec.code*/
void BuildBST(BinTreePointer *Aroot, BinTreePointer *Broot, BinTreePointer *Croot, BinTreeElementType EmpRec)
{
    FILE *infile;
    char termch;

    /*ANOIGMA ARXEIOU*/
    infile=fopen("I13F5.TXT", "r");

    if (infile==NULL){ //AN DEN MPOREI NA ANOIKSEI TO ARXEIO, EMFANIZEI MHNUMA KAI TERMATIZEI TO PROGRAMMA...
        printf("Can't open this file...\n");
        exit(1);
    }
    else{
        /*DIABASMA TOU PERIEXOMENOU TOU ARXEIOU KAI KATAXWRHSH STIS METABHTES*/
        while (!feof(infile)){
            fscanf(infile, "%20[^ ] %20[^ ] %d%c", EmpRec.LastName, EmpRec.name, &EmpRec.code, &termch);
            if (EmpRec.code==1){
                RecBSTInsert(&(*Aroot), EmpRec); //EISAGWGH YPALLHLWN GRAFEIOU
            }
            else if (EmpRec.code==2){
                RecBSTInsert(&(*Broot), EmpRec); //EISAGWGH ERGATWN
            }
            else if (EmpRec.code==3){
                RecBSTInsert(&(*Croot), EmpRec); //EISAGWGH ANTIPROSWPWN
            }
        }
    }
    /*KLEISIMO ARXEIOU*/
    fclose(infile);
}

/*SYNARTHSH: EMFANISH TOU PERIEXOMENOU TOU EPILEGMENOU KOMBOU (LocPtr)*/
void TraversalBST(BinTreePointer Root, BinTreePointer LocPtr)
{
    if (Root!=NULL){
        printf("<%s, %s, %d>", LocPtr->Data.LastName, LocPtr->Data.name, LocPtr->Data.code);
    }
}
