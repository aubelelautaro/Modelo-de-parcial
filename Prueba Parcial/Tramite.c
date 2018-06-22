#include <stdio.h>
#include <stdlib.h>
#include "Tramite.h"

eTramite* new_Tramite()
{
    eTramite* aux;

    aux = (eTramite*) malloc(sizeof(eTramite));

    return aux;
}

int setId(eTramite* this,int id)
{
    int seteo = -1;

    if(this!= NULL)
    {
        this->idTramite = id;
        seteo = 0;
    }
    return seteo;
}

int getId(eTramite* this)
{
    int id = -1;
    if(this!=NULL)
    {
        id = this->idTramite;
    }
    return id;
}

int setDni(eTramite* this,char* dni)
{
    int seteo=-1;
    if(this!=NULL && dni!=NULL)
    {
        strcpy(this->dni, dni);
        seteo =0;
    }
    return seteo;
}
int getDni(eTramite* this)
{
    char* dni=NULL;
    if (this!= NULL)
    {
        dni = this->dni;
    }
    return dni;

}

void mostrarTramite(eTramite* this)
{
    int mostro = -1;
    if (this != NULL)
    {
        printf("%d--%s\n", getId(this), getDni(this));
        mostro = 0;
    }
    return mostro;
}

int compararDni(void* tramiteA, void* tramiteB)
{
    eTramite* tramite1 = (eTramite*) tramiteA;
    eTramite* tramite2 = (eTramite*) tramiteB;

    return strcmp(tramite1->dni, tramite2->dni);
}

int mostrarListaTramites(ArrayList* listado)
{
    int listo = -1;
    int i;
    int len;
    eTramite* tramiteActual;

    if(listado!=NULL)
    {
        len = listado->len(listado);
        for(i=0;i<len; i++)
        {
            tramiteActual = (eTramite*) listado->get(listado, i);
            mostrarTramite(tramiteActual);
        }
        listo = 0;
    }
    return listo;
}

int cargarTramite(ArrayList* listado, int id, char* dni)
{
    int cargo =-1;
    eTramite* tramiteActual;

    if (listado != NULL && id > 0 && dni != NULL)
    {
        tramiteActual = new_Tramite();

        setId(tramiteActual, id);
        setDni(tramiteActual,dni);

        listado->add(listado,tramiteActual);
        cargo = 0;
    }
    return cargo;
}

int atenderTramite(ArrayList* listaPendientes, ArrayList* listaAtendidos)
{
    int atendio = -1;
    eTramite* tramiteActual;
    if(listaPendientes !=NULL && listaAtendidos != NULL)
    {
        tramiteActual = (eTramite*) listaPendientes->pop(listaPendientes, 0);

        listaAtendidos->add(listaAtendidos,tramiteActual);
        printf("Cliente a ser atendido: ");

        mostrarTramite(tramiteActual);
    }
}
