#include <stdio.h>
#include <math.h>

/*SYNARTHSEIS/DIADIKASIES*/
void createPowerSet(char set[], int size);

/*KYRIWS PROGRAMMA*/
int main(){

    char set[] = {1,2,3,4,5};

    /*DHMIOYRGIA KAI EKTYPWSH DYNAMOSYNOLOY, GIA N=5.*/
    printf("TO DYNAMOSYNOLO GIA N=5: \n");
    createPowerSet(set, 5);

    return 0;
}

/*SYNARTHSH: DHMIOYRGIA KAI EKTYPWSH DYNAMOSYNOLOY.*/
void createPowerSet(char set[], int size)
{
    int i, j;
    int pow_set_size;

    /*KLHSH THS SYNARTHSHS pow(), GIA NA EPISTRAFEI TO APOTELESMA TOY 5^2.*/
    pow_set_size = pow(2, size);

    for(i=0; i<pow_set_size; i++){
        for(j=0; j<size; j++){
            if(i & (1<<j)){
                printf("%d", set[j]);
            }
       }
       printf("\n");
    }
}
