#include <stdio.h>
#include <math.h>

int main ()
{
int choice1;
int uchoice1;
double a,b,res;


do
{


printf("Waehlen Sie eine Option : \n");
printf("\n");
printf("\t1 ... Taschenrechner\n");
printf("\t2 ... Wissenschaftlichenrechner\n");
printf("\t-------------------------------\n");
printf("\t3 ... (E)EXIT\n");
printf("\n");
printf("Ihre Wahl : ");
scanf("%d",&choice1);

if (choice1 == 1)
{

 printf("\n");
 printf("Taschenrechner\n");
 printf("\n");
 printf("Waehlen Sie eine Option : ");
 printf("\n");
 printf("\t1 ... (+)Addieren\n");
 printf("\t2 ... (-)Substrahieren\n");
 printf("\t3 ... (*)Multiplieren\n");
 printf("\t4 ... (/)Dividieren\n");
 printf("\n");
 printf("Ihre Wahl : ");
 scanf("%d",&uchoice1);

 switch(uchoice1){
    case (1) :
                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl ein : ");
                scanf("%lf",&b);

                res = a + b;

                printf("%g + %g =  %g",a,b,res);
                break;

    case (2) :

                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl ein : ");
                scanf("%lf",&b);

                res = a - b;

                printf("%g - %g =  %g",a,b,res);
                break;

    case (3) :

                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl ein : ");
                scanf("%lf",&b);

                res = a * b;

                printf("%g * %g =  %g",a,b,res);
                break;

    case (4) :


                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl bzw. Nenner ein : ");
                scanf("%lf",&b);

            do{
                printf("\n");
                printf("**************************************************\n");
                printf("******* Hinweis: Nenner darf nicht 0 sein! *******\n");
                printf("**************************************************\n");
                printf("\n");

                printf("Geben Sie die zweite Zahl bzw. Nenner nochmal ein : ");
                scanf("%lf",&b);} while(b==0);

                res = a / b;

                printf("%g / %g =  %g",a,b,res);
                break;

    default : break;




 }
}
if (choice1 == 2){


 printf("\n");
 printf("Wissenschaftlichenrechner\n");
 printf("\n");
 printf("Waehlen Sie eine Option : ");
 printf("\n");
 printf("\t1 ... (+)Addieren\n");
 printf("\t2 ... (-)Substrahieren\n");
 printf("\t3 ... (*)Multiplieren\n");
 printf("\t4 ... (/)Dividieren\n");
 printf("\t5 ... (s)Square root\n");
 printf("\t6 ... (sinus)Sinus Funktion\n");
 printf("\t7 ... (pow)Power Funktion\n");
 printf("\n");
 printf("Ihre Wahl : ");
 scanf("%d",&uchoice1);

 switch(uchoice1){
    case (1) :
                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl ein : ");
                scanf("%lf",&b);

                res = a + b;

                printf("%g + %g =  %g",a,b,res);
                break;

    case (2) :

                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl ein : ");
                scanf("%lf",&b);

                res = a - b;

                printf("%g - %g =  %g",a,b,res);
                break;

    case (3) :

                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl ein : ");
                scanf("%lf",&b);

                res = a * b;

                printf("%g * %g =  %g",a,b,res);
                break;

    case (4) :


                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl bzw. Nenner ein : ");
                scanf("%lf",&b);

            do{
                printf("\n");
                printf("**************************************************\n");
                printf("******* Hinweis: Nenner darf nicht 0 sein! *******\n");
                printf("**************************************************\n");
                printf("\n");

                printf("Geben Sie die zweite Zahl bzw. Nenner nochmal ein : ");
                scanf("%lf",&b);} while(b==0);

                res = a / b;

                printf("%g / %g =  %g",a,b,res);
                break;


    case (5) :

                printf("Geben Sie die Zahl ein : ");
                scanf("%lf",&a);

                res = sqrt(a);

                printf("Squareroot von %g = %g\n",a,res);
                break;

    case (6) :

                printf("Geben Sie den Winkel ein : ");
                scanf("%lf",&a);

                res = sin(a*M_PI/180);
                printf("Sinus(%g) = %g\n",a,res);
                break;

    case (7) :

                printf("Geben Sie die erste Zahl ein : ");
                scanf("%lf",&a);
                printf("Geben Sie die zweite Zahl bzw. Power ein : ");
                scanf("%lf",&b);

                res = pow(a,b);
                printf("%g%s%g = %g\n",a,"^",b,res);
                break;


    default : break;




 }}
if (choice1 == 3) {return 0;}

} while (choice1 != 1 && choice1 != 2 && choice1 !=3) ;

return 0;
}
