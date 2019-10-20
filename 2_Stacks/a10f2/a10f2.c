#include <stdio.h>

#define StackLimit 100

/*DOMES/EGGRAFES*/
typedef char StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FASLE, TRUE
} boolean;

/*SYNARTHSEIS/DIADIKASIES*/
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);


/*KYRIWS PROGRAMMA*/
int main(){

    int i;
    StackType Stack1, Stack2, Stack3;
    StackElementType Item;

    /*DHMIOYRGIA STOIBWN.*/
    CreateStack(&Stack1);
    CreateStack(&Stack2);
    CreateStack(&Stack3);

    /*EISAGWGH STOIXEIWN STHN Stack1.*/
    Push(&Stack1, 'P');
    Push(&Stack1, 'A');
    Push(&Stack1, 'S');
    Push(&Stack1, 'C');
    Push(&Stack1, 'A');
    Push(&Stack1, 'L');

    /*EKTYPWSH TOY PERIEXOMENOY THS Stack1.*/
    printf("Stack1\n");
    TraverseStack(Stack1);

    /*METAFORA TWN STOIXEIWN, APO THN Stack1 STHN Stack2.*/
    i=0;
    while (!EmptyStack(Stack1)){
        Pop(&Stack1,&Item);
        Push(&Stack2, Item);
        i++;
    }

    /*EKTYPWSH TOY PERIEXOMENOY THS Stack2.*/
    printf("\nStack2\n");
    TraverseStack(Stack2);

    /*METAFORA TWN STOIXEIWN, APO THN Stack2 STHN Stack3.*/
    i=0;
    while (!EmptyStack(Stack2)){
        Pop(&Stack2,&Item);
        Push(&Stack3, Item);
        i++;
    }

    /*EKTYPWSH TOY PERIEXOMENOY THS Stack3.*/
    printf("\nStack3\n");
    TraverseStack(Stack3);

    /*METAFORA TWN STOIXEIWN, APO THN Stack3 STHN Stack1.*/
    i=0;
    while (!EmptyStack(Stack3)){
        Pop(&Stack3,&Item);
        Push(&Stack1, Item);
        i++;
    }

    /*EKTYPWSH TOY PERIEXOMENOY THS Stack1.*/
    printf("\nStack1\n");
    TraverseStack(Stack1);

return 0;
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

/*SYNARTHSH: EMFANISH TOY PERIEXOMENOY THS STOIBAS(Stack).*/
void TraverseStack(StackType Stack)
{
    int i;

    printf("\nPLITHOS STOIXEIWN STH STOIBA: %d\n", Stack.Top+1);

    for (i=0; i<=Stack.Top; i++)
        printf("%c, ", Stack.Element[i]);
        printf("\n");
}
