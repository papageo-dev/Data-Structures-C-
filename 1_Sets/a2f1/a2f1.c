#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define megisto_plithos 255
#define max_alf 100

/*DOMES/EGGRAFES*/
typedef enum
{
    FALSE, TRUE
}boolean;

typedef boolean typos_synolou[megisto_plithos+1];
typedef int stoixeio_synolou;

/*SYNARTHSEIS/DIADIKASIES*/
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean isValidInteger(char ch[], typos_synolou CharacterSet, typos_synolou DigitSet);
boolean isValidIdentifier(char ch[], typos_synolou LetterSet, typos_synolou DigitSet);

/*KYRIWS PROGRAMMA*/
int main() {

    int i;
    typos_synolou CharacterSet, DigitSet, LetterSet;
    char ch[max_alf], x;

    /*DHMIOURGIA TWN SYNOLWN.*/
    Dimiourgia(CharacterSet);
    Dimiourgia(DigitSet);
    Dimiourgia(LetterSet);

    /*EISAGWGH STOIXEIWN STA SYNOLA.*/
    Eisagogi('+', CharacterSet);
    Eisagogi('-', CharacterSet);

    for (i='0'; i<='9'; i++) {
        Eisagogi(i, DigitSet);
    }
    for (i=65; i<=122; i++) {
        if ((i>=65 && i<=90)||(i>=97 && i<=122)) {
            Eisagogi(i, LetterSet);
        }
    }

    x='Y';
    /*EISAGWGH ALFARITHMITIKWN KAI ELEGXOS EAN EINAI AKERAIOI ARITHMOI(Integers).*/
    while (x=='Y' || x=='y'){
        printf("Insert an Integer Value: ");
        scanf(" %s", ch);
        printf("\n");

        if (isValidInteger(ch, CharacterSet, DigitSet)) {
            printf("Valid Integer!\n");
        }
        else{
            printf("Not a Valid Integer!\n");
        }

        fflush(stdin);

        printf("Want you insert one more Integer Value?(Y/N): ");
        scanf("%c", &x);
        printf("\n");
        while ((x!='N') && (x!='n') && (x!='Y') && (x!='y')){
            printf("Wrong answer... Try again!(Y/N): ");
            scanf("%c", &x);
            printf("\n");
        }
    }

    x='Y';
    /*EISAGWGH ALFARITHMITIKWN KAI ELEGXOS EAN EINAI ANAGNWRISTIKA(Identifiers).*/
    while (x=='Y' || x=='y'){
        printf("Insert an Identifier: ");
        scanf(" %s", ch);
        printf("\n");

         if (isValidIdentifier(ch, LetterSet, DigitSet)) {
            printf("Valid Identifier!\n");
        }
        else{
            printf("Not a Valid Identifier!\n");
        }

        fflush(stdin);

        printf("Want you insert one more Identifier?(Y/N): ");
        scanf("%c", &x);
        printf("\n");
        while ((x!='N') && (x!='n') && (x!='Y') && (x!='y')){
            printf("Wrong answer... Try again!(Y/N): ");
            scanf("%c", &x);
            printf("\n");
        }
    }
return 0;
}


/*SYNARTHSEIS/DIADIKASIES*/
void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 1; i <= megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

/*SYNARTHSH: ELEGXOS AKERAIOY(Integer)*/
boolean isValidInteger(char ch[], typos_synolou CharacterSet, typos_synolou DigitSet)
{
    int i, length;
    boolean flag;

    flag=FALSE;
    length=strlen(ch);

    if (Melos(ch[0], CharacterSet)||Melos(ch[0], DigitSet)){
        for (i=1; i<=length; i++){
            if (Melos(ch[i], DigitSet)){
                flag=TRUE;
            }
            else{
                flag=FALSE;
                break;
            }
        }
    }
    return flag;
}

/*SYNARTHSH: ELEGXOS ANAGNWRISTIKOY(Identifier)*/
boolean isValidIdentifier(char ch[], typos_synolou LetterSet, typos_synolou DigitSet)
{
    int i, length;
    boolean flag;

    flag=FALSE;
    length=strlen(ch);

    if (Melos(ch[0], LetterSet)){
        for (i=1; i<=length; i++){
            if (Melos(ch[i], LetterSet)||Melos(ch[i], DigitSet)||ch[i]=='_'){
                flag=TRUE;
            }
            else if (ch[i]==' '){
                flag=FALSE;
            }
                else{
                    flag=FALSE;
                }
        }
    }
    return flag;
}


