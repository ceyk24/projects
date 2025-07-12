#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{

    double a,b;
    double r, res;
    int c;




  do{

    printf(" ");
    printf("Geben Sie welche option Sie wollen:\n");
    printf("(1) Kartesisch -> Polar\n");
    printf("(2) Polar -> Kartesisch\n");
    printf("(3) Exit\n");

    scanf("%d",&c);

   if (c == 1)
        {

    printf("Geben Sie bitte die reele Teil Zahl 1 ein : ");
    scanf("%lf",&a);

    printf("Geben Sie bitte die Imaginaere Zahl 2 ein : ");
    scanf("%lf",&b);

    r = sqrt(a*a+b*b);

    res = atan(b/a) * 180 / PI;

    printf("r ist %g\n", r);
    printf("Winkel ist %g\n", res);
    printf("------------------\n");

    }

    if(c == 2){

    printf("Geben Sie bitte den Radius ein : ");
    scanf("%lf",&r);

    printf("Geben Sie bitte den Winkel ein : ");
    scanf("%lf",&res);

    a = 2 * cos(res*PI/180);
    b = 2 * sin(res*PI/180);

    printf("Die Kartesische Darstellung lautet als %.2lf + %.2lfi\n", a,b);
    printf("------------------\n");


    }}while(c != 3);

    return 0;
}

