#include <stdio.h>
#include <stdlib.h>
#include "Tramite.h"
#include "ArrayList.h"

int main()
{
    /*eTramite* t;
    t=new_Tramite();

    setId(t,5);
    setDni(t,"3333");

    mostrarTramite(t);*/

    int i;
    int opcion;
    int len;
    char dni[10];

    int ultimoIdUrgente = 0;
    int ultimoIdRegular = 0;

    ArrayList* listaRegulares = al_newArrayList();
    ArrayList* listaUrgentes = al_newArrayList();

    ArrayList* atendidosRegulares = al_newArrayList();
    ArrayList* atendidosUrgentes = al_newArrayList();

    eTramite* tramiteActual;

    do
    {
        printf("\n\tMENU\n");
        printf("1.Tramite urgente\n");
        printf("2.Tramite regular\n");
        printf("3.Proximo cliente\n");
        printf("4.Listar pendientes\n");
        printf("5.Informar atendidos\n");
        printf("6.Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            ultimoIdUrgente++;

            printf("Ingrese dni: ");
            fflush(stdin);
            gets(dni);

            cargarTramite(listaUrgentes,ultimoIdUrgente,dni);

            break;
        case 2:
            ultimoIdRegular++;

            printf("Ingrese dni: ");
            fflush(stdin);
            gets(dni);

            cargarTramite(listaRegulares,ultimoIdRegular,dni);
            break;
        case 3:
            if(!listaUrgentes->isEmpty(listaUrgentes))
            {
                printf("Cliente a ser atendido(URGENTE): ");
                atenderTramite(listaUrgentes,atendidosUrgentes);
            }
            else
            {
                 if(!listaRegulares->isEmpty(listaRegulares))
                 {
                     printf("Cliente a ser atendido (REGULAR): ");
                    atenderTramite(listaRegulares,atendidosRegulares);
                 }
                 else
                 {
                     printf("No hay clientes por atender");
                 }
            }

            break;
        case 4:
             if(!listaUrgentes->isEmpty(listaUrgentes))
             {
                printf("TRAMITE URGENTE\n");
                mostrarListaTramites(listaUrgentes);
             }

            if(!listaRegulares->isEmpty(listaRegulares))
            {
                printf("\nTRAMITE REGULAR\n");
                mostrarListaTramites(listaRegulares);
            }
            break;
        case 5:
            if(!atendidosUrgentes->isEmpty(atendidosUrgentes))
             {
                len =atendidosUrgentes->len(atendidosUrgentes);

                atendidosUrgentes->sort(atendidosUrgentes,compararDni,0);
                printf("TRAMITE URGENTE\n");
                for(i=0; i<len;i++)
                {
                    tramiteActual = (eTramite*) atendidosUrgentes->get(atendidosUrgentes,i);
                    mostrarTramite(tramiteActual);
                }
             }

            if(!atendidosRegulares->isEmpty(atendidosRegulares))
            {
                atendidosRegulares->sort(atendidosRegulares,compararDni,0);
                printf("\nTRAMITE REGULAR\n");

                len =atendidosRegulares->len(atendidosRegulares);
                for(i=0; i<len;i++)
                {
                    tramiteActual = (eTramite*) atendidosRegulares->get(atendidosRegulares,i);
                    mostrarTramite(tramiteActual);
                }
            }

            break;
        }
    }while(opcion!=6);

    return 0;
}
