#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED
#include "structs.h"

data * load_data(FILE *arquivo){
    data * temp = (data*)malloc(sizeof(data));

    fscanf(arquivo,"%s",temp->hora);
    fscanf(arquivo,"%s",temp->minuto);
    fscanf(arquivo,"%s",temp->segundo);
    fscanf(arquivo,"%s",temp->dia);
    fscanf(arquivo,"%s",temp->mes);
    fscanf(arquivo,"%s",temp->ano);

    return temp;
}

int load_users(){
    FILE *arquivo;
    arquivo = fopen("usuarios.txt","r");
    usuario *temp, *aux;
    root = aux = temp = (usuario*)malloc(sizeof(usuario));
    char block[2];
    while(!feof(arquivo)){
        fscanf(arquivo,"%s",temp->nome);
        fscanf(arquivo,"%s",temp->senha);
        fscanf(arquivo,"%s",block);
        fscanf(arquivo,"%s",temp->home);
        if(!strcmp(block,"1"))
            temp->block = 1;
        else
            temp->block = 0;
        aux->prox = temp;
        aux = temp;
        temp = (usuario*)malloc(sizeof(usuario));
    }
    aux->prox = NULL;
    return 0;
}

int load_dir(){
    FILE *arquivo;
    arquivo = fopen("diretorios.txt","r");
    diretorio *temp, *aux;
    char char_temp[16];
    usuario *user_temp;
    root_dir = aux = temp = (diretorio*)malloc(sizeof(diretorio));
    //carrega todos na memória
    while(!feof(arquivo)){
        fscanf(arquivo,"%s",temp->nome);
        aux->prox = temp;
        aux = temp;
        temp = (diretorio*)malloc(sizeof(diretorio));

        user_temp = root;
        fscanf(arquivo,"%s",char_temp);
        while(user_temp!=NULL){
            if(!strcmp(user_temp->nome,char_temp)){
                aux->criador = user_temp;
                break;
            }
            user_temp = user_temp->prox;
        }

        fscanf(arquivo,"%*s %*s %*s %*s %*s %*s %*s %*s %*s %s",char_temp);
        if(!strcmp(char_temp,"1"))
            aux->ishome = 1;
        else
            aux->ishome = 0;
    }
    aux->prox = NULL;

    fclose(arquivo);
    arquivo = fopen("diretorios.txt","r");
    temp = root_dir;
    while(!feof(arquivo)){
        fscanf(arquivo,"%*s %*s %s", char_temp);
        aux = root_dir;
        while(aux!=NULL){
            if(!strcmp(char_temp,aux->nome))
                break;
            aux = aux->prox;
        }
        temp->pai=aux;

        fscanf(arquivo,"%s",char_temp);
        aux = root_dir;
        while(aux!=NULL){
            if(!strcmp(char_temp,aux->nome))
                break;
            aux = aux->prox;
        }
        temp->filho=aux;

        fscanf(arquivo,"%s",char_temp);
        aux = root_dir;
        while(aux!=NULL){
            if(!strcmp(char_temp,aux->nome))
                break;
            aux = aux->prox;
        }
        temp->irmao=aux;

        temp->criacao = load_data(arquivo);
        fscanf(arquivo,"%*s");

        temp=temp->prox;
    }
    return 0;
}

int store_user(){
    FILE *arquivo;
    arquivo = fopen("usuarios.txt","w");
    usuario *temp = root;
    char o[2];

    while(temp!=NULL){
        strcpy(o,"");
        if(temp->prox!=NULL)
            strcpy(o,"\n");
        fprintf(arquivo,"%s %s %d %s%s",temp->nome, temp->senha, temp->block,temp->home, o);
        temp = temp->prox;
    }
    fclose(arquivo);
    return 0;
}
int store_dir(){
    FILE *arquivo;
    arquivo = fopen("diretorios.txt","w");
    diretorio *temp = root_dir;
    char o[3];

    while(temp!=NULL){
        strcpy(o,"");
        if(temp->prox!=NULL)
            strcpy(o,"\n");
        fprintf(arquivo,"%s %s %s %s %s %s %s %s %s %s %s %d%s",temp->nome,temp->criador->nome,temp->pai->nome,temp->filho->nome,temp->irmao->nome,temp->criacao->hora,temp->criacao->minuto,temp->criacao->segundo,temp->criacao->dia,temp->criacao->mes,temp->criacao->ano, temp->ishome, o);
        temp = temp->prox;
    }
    fclose(arquivo);
    return 0;
}

#endif // LOADER_H_INCLUDED
