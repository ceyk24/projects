#include <stdio.h>
#include <stdlib.h>
#include "transistor.c"



int main()
{
    Transistor_t transistor[NMAX];
    int a;
    int a1,a2;
    int tn;
    long n;

do{



    a1 = 0;
    a2 = 0;
    printf("\nMenu\n");
    printf("(1) List one/all Transistors\n");
    printf("(2) Initialize one/all Transistors\n");
    printf("(3) Edit Transistor(s)\n");
    printf("(4) Read the details from a file\n");
    printf("(5) Write to the file\n");
    printf("(7) Exit\n");

    scanf("%d",&a);




    switch(a)
    {

        case 1  :  printf("Want to list one(1) or all(2) Transistor(s)?\n");
                    scanf("%d",&a1);
                   switch (a1)
                   {
                       case 1   :

                           printf("Which transistor? : ");
                           scanf("%d",&tn);
                           printTransistor(transistor[tn]);
                           break;

                       case 2   :

                            printAllTransistors(transistor,NMAX);
                            break;

                    default : break;

                   } break;

                   case 7   : return 0;

                   break;



            case 2  :  printf("Want to initialize one(1) or all(2) Transistor(s)?\n");
                    scanf("%d",&a2);
                   switch (a2)
                   {
                       case 1   :

                           printf("Which transistor? : ");
                           scanf("%d",&tn);
                           initializeTransistor(&transistor[tn]);
                           break;

                       case 2   :

                            initializeAllTransistors(transistor,NMAX);
                            break;

                    default : break;

                   } break;



                       case 3  :

                        printf("Which transistor you wanna edit?:");
                        scanf("%ld",&n);
                        editTransistor(transistor,NMAX,n);
                        break;

            default :   break;

    }

}while(1);}



