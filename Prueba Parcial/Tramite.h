#include "ArrayList.h"

typedef struct
{
    int idTramite;
    char dni[10];
}eTramite;

eTramite* new_Tramite();

int setId(eTramite*,int);
int getId(eTramite*);

int setDni(eTramite*,char*);
int getDni(eTramite*);

void mostrarTramite(eTramite*);

int compararDni(void* tramiteA,void* tramiteB);

int mostrarListaTramites(ArrayList* listado);

int cargarTramite(ArrayList*,int,char*);

int atenderTramite(ArrayList*, ArrayList*);
