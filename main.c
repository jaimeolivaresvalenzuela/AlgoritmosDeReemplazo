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

int lru(int *marcos,int *paginas,int ultimaPaginaInsertada,int Npaginas, int Nmarcos){

}
int fifo(int *marcos,int *paginas,int ultimaPaginaInsertada,int Npaginas, int Nmarcos){
}
int relog(int *marcos,int *paginas,int ultimaPaginaInsertada,int Npaginas, int Nmarcos){
}
int optimo(int *marcos,int *paginas,int ultimaPaginaInsertada,int Npaginas, int Nmarcos){
int marco[Nmarcos];
int j,n,paginaEnMarco,pocicion,marcoMayor;




    for(n=0;n<Nmarcos;n++){
        paginaEnMarco=marcos[n];
        marco[n]=0;
        for(j=ultimaPaginaInsertada;j<Npaginas;j++){



            if(paginas[j]!=paginaEnMarco){
                marco[n]++;
            }else{
                break;
            }

        }
    }
    marcoMayor=marco[0];
    pocicion=0;
    for(n=1;n<Nmarcos;n++){
        if (marco[n]>marcoMayor){
            marcoMayor=marco[n];
            pocicion=n;
        }
    }
    if(ultimaPaginaInsertada+1==Npaginas){
        pocicion=3;

    }

return(pocicion);

}
void algoritmosDeReemplazo(int Npaginas,FILE *archivo,int Nmarcos ){
    int paginas[Npaginas];
    int i,j,c,n,cont=0;
    int marcos[Nmarcos];
    int conatado[Nmarcos];
    int algoritmo;
    rewind(archivo);
    c = fgetc(archivo);
    paginas[0]=0;
    i = 0;

    while(i<Npaginas && c!=-1){

            if(c!=44 ){

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

     printf("%d\n",paginas[i]);
    for(algoritmo=0;algoritmo<3;algoritmo++){
        switch(algoritmo){
        case 0:
            printf("\nALGORITMO OPTIMO\n");
            break;
        case 1:
            printf("\nALGORITMO LRU\n");
            break;
        case 2:
            printf("\nALGORITMO FIFO\n");
            break;
        case 3:
            printf("\nALGORITMO POLITICAS DE RELOG\n");
            break;
        }

        for(i=0;i<Nmarcos;i++){
            marcos[i]=-1;
            printf("%d  ",i);
        }
        printf("\n");
        for(i=0;i<Npaginas;i++){
            for(j=0;j<Nmarcos;j++){

                if(marcos[j]==-1){
                    marcos[j]=paginas[i];
                    cont++;
                    break;
                }else if(marcos[j]==paginas[i]) {
                    break;

                }else if(cont==Nmarcos){

                    switch(algoritmo){
                    case 0: //optimo
                        marcos[optimo(&marcos,&paginas,i,Npaginas,Nmarcos)]=paginas[i];
                        break;
                    case 1:
                        marcos[lru(&marcos,&paginas,i,Npaginas,Nmarcos)]=paginas[i];
                        break;
                    case 2:
                        marcos[fifo(&marcos,&paginas,i,Npaginas,Nmarcos)]=paginas[i];
                        break;
                    case 3:
                        marcos[relog(&marcos,&paginas,i,Npaginas,Nmarcos)]=paginas[i];
                        break;
                    }

                }
            }

        //   Muestra Marco
            for(n=0;n<Nmarcos;n++){
                if (marcos[n]!= -1){
                    printf("%d  ",marcos[n]);
                }

            }
            printf("\n");
        }
//ALGORITMOS
}
   printf("\nALGORITMO OPTIMO\n");




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
                algoritmosDeReemplazo(numeroPaginas,archivo,marcos);
            }

        break;
        case 'o':

        break;

        }


     }



    printf("\n\n\n\nHello world!\n");
    return 0;
}
