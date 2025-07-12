#define NMAX 30

typedef struct Gehalt_s
{
double betrag;
long gehaltsstufe;
long jahr; // Datum, an dem aktuelle
long monat; // Gehaltstufe erreicht wurde
} Gehalt_t;



typedef struct Person_s
{
char name[40]; // Vor- und Nachname
long abteilung; // Abteilungskennzahl
long telNr;	// Durchwahl
Gehalt_t gehalt;
} Person_t;


void initializePerson(Person_t *person);
void initializeAll(Person_t person[], long len);
void printPerson(Person_t person);
void printAllPersons(Person_t person[], long len);
void editPerson(Person_t person[], long len, char name[]);
void writeBinaryPersonData(Person_t person[], long len,char *filename);
void readBinaryPersonData(Person_t person[], long len, char *filename);
