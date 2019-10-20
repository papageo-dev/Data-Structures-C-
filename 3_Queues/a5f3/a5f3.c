#include <stdio.h>

#define QueueLimit 100
#define StackLimit 100

typedef int QueueElementType;

typedef struct {
    int Front, Rear;
    QueueElementType Element[QueueLimit];
} QueueType;

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void ReverseQ(QueueType *Queue);
void TraverseQ(QueueType Queue);


/*KYRIWS PROGRAMMA*/
int main() {

    int i;

    QueueType Q1;

    /*DHMIOYRGIA KENHS OYRAS(Queue).*/
    CreateQ(&Q1);

    /*GEMISMA THS OYRAS(Queue) ME STOIXEIA.*/
    for (i=2; i<=30; i=i+2){
        AddQ(&Q1, i);
    }

    /*EKTYPWSH STOIXEIWN OYRAS(Queue), PRIN THN ANTISTROFH.*/
    printf("TA STOIXEIA THS OYRAS(Queue) PRIN THN ANTISTROFH EINAI:\n");
    TraverseQ(Q1);
    printf("\n");

    /*ANTISTROFH TWN STOIXEIWN THS OYRAS(Queue).*/
    ReverseQ(&Q1);

    /*EKTYPWSH STOIXEIWN OYRAS(Queue), PRIN THN ANTISTROFH.*/
    printf("TA STOIXEIA THS OYRAS(Queue) META THN ANTISTROFH EINAI:\n");
    TraverseQ(Q1);

return 0;
}



/*SYNARTHSH: ANTISTROFH TWN STOIXEIWN MIAS OYRAS(Queue), ME THN XRHSH STOIBAS(Stack).*/
void ReverseQ(QueueType *Queue)
{
    StackType tempStack;
    QueueElementType item;

    /*DHMIOYRGIA KENHS STOIBAS(Stack).*/
    CreateStack(&tempStack);

    /*AFAIRESH STOIXEIWN APO THN OYRA(Queue) KAI EISAGWGH STHN STOIBA(Stack).*/
    while (!EmptyQ(*Queue)){
        RemoveQ(Queue, &item);
        Push(&tempStack, item);
    }

    /*AFAIRESH STOIXEIWN APO THN STOIBA(Stack) KAI EISAGWGH STHN OYRA(Queue).*/
    while (!EmptyStack(tempStack)){
        Pop(&tempStack, &item);
        AddQ(Queue, item);
    }

}

/*SYNARTHSH: EMFANISH TWN STOIXEIWN THS OYRAS(Queue).*/
void TraverseQ(QueueType Queue)
{
    int current;

    current = Queue.Front;

    while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
        current = (current + 1) % QueueLimit;
    }
    printf("\n");
}

/*SYNARTHSH: DHMIOYRGIA KENHS OYRAS(Queue).*/
void CreateQ(QueueType *Queue)
{
    Queue->Front = 0;
    Queue->Rear = 0;
}

/*SYNARTHSH: ELEGXOS AN MIA OYRA(Queue) EINAI KENH.*/
boolean EmptyQ(QueueType Queue)
{
    return (Queue.Front == Queue.Rear);
}

/*SYNARTHSH: ELEGXOS AN MIA OYRA(Queue) EINAI GEMATH.*/
boolean FullQ(QueueType Queue)
{
    return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

/*SYNARTHSH: AFAIRESH STOIXEIOY APO THN OYRA(Queue), AN DEN EINAI KENH.*/
void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    if(!EmptyQ(*Queue)){
        *Item = Queue ->Element[Queue -> Front];
        Queue ->Front = (Queue ->Front + 1) % QueueLimit;
}
    else{
        printf("Empty Queue\n");
    }
}

/*SYNARTHSH: EISSAGWGH STOIXEIOY STHN OURA(Queue), AN DEN EINAI GEMATH.*/
void AddQ(QueueType *Queue, QueueElementType Item)
{
    int NewRear;

    if(!FullQ(*Queue)){
        NewRear = (Queue ->Rear + 1) % QueueLimit;
        Queue ->Element[Queue ->Rear] = Item;
        Queue ->Rear = NewRear;
    }
    else{
        printf("Full Queue\n");
    }
}


/*SYNARTHSH: DHMIOYRGIA KENHS STOIBAS(Stack).*/
void CreateStack(StackType *Stack)
{
 Stack -> Top = -1;
}

/*SYNARTHSH: ELEGXOS AN H STOIBA(Stack) EINAI KENH.*/
boolean EmptyStack(StackType Stack)
{
 return (Stack.Top == -1);
}

/*SYNARTHSH: ELEGXOS AN H STOIBA(Stack) EINAI GEMATH.*/
boolean FullStack(StackType Stack)
{
 return (Stack.Top == (StackLimit - 1));
}

/*SYNARTHSH: EISAGWGH STOIXEIOY(Item) STHN KORYFH THS STOIBAS(Stack), AN DEN EINAI GEMATH.*/
void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    }
    else
        printf("Full Stack...");
}

/*SYNARTHSH: DIAGRAFH STOIXEIOY(Item) APO THN KORYFH THS STOIBAS(Stack), AN DEN EINAI ADEIA.*/
void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    }
    else
        printf("Empty Stack...");
}

