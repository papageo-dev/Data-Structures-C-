#include <stdio.h>
#include <string.h>

/*SYNARTHSH KATAKERMATISMOU: h(i) = (i % 10)*/

#define HMax 10             /* �� ������� ��� ������ HashTable
                               ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef struct{
    int code;
    char name[20];
    int type;
    }ListElementType;  /*���� ��������� ��� �� �������� ��� ������*/

typedef struct {
	int RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateHashList(HashListType *HList);
int HashKey(int Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,int DelKey);

void menu(int *choice);
void printUsers(HashListType HList, char types[][20]);

/*KURIWS PROGRAMMA*/
int main(){

    int choice;
    HashListType HList;
    ListElm item;
    char a;
    char userName[20], types[][20]={"Student", "PostgraduateStudent", "Teacher", "Visitor"}; //ANTISTOIXISH KWDIKWN(1,2,3,4) SE IDIOTHTES(char)
    int userCode, userType;
    int Loc, Pred;


    do
   {
   	menu(&choice);
      switch(choice)
      {
        case 1: { //1. Create HashList
                CreateHashList(&HList);                    /*DHMIOURGIA THS DOMHS DEDOMENWN(HList)*/
                }break;
        case 2: { //2. Insert new user
                do{
                    printf("\nEnter user's code: ");
                    scanf("%d", &userCode);                  /*EISAGWGH TOU KWDIKOU XRHSTH*/
                    fflush(stdin);
                    item.Data.code=userCode;                 /*ANTIGRAFH TOU KWDIKOU XRHSTH STHN DOMH*/

                    printf("Enter user's full name: ");
                    scanf(" %[^\n]s", userName);              /*EISAGWGH TOU ONAMATOS XRHSTH*/
                    fflush(stdin);
                    strcpy(item.Data.name, userName);         /*ANTIGRAFH TOU ONAMATOS XRHSTH STHN DOMH*/

                    printf("Enter user's Capacity (1 = Student, 2 = Postgraduate student, 3 = Teacher, 4 = Visitor): ");
                    scanf("%d", &userType);                   /*EISAGWGH THS IDIOTHTAS XRHSTH*/
                    fflush(stdin);
                    item.Data.type=userType;                  /*ANTIGRAFH THS IDIOTHTAS XRHSTH STHN DOMH*/

                    item.RecKey=item.Data.code;               /*DHLWSH TOU KWDIKOU XRHSTH WS KLEIDI KATAKERMATISMOU*/
                    item.Link=EndOfList;                      /*DHLWSH TIMHS GIA TO TELOS THS LISTAS KAI TWN YPOLISTWN*/

                    AddRec(&HList, item);                     /*EISAGWGH XRHSTH STHN DOMH DEDOMENWN(HList)*/

                    printf("Continue (Y/N)?");
                    scanf("%c", &a);

                   }while(a=='Y' || a=='y');                   /*ELEGXOS GIA EISAGWGH NEOU XRHSTH*/
                }break;
        case 3: { //3. Delete a user
                 do{
                    printf("\nEnter user's code for delete: ");
                    scanf("%d", &userCode);                     /*EISAGWGH KWDIKOU XRHSTH*/
                    fflush(stdin);

                    DeleteRec(&HList, userCode);                /*DIAGRAFH XRHSTH APO THN DOMH DEDOMENWN(HList)*/

                    printf("Continue (Y/N)?");
                    scanf("%c", &a);

                   }while(a=='Y' || a=='y');                     /*ELEGXOS GIA DIAGRAFH NEOU XRHSTH*/
                }break;
        case 4: { //4. Search for a user
                 do{
                    printf("\nEnter user's code for search: ");
                    scanf("%d", &userCode);                      /*EISAGWGH KWDIKOU XRHSTH*/
                    fflush(stdin);

                    SearchHashList(HList, userCode, &Loc, &Pred); /*ANAZHTHSH STHN DOMH DEDOMENWN BASH TOU KWDIKOU XRHSTH*/

                    if (Loc!=-1){ //AN O XRHSTHS BRETHEI, EKTYPWSH TWN STOIXEIWN TOU
                        printf("\nUser Found!\n %s, %d, %s\n",
                               HList.List[Loc].Data.name, HList.List[Loc].Data.code, types[HList.List[Loc].Data.type-1]);
                    }
                    else{ //AN O XTRHSTHS DEN BRETHEI, EKTYPWSH MHNYMATOS
                        printf("There is no user with code %d\n", userCode);
                    }

                    printf("Continue (Y/N)?");
                    scanf("%c", &a);

                   }while(a=='Y' || a=='y');                      /*ELEGXOS GIA ANAZHTHSH NEOU XRHSTH*/
                }break;
        case 5: { //5. Print list of all users
                printUsers(HList, types);                                /*EKTYPWSH TWN STOIXEIWN OLWN TWN XRHSTWN*/
                }break;
		}
   } while (choice!=6); //6. Quit

return 0;
}


int HashKey(int Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		//HList->List[index].Data=0; /*MPAINEI SE SXOLIO/DEN XREIAZETAI AFOU EXW DOMH DEDOMENWN GIA KATHE EGGRAFH*/
		index=index+1;
	}
	HList->List[index].Link=EndOfList;

	printf("HashTable\n");
	for (index=0;index<HMax;index++)
	   printf("%d: %d\n",index,HList->HashTable[index]);

    printf("List of keys\n");
	for (index=0;index<=VMax-1;index++)
	   printf("%d\t%d\n",index,HList->List[index].Link);
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,int DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}


/*SYNARTHSH: MENU EPILOGWN*/
void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create HashList\n");
    printf("2. Insert new user\n");
    printf("3. Delete a user\n");
    printf("4. Search for a user\n");
    printf("5. Print list of all users\n");
    printf("6. Quit\n");
    printf("\nCHOICE: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

/*SYNARTHSH: EKTYPWSH TWN STOIXEIWN OLWN TWN XRHSTWN*/
void printUsers(HashListType HList, char types[][20])
{
    int i, tempHash, key;

    printf("\nUSERS:\n");
	for(i=0; i<HMax-1; i++){
        tempHash = HList.HashTable[i];
        key=HashKey(HList.List[tempHash].RecKey); //key=HValue(TIMH KATAKERMATISMOU)

        if (tempHash!=EndOfList){
            printf("\nSynonyms, collision at position: %d\n", key);
        }

        while (tempHash!=EndOfList){ //OSO YPARXOUN KATAXWRHMENOI XRHSTES, EKTYPWSH TWN STOIXEIWN TOUS
                printf("%d: [%s, %d, %s]\n", tempHash, HList.List[tempHash].Data.name, HList.List[tempHash].Data.code, types[HList.List[tempHash].Data.type-1]);
                tempHash = HList.List[tempHash].Link; //METAKINHSH TOY tempList STHN EPOMENH KATAXWRHSH(XRHSTH)
        }
    }
}
