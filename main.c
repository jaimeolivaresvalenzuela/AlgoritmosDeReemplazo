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
#include <windows.h>
//int *matriz;


void algoritmosDeReemplazo(int Npaginas,FILE *archivo ){
int paginas[Npaginas];
//char * buffer = NULL;
  int i, c;
  rewind(archivo);
  c = fgetc(archivo);
  paginas[0]=0;
  i = 0;
  while(!feof(archivo))
    {
      //buffer = (char*)realloc(NULL, sizeof(char));

      while( c != '\n')
        {
        if(c!=44){
            if(paginas[i]==0){
                paginas[i]=c-48;


            }else{
                paginas[i]=paginas[i]*10+(c-48);
            }
        }else{
        printf("%d\n",paginas[i]);
        i++;
        paginas[i]=0;

        }
          c = fgetc(archivo);
        }



    }

}



int main(int argc, char *argv[])
{
    int marcos,pararg,caracter,numeroPaginas=1;
    FILE *archivo;


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
                printf("\nEl contenido del archivo de Paginas es \n\n");
                printf("%c\n",caracter);
                while((caracter = fgetc(archivo)) != EOF)  {

                    if (caracter == 44){
                        numeroPaginas++;
                    }


                }
                printf("Numero de paginas ingresadas %i \n",numeroPaginas);
                algoritmosDeReemplazo(numeroPaginas,archivo);
            }

        break;
        case 'o':

        break;

        }


     }



    printf("Hello world!\n");
    return 0;
}
