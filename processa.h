#ifndef PROCESSA_H_INCLUDED
#define PROCESSA_H_INCLUDED
#include <string.h>
#include <stdlib.h>


#define P 20
char comandos[P][10] = {"pwd","cd","ls","mkdir","rmdir","adduser","del","lock","unlock","whoami","logoff","poweroff","showuser","help","copyright","clear"};


int processa(char *linha_comando, parametro **parametros){
		char *comando;
		int i;
		parametro *temp, *aux = NULL;

		comando = strtok(linha_comando," ");
		if(comando!=NULL){
            for(i=0;i<P;i++)
                if (strcmp(comando,comandos[i]) == 0)
                    break;
		}
        else{
            *parametros = NULL;
            return P;
        }


        while(1){
            comando = strtok(NULL," ");
            if(comando!=NULL){
                temp = (parametro*)malloc(sizeof(parametro));
                if(aux!=NULL)
                    aux->prox = temp;
                else
                    *parametros = temp;
                strcpy(temp->valor,comando);
                temp->prox = NULL;
                aux = temp;
            }
            else{
                if(aux==NULL)
                    *parametros = NULL;
                break;
            }
        }
        return i;
}


#endif // PROCESSA_H_INCLUDED
