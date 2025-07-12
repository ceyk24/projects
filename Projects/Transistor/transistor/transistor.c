#include <stdio.h>
#include <stdlib.h>
#include "transistor.h"



void initializeTransistor(Transistor_t *transistor)
{
    Data_t a = {0.0,0.0,0.0};
    Transistor_t b = {" ",0,a};

    *transistor = b;

}







void initializeAllTransistors(Transistor_t transistor[],long len)
{
    int i;

    for(i=0;i<len;i++)
    {
        initializeTransistor(&transistor[i]);
    }
}





void printTransistor(Transistor_t transistor)
{
printf("Type : %s\n",transistor.type);
printf("id : %ld\n",transistor.id);
printf("Treshhold : %.2lf\n",transistor.characteristics.vth);
printf("Gate Length : %.2lf\n",transistor.characteristics.L);
printf("Gate Width : %.2lf\n",transistor.characteristics.W);
printf("Oxide Thickness : %.2lf\n",transistor.characteristics.tox);

}




void printAllTransistors(Transistor_t transistor[],long len)
{
    int i;


    for(i=0;i<len;i++)
    {
        //if(transistor[i].characteristics.vth == 0) printf("Transistor[%d] is empty!\n",i);
        printTransistor(transistor[i]);
    }
}



void editTransistor(Transistor_t transistor[],long len,long id)

{




        int i;
        int confirmation;
        char ans;

        for(i=0;i<len;i++)
        {
            if(transistor[i].id == id)
            {
                confirmation = 1;
                break;
            }
        }

        if(confirmation)
        {
            printf("Do you want to change it?(y/n) : ");
            scanf("%c",&ans);
        }



        if (i==len) printf("Insufficient space for Transistor array!\n");

    if(ans == 'y')
    {
        printf("Type: ");
        scanf("%s",transistor[i].type);
    }


}