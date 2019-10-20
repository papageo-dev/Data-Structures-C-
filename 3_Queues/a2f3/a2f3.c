#include <stdio.h>

#define QueueLimit 100

typedef int QueueElementType;

typedef struct {
    int Front, Rear;
    QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void DisplayQA(QueueType *Queue);
void DisplayQB(QueueType Queue);


/*KYRIWS PROGRAMMA*/
int main() {

    int i;
    QueueType Q1;

    /*DHMIOYRGIA OYRAS(Queue)*/
    CreateQ(&Q1);

    /*GEMISMA OYRAS(Queue) ME PERITTOYS ARITHMOYS[1-100].*/
    for(i=1; i<=100; i=i+2){
        AddQ(&Q1, i);
    }

    /*EMFANISH STOIXEIWN OYRAS(Queue), SE EPIPEDO EFARMOGHS.*/
    printf("SE EPIPEDO EFARMOGHS(DisplayQA), TA STOIXEIA THS OYRAS EINAI:\n");
    DisplayQA(&Q1);

    /*EMFANISH STOIXEIWN OYRAS(Queue), SE EPIPEDO YLOPOIHSHS.*/
    printf("\n\nSE EPIPEDO YLOPOIHSHS(DisplayQB), TA STOIXEIA THS OYRAS EINAI:\n");
    DisplayQB(Q1);

return 0;
}


/*SYNARTHSH: EMFANISH TWN STOIXEIWN MIAS OYRAS(Queue), SE EPIPEDO EFARMOGHS.*/
void DisplayQA(QueueType *Queue)
{
    QueueType tempQ;
    QueueElementType item;

    /*DHMIOYRGIA BOHTHITIKHS OYRAS(tempQ).*/
    CreateQ(&tempQ);

    /*AFAIRESH OLWN TWN STOIXEIWN APO THN ARXIKH OYRA(Queue), EKTYPWSH KAI EISAGWGH STHN BOHTHITIKH OYRA(tempQ).*/
    while (!EmptyQ(*Queue)){
        RemoveQ(Queue, &item);
        printf("%d ", item);
        AddQ(&tempQ, item);
    }

    /*AFAIRESH OLWN TWN STOIXEIWN APO THN BOHTHITIKH OYRA(tempQ) KAI EISAGWGH STHN ARXIKH OYRA(Queue).*/
    while (!EmptyQ(tempQ)) {
        RemoveQ(&tempQ, &item);
        AddQ(Queue, item);
    }
}

/*SYNARTHSH: EMFANISH TWN STOIXEIWN MIAS OYRAS(Queue), SE EPIPEDO YLOPOIHSHS.*/
void DisplayQB(QueueType Queue)
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
