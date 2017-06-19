/**
UNIVERSIDAD DE SANTIAGO DE CHILE
Facultad de Ingeniería
Departamento Ingeniería Informática
Carrera: Ingenierí De Ejecucion en Informatica
Plan: Vespertino
Tercer Laboratorio de Sistema operativo
Proyecto: Algoritmos de reemplazo.
Autor: Jaime Olivares
Rut: 15467207-9
Fecha: 2017-06-19
Profesor:   Fernando Rannou (fernando.rannou@usach.cl)
            Miguel Caarcamo (miguel.carcamo@usach.cl)
Ayudante: Natalia Perez (natalia.perez.g@usach.cl)
Guithub:https://github.com/jaimeolivaresvalenzuela/AlgoritmoDeReemplazo
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int *matriz
int main(int argc, char *argv[])
{
    int marcos,pararg,fichero;

     while ((pararg=getopt(argc,argv,"m:e:o:")) != -1){

        switch (pararg){
        case 'm':

            marcos=atoi(optarg);
            printf("%d\n",marcos);

        break;
        case 'e':

            fichero=open(optarg,O_RDONLY,0644);
            printf("%d\n",fichero);
            matriz=(int*)malloc(sizeof(int)*atoi(optarg)

        break;
        case 'o':

        break;

        }


     }



    printf("Hello world!\n");
    return 0;
}
