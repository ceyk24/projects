
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define Textlen 100



void getline1(char str[],long num);
long numofletters(char str[]);
long numofcharacters(char str[]);


int main()
{

    long length[11]={0,0,0,0,0,0,0,0,0,0,0};
    char text[Textlen];
    printf("Enter a text: ");
    getline1(text,Textlen);
    printf("Girilen deger : %s\n",text);


    printf("Girilen textin uzunlugu : %ld\n",strlen(text));

    long pos = 0;
    long tl = 0;
    long tk = 0;
    long tw = 0;

    while(text[pos])
    {

        tl = numofletters(&text[pos]);
        tk = numofcharacters(&text[pos+tl]);
        if(tl <11 && tl >0) length[tl]++;
        printf("At that %ld position %ld letters and %ld characters are counted!\n",pos, tl,tk);
        pos = pos + tl + tk;
        printf("Next position is %ld\n",pos);


        tw++;


    }


    printf("The number of the found words: %ld\n",tw);
    printf("----------------\n");


int j;
        for(j=0;j<11;j++)
       printf("%ld harften olusan kelime sayisi %ld\n",j,length[j]);


    return 0;
}


void getline1(char str[],long num)
{
 char c, *strend = str + num - 1, *strtemp = str;


 while(1)
 {

     c = getchar();
     if(c == '\n') {*strtemp = 0; break;}
     if(strtemp < strend) {*strtemp = c; strtemp++;}
     else {
        printf("Limitten fazla karakter girisi oldu!\n");
        *strtemp=str;
        while(getchar() != '\n');

     }

 }


}


long numofletters(char str[])
{
    long c = 0;
    int i = 0;

    for(i;strlen(str);i++)

        if(isalpha(str[i])) c++;
        else break;


    return c;

}

long numofcharacters(char str[])
{
    long c = 0;
    int i = 0;

    for(i;strlen(str);i++)

        if(!isalpha(str[i])) c++;
        else break;


    return c;

}
