#include <stdio.h>
#include <stdlib.h>

#define NMAX 30

typedef struct Data_s
{
    double vth;     // threshold voltage
    double L, W;    // gate length, gate width
    double tox;     // oxide thickness
} Data_t;

typedef struct Transistor_s
{
    char type[30];              // type of transistor
    long id;                    // unique number
    Data_t characteristics;     // device parameter
} Transistor_t;

void initializeTransistor(Transistor_t *transistor);
void initializeAllTransistors(Transistor_t transistor[], long len);
void printTransistor(Transistor_t transistor);
void printAllTransistors(Transistor_t transistor[], long len);
void editTransistor(Transistor_t transistor[], long len, long id);
void writeBinaryTransistorData(Transistor_t transistor[], long len, char *filename);
void readBinaryTransistorData(Transistor_t transistor[], long len, char *filename);

int main()
{
    int input = 0;
    long search;
    char filename[20];

    Transistor_t transistor[NMAX];

    initializeAllTransistors(transistor,NMAX);

    while(1)
    {
        printf("-1- Anzeigen\n");
        printf("-2- Leeren\n");
        printf("-3- Suchen/Bearbeiten\n");
        printf("-4- Sichern\n");
        printf("-5- Einlesen\n");
        printf("-6- Ende\n");
        printf(":");

        scanf("%d%*c", &input);
        printf("\n");

        switch(input)
        {
            case 1:
                printAllTransistors(transistor, NMAX);
                break;

            case 2:
                initializeAllTransistors(transistor, NMAX);
                break;

            case 3:
                printf("Suche nach id: ");
                scanf("%ld%*c", &search);
                printf("\n\n");

                editTransistor(transistor, NMAX, search);
                break;

            case 4:
                printf("Dateiname: ");
                scanf("%s%*c", &filename);

                writeBinaryTransistorData(transistor, NMAX, filename);
                break;

            case 5:
                printf("Dateiname: ");
                scanf("%s", &filename);

                readBinaryTransistorData(transistor, NMAX, filename);
                break;

            case 6:
                return 0;

            default:
                printf("Fehlerhafte Eingabe!\n");

        }

        printf("\n\n");

    }

    return 0;
}

void initializeTransistor(Transistor_t *transistor)
{
    Data_t d = {0.0, 0.0, 0.0, 0.0};

    Transistor_t t = {"", 0, d};

    // Inhalt von transistor mittels * aendern
    *transistor = t;
}

void initializeAllTransistors(Transistor_t transistor[], long len)
{
    int i;

    for(i=0;i<len;i++)
    {
        // Parameter muss ein Pointer auf einen transistor sein
        initializeTransistor(&transistor[i]);
    }
}

void printTransistor(Transistor_t transistor)
{
    printf("Type:\t%s\n",transistor.type);
    printf("id:\t%ld\n",transistor.id);
    printf("Vth:\t%.2lf V\n",transistor.characteristics.vth);
    printf("W x L:\t%.1lf x %.1lf um\n",transistor.characteristics.W, transistor.characteristics.L);
    printf("tox:\t%.1lf nm\n",transistor.characteristics.tox);
}

void printAllTransistors(Transistor_t transistor[], long len)
{
    int i;
    int isEmpty = 1;

    for(i=0;i<len;i++)
    {
        // Ausgabe wenn type nicht leer
        if(transistor[i].type[0] != 0)
        {
            isEmpty = 0;
            printTransistor(transistor[i]);
            printf("\n");
        }
    }

    if(isEmpty == 1)
        printf("Keine Eintraege vorhanden\n");
}

void editTransistor(Transistor_t transistor[], long len, long id)
{

    int i;
    int found = 0;
    char toChange = 'n';

    for(i=0;i<len;i++)
    {
        /* Hinweis
        In der anderen Gruppe sind zwei Strings zu vergleichen. Am besten die
        Funktion strcmp(string1, string2) aus string.h verwenden. Liefert 0
        zuerueck wenn beide Strings gleich sind
        */

        if(transistor[i].id == id)
        {
            found = 1;
            break;
        }
    }

    // i enthaelt jetzt den Index des gefundenen Eintrags


    if(found == 1)
    {
        printf("Eintrag gefunden:\n\n");

        printTransistor(transistor[i]);
        printf("\n");

        printf("Eintrag aendern? [j/n]: ");
        scanf("%c", &toChange);

    }
    else
    {

        for(i=0;i<len;i++)
        {
            if(transistor[i].type[0] == 0)
            {
                toChange = 'j';
                break;
            }

        }

        // i enthaelt jetzt den Index des freien Platzes

        if(i == len)
            printf("Keine freien Plaetze!\n\n");
        else
            printf("Kein Eintrag gefunden. Neuer Eintrag:\n\n");
    }


    if(toChange == 'j')
    {
        printf("Type: ");
        // Kein & Adressoperator da type schon ein Pointer ist
        scanf("%s%*c", transistor[i].type);

        printf("id: ");
        scanf("%lf%*c", &transistor[i].id);

        printf("Vth: ");
        scanf("%lf%*c", &transistor[i].characteristics.vth);

        printf("W: ");
        scanf("%lf%*c", &transistor[i].characteristics.W);

        printf("L: ");
        scanf("%lf%*c", &transistor[i].characteristics.L);

        printf("tox: ");
        scanf("%lf%*c", &transistor[i].characteristics.tox);
    }

}

void writeBinaryTransistorData(Transistor_t transistor[], long len, char *filename)
{
    // Handle auf zu schreibenden Dateistrom
    FILE *output = fopen(filename, "w");

    if(output == 0)
    {
        printf("Konnte Datei nicht oeffnen//anlegen\n");
        return;
    }

    // Anfangsadresse des Feldes, Groesse eines Elementes, Anzahl der Elemente, Ausgabestrom
    fwrite(transistor, sizeof(Transistor_t), len, output);

    fclose(output);
}

void readBinaryTransistorData(Transistor_t transistor[], long len, char *filename)
{
    int i;

    // Handle auf zu lesenden Dateistrom
    FILE *input = fopen(filename, "r");

    if(input == 0)
    {
        printf("Datei nicht gefunden\n");
        return;
    }

    for(i=0;i<len;i++)
    {
        // Adressposition im Feld, Groesse eines Elementes, Anzahl der Elemente, Einlesestrom
        fread(&transistor[i], sizeof(Transistor_t), 1, input);
    }

    fclose(input);

}
