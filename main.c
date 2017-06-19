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
Guithub:https://github.com/jaimeolivaresvalenzuela/AlgoritmosDeReemplazo
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
//int *matriz;
int main(int argc, char *argv[])
{
    int marcos,pararg,fichero,caracter;
    FILE *archivo;
    char *pagina;
     while ((pararg=getopt(argc,argv,"m:e:o:")) != -1){

        switch (pararg){
        case 'm':

            marcos=atoi(optarg);
            printf("%d\n",marcos);

        break;
        case 'e':
            archivo=fopen(optarg,"rt");
            if (archivo == NULL){
                printf("\nError de apertura del archivo. \n\n");
            }
            else
            {
                printf("\nEl contenido del archivo de prueba es \n\n");
                while((caracter = fgetc(archivo)) != EOF)  {
                    printf("%c",caracter);
                }
            }

        break;
        case 'o':

        break;

        }


     }



    printf("Hello world!\n");
    return 0;
}
