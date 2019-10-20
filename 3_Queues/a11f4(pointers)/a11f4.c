#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MaxNameChar 8

typedef char QueueElementType[MaxNameChar];

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode {
    QueueElementType Data;
    QueuePointer Next;
 } QueueNode;

typedef struct {
    QueuePointer Front;
    QueuePointer Rear;
 } QueueType;

typedef enum {
    FALSE, TRUE
 } boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);

boolean SearchUserID(QueueElementType userID);


/*KYRIWS PROGRAMMA*/
int main(){

    QueueType Q1;
    QueueElementType user_id;
    QueuePointer CurrPtr;
    char a;

    /*DHMIOURGIA OURAS*/
    CreateQ(&Q1);

    /*EISAGWGH USERNAME(user_id)*/
    printf("USERNAME: ");
    scanf("%s", user_id);

    if (SearchUserID(user_id)) {
            AddQ(&Q1, user_id);
        }
        else{
            printf("Wrong User ID \n");
        }

    printf("New entry Y/N (Y=Yes, N=No)? \n");
    a=getch();

    while(a=='y' || a=='Y') {
        printf("USERNAME: ");
        scanf("%s", user_id);

        if (!SearchUserID(user_id)) {
            printf("Wrong User ID \n");
        }
        else if (SearchUserID(user_id)) {
            CurrPtr = Q1.Front;

            while ( CurrPtr!=NULL){

                if (strcmp(CurrPtr->Data, user_id)==0) {
                    printf("You have logged in to the system from another terminal. New access is forbidden. \n");
                    break;
                }
                else {
                    CurrPtr = CurrPtr->Next;
                }

                if (CurrPtr==NULL) {
                    AddQ(&Q1, user_id);
                }
            }
        }
        printf("New entry Y/N (Y=Yes, N=No)? \n");
        a=getch();
    }

    printf("\nOnline users: \n");
    TraverseQ(Q1);

    return 0;
}


/*SYNARTHSH: DHMIOURGIA KENHS OURAS*/
 void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

/*SYNARTHSH: ELEGXOS EAN MIA OURA EINAI KENH*/
boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

/*SYNARTHSH: PROSTHIKH ENOS STOIXEIOU STO TELOS THS OURAS*/
void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    strcpy(TempPtr->Data, Item);
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

/*SYNARTHSH: AFAIRESH ENOS STOIXEIOU APO THN KORYFH THS OURAS*/
void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        strcpy(TempPtr->Data, *Item);
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

/*SYNARTHSH: EMFANISH OLWN TWN STOIXEIWN THS OURAS*/
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%s \n", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

/*SYNARTHSH: ANOIGMA ARXEIOU(*infile) KAI ELEGXOS EAN TO USERNAME(userID) POU EDWSE O XRHSTHS YPARXEI STO ARXEIO.*/
 boolean SearchUserID(QueueElementType userID)
{
     FILE *infile;
     char fileUsername[MaxNameChar];

     infile=fopen("I11F4.dat", "r"); //ANOIGMA ARXEIOU

     if (infile==NULL) {
        printf("Cannot open this file. Try again... \n"); //MHNYMA SE PERIPTWSH POU DEN BRETHEI TO ARXEIO
     }
     else {
        while (!feof(infile)){ //DIABASMA TOU PERIEXOMENOU TOU ARXEIOU
            fscanf(infile, "%s", fileUsername);

            if (strcmp(fileUsername, userID)==0){ //SYGKRINSH TOU PERIEXOMENOU, ME TO userID POU EDWSE O XRHSTHS
                fclose(infile);
                return TRUE;
            }
        }
     }
     fclose(infile);
     return FALSE;
}
