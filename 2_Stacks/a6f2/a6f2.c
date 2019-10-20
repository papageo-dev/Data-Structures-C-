#include <stdio.h>

#define StackLimit 100

/*DOMES/EGGRAFES*/
typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FASLE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void GetTopElementA(StackType *Stack, StackElementType *Item);
void GetTopElementB(StackType Stack, StackElementType *Item);

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);


/*KYRIWS PROGRAMMA*/
int main(){

    int i;
    StackType Stack;
    StackElementType a, b;

    /*DHMIOYRGIA KENHS STOIBAS(Stack).*/
    CreateStack(&Stack);

    /*EISAGWGH OLWN TWN PERITTWN ARITHMWN (1-100), STHN STOIBA(Stack).*/
    for (i=1; i<100; i=i+2){
        Push(&Stack, i);
    }

    GetTopElementA(&Stack, &a);
    GetTopElementB(Stack, &b);

    printf("TO STOIXEIO THS KORYFHS THS STOIBAS(Stack), SE EPIPEDO EFARMOGHS EINAI TO: %d\n", a);
    printf("TO STOIXEIO THS KORYFHS THS STOIBAS(Stack), SE EPIPEDO YLOPOIHSHS EINAI TO: %d\n", b);

return 0;
}


/*SYNARTHSH: EPISTROFH TOY STOIXEIOY  THS KORYFHS MIAS STOIBAS(Stack), SE EPIPEDO EFARMOGHS.*/
void GetTopElementA(StackType *Stack, StackElementType *Item)
{
    Pop(Stack, Item);
    Push(Stack, *Item);
}

/*SYNARTHSH: EPISTROFH TOY STOIXEIOY  THS KORYFHS MIAS STOIBAS(Stack), SE EPIPEDO YLOPOIHSHS.*/
void GetTopElementB(StackType Stack, StackElementType *Item)
{
    *Item=Stack.Element[Stack.Top];
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

