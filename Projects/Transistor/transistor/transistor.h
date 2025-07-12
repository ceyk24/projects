#define NMAX 30

typedef struct Data_s
{
    double vth, L, W, tox;
}Data_t;


typedef struct Transistor_s
{
    char type[NMAX];
    long id;
    Data_t characteristics;

}Transistor_t;



void initializeTransistor(Transistor_t *transistor);
void initializeAllTransistors(Transistor_t transistor[],long len);

void printTransistor(Transistor_t transistor);
void printAllTransistors(Transistor_t transistor[],long len);

void editTransistor(Transistor_t transistor[],long len,long id);