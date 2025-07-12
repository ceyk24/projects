#include <stdio.h>
#include <stdlib.h>
#include "personal.h"

int main()
{
    Person_t person[NMAX];
    int choice = 0;
    char search[NMAX];
    char filename[40];

    initializeAll(person, NMAX);

    while (1)
    {
      printf("MENU: \n");
      printf("1: Print to Screen: \n");
      printf("2: Initialize them All! \n");
      printf("3: Edit \n");
      printf("4: Read from a File \n");
      printf("5. Save to a File \n");
      printf("6. Exit \n");

      printf("\tOption:  ");

      scanf("%d",&choice);

      switch(choice)
      {
      case 1:
        printAllPersons(person, NMAX);
        break;

      case 2:
        initializeAll(person, NMAX);
        break;

      case 3:
        printf("Name ? \n");
        scanf("%s",search);
        printf("\n");
        editPerson(person,NMAX,search);
        break;

      case 4:
      printf("Enter a File-Name: ");
      scanf("%s%*c", &filename);
      readBinaryTransistorData(person, NMAX, filename);
      break;

      case 5:
          printf("Enter a File-Name: ");
          scanf("%s%*c", &filename);
          writeBinaryTransistorData(person, NMAX, filename);
          break;


      case 6:
        return 0;

      default:
          printf("Fehlerhafte Eingabe!\n");
          break;



      }
       printf("\n\n");

    }
    return 0;
}
