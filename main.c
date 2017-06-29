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
FILE *nfichero;




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
    int i,j,c,n,m,cont=0;
    int marcos[Nmarcos],marcoReemplazado;
    int contadorFifo[Nmarcos],marcoFifo;
    int algoritmo;
    float tasa,hit=0,miss=0;
    //char *cadena;
    //cadena= malloc(30 * sizeof(char));

    rewind(archivo);
    c = fgetc(archivo);
    paginas[0]=0;
    i = 0;
//INICIO - SEPARA LAS FAGINAS
    while(i<Npaginas && c!=-1){

            if(c!=44 ){

                if(paginas[i]==0){
                    paginas[i]=c-48;
                }else{
                    paginas[i]=paginas[i]*10+(c-48);
                }

            }else{
                printf("%d\n",paginas[i]);
                //itoa(paginas[i],cadena,10);
                //cadena=paginas[i];
                //write(nfichero,cadena,strlen(cadena));
                i++;
                paginas[i]=0;
            }
            c = fgetc(archivo);

    }
//FIN - SEPARA LAS FAGINAS
//INICIO - PUEBLA LOS MARCOS
     printf("%d\n",paginas[i]);
     //itoa(paginas[i],cadena,10);

     //write(nfichero,cadena,strlen(cadena));

    for(algoritmo=0;algoritmo<3;algoritmo++){
        cont=0;
        miss=0;
        hit=0;
        switch(algoritmo){
        case 0:
            printf("\nALGORITMO OPTIMO\n");
            //cadena="\nALGORITMO OPTIMO\n";
            //write(nfichero,cadena,strlen(cadena));
            break;
        case 1:
            printf("\nALGORITMO LRU\n");
            //cadena=("\nALGORITMO LRU\n");
            //write(nfichero,cadena,strlen(cadena));
            break;
        case 2:
            printf("\nALGORITMO FIFO\n");
            //cadena=("\nALGORITMO FIFO\n");
            //write(nfichero,cadena,strlen(cadena));
            break;
        case 3:
            printf("\nALGORITMO POLITICAS DE RELOG\n");
            //cadena=("\nALGORITMO POLITICAS DE RELOG\n");
           // write(nfichero,cadena,strlen(cadena));
            break;
        }

        for(i=0;i<Nmarcos;i++){
            marcos[i]=-1;
            contadorFifo[i]=0;
            printf("%d  ",i);
        }
        printf("\n");


        for(i=0;i<Npaginas;i++){
            for(j=0;j<Nmarcos;j++){

                if(marcos[j]==-1){ //Marco vacio - primera vez
                    marcos[j]=paginas[i];
                    cont++;
                    contadorFifo[j]++;
                    hit++;

                    break;
                }else if(marcos[j]==paginas[i]) { //la pagina ya se encuentra en un marco

                    contadorFifo[j]++;
                    hit++;
                    break;

                }else if(cont==Nmarcos){
                    miss++;
                    switch(algoritmo){
                    case 0: //optimo
                        marcos[optimo(&marcos,&paginas,i,Npaginas,Nmarcos)]=paginas[i];
                        break;
                    case 1:
                        marcoFifo=-1;
                        for(m=0;m<Nmarcos;m++){
                            if(contadorFifo[m]>marcoFifo){
                                marcoFifo=contadorFifo[m];
                                marcoReemplazado=m;
                            }
                        }
                        marcos[marcoFifo]=paginas[i];
                        contadorFifo[marcoReemplazado]=1;

                        break;
                    case 2:
                        marcoFifo=contadorFifo[0];
                        for(m=0;m<Nmarcos;m++)
                            if(marcoFifo>contadorFifo[m])
                                marcoFifo=contadorFifo[m];
                        marcos[marcoFifo]=paginas[i];
                        contadorFifo[m]=0;
                        break;
                    case 3:
                        marcos[relog(&marcos,&paginas,i,Npaginas,Nmarcos)]=paginas[i];
                        break;
                    }
                    /*
                    m=j;
                    for(m=j;m>=j;m--)
                        contadorFifo[m]++;
        */
                }else{
                    contadorFifo[j]++;

                }



            }

        //   Muestra Marco
            for(n=0;n<Nmarcos;n++){
                if (marcos[n]!= -1){
                    printf("%d  ",marcos[n]);
                    //cadena=("%d  ",marcos[n]);
                    //write(nfichero,cadena,strlen(cadena));
                }

            }
            printf("\n");
        }
//ALGORITMOS
        tasa=(miss/Npaginas)*100;
        printf("\ntasa miss %.2f%%",tasa);

        //cadena=("\ntasa miss ");
        //write(nfichero,cadena,strlen(cadena));
        //itoa(tasa,cadena,10);
        //write(nfichero,cadena,strlen(cadena));


        tasa=(hit/Npaginas)*100;
        printf("\ntasa hit %.2f%%",tasa);
        //cadena=("\ntasa hit ");
        //write(nfichero,cadena,strlen(cadena));
        //itoa(tasa,cadena,10);
        //write(nfichero,cadena,strlen(cadena));

        printf("\n");
        //cadena=("\n");
        //write(nfichero,cadena,strlen(cadena));
}
        printf("\nALGORITMO OPTIMO\n");
        //cadena=("\nALGORITMO OPTIMO\n");
        //write(nfichero,cadena,strlen(cadena));




}



int main(int argc, char *argv[])
{
    int marcos,pararg,caracter,numeroPaginas=1;
    FILE *archivo;
    // char *cadena;
     //cadena= malloc(30 * sizeof(char));
    while ((pararg=getopt(argc,argv,"m:e:o:")) != -1){

        switch (pararg){
        case 'm':

            marcos=atoi(optarg);
            printf("Numero de Marcos : %d\n",marcos);
            //cadena="Numero de Marcos : ";
            //write(nfichero,cadena,strlen(cadena));
            //itoa(marcos,cadena,10);
            //cadena=marcos;
            //write(nfichero,cadena,strlen(cadena));

        break;
        case 'e':
            archivo=fopen(optarg,"rt");
            if (archivo == NULL){
                printf("\nError de apertura del archivo. \n\n");

            }
            else
            {
                printf("\nEl contenido del archivo de Paginas es \n\n");

                while((caracter = fgetc(archivo)) != EOF)  {
                    putchar(caracter);
                    if (caracter == 44){
                        numeroPaginas++;
                    }


                }
                printf("\nNumero de paginas ingresadas %d \n",numeroPaginas);
                //cadena="\nNumero de paginas ingresadas ";
                //write(nfichero,cadena,strlen(cadena));
                //itoa(numeroPaginas,cadena,10);
                //write(nfichero,cadena,strlen(cadena));
                algoritmosDeReemplazo(numeroPaginas,archivo,marcos);
            }

        break;
        case 'o':

            printf(" Archivo de Salida generado %d\n",nfichero);
            nfichero=open(optarg,O_WRONLY|O_CREAT,0700);
        break;

        }


     }



    printf("\n\n\n\nHello world!\n");
    return 0;
}
