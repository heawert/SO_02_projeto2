#ifndef FUNCOES_USUARIO_H_INCLUDED
#define FUNCOES_USUARIO_H_INCLUDED
#include "loader.h"

int whoami();
int add_user(parametro *para);
int del(parametro *para);
int lock(parametro *para);
int unlock(parametro *para);
int showuser();
int logoff();

int whoami()
{
    printf("%s\n",usuario_atual->nome);
    return 0;
}

int add_user(parametro *para){
    usuario *temp, *aux;



    if(usuario_atual!=root)
        return 3;
    if(para==NULL)
        return 1;
    if(para->prox==NULL)
        return 1;
    if(para->prox->prox!=NULL)
        return 1;



    temp = (usuario*)malloc(sizeof(usuario));
    strcpy(temp->nome,para->valor);
    strcpy(temp->senha,para->prox->valor);
    temp->block = 0;
    temp->prox = NULL;

    aux = root;
    while(aux->prox!=NULL)
        aux = aux->prox;
    aux->prox = temp;


    diretorio * temp_dir, *aux_dir;
    char char_temp[20]; strcpy(char_temp,"_home");
    temp_dir = (diretorio*)malloc(sizeof(diretorio));
    strcpy(temp_dir->nome,para->valor);
    strcat(temp_dir->nome,char_temp);
    strcpy(temp->home,temp_dir->nome);
    temp_dir->pai = root_dir;
    temp_dir->filho = NULL;
    temp_dir->irmao = NULL;
    temp_dir->ishome = 1;
    temp_dir->criador = temp;
    if(root_dir->filho!=NULL){
        aux_dir = root_dir->filho;
        while(aux_dir->irmao!=NULL)
            aux_dir = aux_dir->irmao;
        aux_dir->irmao = temp_dir;
    }
    else
        root_dir->filho = temp_dir;
    aux_dir = root_dir;
    while(aux_dir->prox!=NULL)
        aux_dir = aux_dir->prox;
    aux_dir->prox = temp_dir;
    temp_dir->prox = NULL;
    data *temp_data = (data*)malloc(sizeof(data));
    strcpy(temp_data->ano,"00");
    strcpy(temp_data->mes,"00");
    strcpy(temp_data->dia,"00");
    strcpy(temp_data->hora,"00");
    strcpy(temp_data->minuto,"00");
    strcpy(temp_data->segundo,"00");
    temp_dir->criacao = temp_data;



    if(debug_mode)
        clear();

    store_user();
    store_dir();

    return 0;
}

int del(parametro *para){
    usuario *temp, *aux;



    if(usuario_atual!=root)
        return 3;
    if(para==NULL)
        return 1;
    if(para->prox!=NULL)
        return 1;

    if(root->prox!=NULL){
        temp = root;
        aux = root->prox;
        while(strcmp(aux->nome,para->valor)){
            temp = aux;
            aux = aux->prox;
            if(aux==NULL)
                return 4;
        }
        pause();
        temp->prox = aux->prox;


        diretorio *temp_dir, *aux_dir, *aux2_dir;
        aux_dir = root_dir;
        while(1){
            temp_dir = aux_dir;
            aux_dir = aux_dir->prox;
            if(aux_dir==NULL)
                break;
            if(!strcmp(aux_dir->criador->nome,aux->nome)){
                if(aux_dir->pai->filho==aux_dir)
                    aux_dir->pai->filho = aux_dir->irmao;
                else{
                    aux2_dir = aux_dir->pai->filho;
                    while(aux2_dir->irmao!=aux_dir)
                        aux2_dir = aux2_dir->irmao;
                    aux2_dir->irmao = aux_dir->irmao;
                }

                temp_dir->prox = aux_dir->prox;
            }
        }


        free(aux);

        store_user();
        store_dir();
        if(debug_mode)
            clear();

        return 0;
    }
    return 4;
}

int lock(parametro *para){
    if(root->prox==NULL)
        return 4;
    usuario *aux = root->prox;
    while(strcmp(aux->nome,para->valor)){
            aux = aux->prox;
            if(aux==NULL)
                return 4;
        }
    aux->block = 1;
    if(debug_mode)
        clear();
    store_user();
    return 0;
}

int unlock(parametro *para){
    if(root->prox==NULL)
        return 4;
    usuario *aux = root->prox;
    while(strcmp(aux->nome,para->valor)){
            aux = aux->prox;
            if(aux==NULL)
                return 4;
        }
    aux->block = 0;
    if(debug_mode)
        clear();
    store_user();
    return 0;
}

int showuser(){
    usuario *temp;
    temp = root;
    while(temp!=NULL){
        printf("%s %s %d\n",temp->nome, temp->senha, temp->block);
        temp = temp->prox;
    }
    return 0;
}

#endif // FUNCOES_USUARIO_H_INCLUDED
