#include "personal.h"
#include <stdlib.h>
#include <stdio.h>


void initializePerson(Person_t *person)
{
  Gehalt_t m = {0.0, 0, 0 ,0} ;
  Person_t muster = {" ",0,0,m};
  *person = muster;

}


void initializeAll(Person_t person[], long len)
{
    int i;

    for(i=0;i<len;i++)
    {
        initializePerson(&person[i]);
    }
}


void printPerson(Person_t person)
{
   printf("Name: %s\n",person.name);
   printf("Department: %ld\n",person.abteilung);
   printf("Tel.No: %ld\n",person.telNr);
   printf("Salary: %.2lf Euro\n",person.gehalt.betrag);
   printf("Income Level: %ld\n",person.gehalt.gehaltsstufe);
   printf("Since: %ld / %ld\n",person.gehalt.jahr,person.gehalt.monat);

    }



void printAllPersons(Person_t person[], long len)
{
    int j;
    int control = 0;

    printf("\n");
    for(j=0;j<len;j++)
    {
        if(person[j].abteilung != 0 )
        {printPerson(person[j]); printf("\n");control++;}
    }
    printf("\n");
    if(control == 0) printf("No Inputs Found!\n");

    printf("%d Inputs are counted!\n",control);
}


void editPerson(Person_t person[], long len, char name[])
{
    int i=100;
    int test = 0;
    long answer;
    int confirmation = 0;


    for(i=0;i<len;i++)
    {
        if(!strcmp(name,person[i].name))
           {
               confirmation = 1;
               printf("Do you want to change this person's details? : \n");
               printf("\t[1] YES\n");
               printf("\t[2] NO\n");
               scanf("%ld",&answer);
               if(answer == 1) test = 1;


           }

    }


    if(confirmation == 0)
    {
        printf("No Matching Name Found!\n\n");

        for(i=0;i<len;i++)
    {
        if(person[i].abteilung > 0) continue;
        else
        {
            printf("New Input!\n");
            answer = 1;
            break;
        }

        if(person[len].abteilung != 0) {printf("There is either no free person-memory or nor matchings found!\n"); return;}
    }

    }



 if(answer == 1)
    {

        printf("Name : ");
        scanf("%s",person[i].name);
        printf("Department : ");
        scanf("%ld",&person[i].abteilung);
        printf("Tel.nr : ");
        scanf("%ld",&person[i].telNr);
        printf("Salary : ");
        scanf("%lf",&person[i].gehalt.betrag);
        printf("Income Level : ");
        scanf("%ld",&person[i].gehalt.gehaltsstufe);
        printf("Year : ");
        scanf("%ld",&person[i].gehalt.jahr);
        printf("Month : ");
        scanf("%ld",&person[i].gehalt.monat);

    }

printf("i = %d\n",i);
    if(test == 1)
    {
    printf("\n*************************\n");
    printf("Edited Person's New Details:\n");
    printf("----------------------------\n");
    printPerson(person[i]);
    printf("\n*************************\n");
    }


}

void readBinaryTransistorData(Person_t person[], long len, char *filename)
{
    int i;

    FILE *input = fopen(filename, "r");

    if(input == 0)
    {
        printf("Failure with reading the file!");
        return;
    }

    for(i=0;i<len;i++)
    {
        fread(&person[i], sizeof(Person_t), 1, input);
    }

    printf("File is read!");
    fclose(input);

}

void writeBinaryTransistorData(Person_t person[], long len, char *filename)
{

    FILE *output = fopen(filename, "w");

    if(output == 0)
    {
        printf("File can not be opened!");
        return;
    }

    fwrite(person, sizeof(Person_t), len, output);
    printf("File is overwritten!");
    fclose(output);
}
