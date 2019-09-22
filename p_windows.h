#ifndef P_WINDOWS_H_INCLUDED
#define P_WINDOWS_H_INCLUDED

#include <stdio.h>
#include "structs.h"

int clear(){
    system("cls");
    if(debug_mode){
        diretorio *temp = root_dir;
        printf("Você esté no mode de debug\n");
        while(temp!=NULL){
            printf("|N:%16s U:%8s P:%16s F:%16s",temp->nome,temp->criador->nome,temp->pai->nome,temp->filho->nome);
            printf("I:%16s T: %2s:%2s:%2s",temp->irmao->nome,temp->criacao->hora,temp->criacao->minuto,temp->criacao->segundo);
            printf("D: %2s/%2s/20%2s IH:%d\n",temp->criacao->dia,temp->criacao->mes,temp->criacao->ano,temp->ishome);
            temp = temp->prox;
        }
        usuario *temp2 = root;
        while(temp2!=NULL){
            printf("|U: %8s S:%8s B:%d H:%16s\n",temp2->nome,temp2->senha,temp2->block,temp2->home);
            temp2 = temp2->prox;
        }
    }
    return 0;
}

int pause(){
    system("pause");
    return 0;
}


#endif // P_WINDOWS_H_INCLUDED
