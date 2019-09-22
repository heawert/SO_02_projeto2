#ifndef FUNCOES_DIRETORIO_H_INCLUDED
#define FUNCOES_DIRETORIO_H_INCLUDED

int pwd();
int cd(parametro *para);
int ls(parametro *para);
int mkdir(parametro *para);
int rmdir(parametro *para);


diretorio * busca_dir(char para[8]){
    diretorio *aux, *temp = root_dir;
    while(temp!=NULL){
        aux = temp;
        while(aux!=NULL){
            if(!strcmp(aux->nome,para))
                return aux;
            aux = aux->irmao;
        }
        temp = temp->filho;
    }
    return NULL;
}

int pwd(){
    printf("%s\n",diretorio_atual->nome);
    return 0;
}

int cd(parametro *para){
    if(para==NULL)
        return 1;
    if(para->prox!=NULL)
        return 1;

    if(!strcmp(para->valor,".."))
        if((diretorio_atual->pai)->criador==usuario_atual||usuario_atual==root){
            diretorio_atual = diretorio_atual->pai;
            return 0;
        }
        else
            return 3;
    diretorio *temp = diretorio_atual->filho;
    while(temp!=NULL){
        if(!strcmp(para->valor,temp->nome)){
            if(temp->criador==usuario_atual||usuario_atual==root){
                diretorio_atual = temp;
                return 0;
            }
            else
                return 3;
        }
        temp = temp->irmao;
    }
    return 5;
}

int ls(parametro *para){
    diretorio *temp = diretorio_atual->filho;
    if(para==NULL){
        while(temp!=NULL){
            printf("%s\n",temp->nome);
            temp = temp->irmao;
        }
        return 0;
    }
    if(para->prox!=NULL)
        return 1;
    if(!strcmp(para->valor,"-l")){
        while(temp!=NULL){
            printf("|N:%16s U:%8s P:%16s F:%16s",temp->nome,temp->criador->nome,temp->pai->nome,temp->filho->nome);
            printf("I:%16s T: %2s:%2s:%2s",temp->irmao->nome,temp->criacao->hora,temp->criacao->minuto,temp->criacao->segundo);
            printf("D: %2s/%2s/20%2s IH:%d\n",temp->criacao->dia,temp->criacao->mes,temp->criacao->ano,temp->ishome);
            temp = temp->irmao;
        }
        return 0;
    }
    return 1;
}

int mkdir(parametro *para){
    if(para==NULL)
        return 1;
    if(para->prox!=NULL)
        return 1;

    diretorio *temp, *aux;
    temp = (diretorio*)malloc(sizeof(diretorio));
    aux = root_dir;
    while(aux->prox!=NULL)
        aux = aux->prox;
    aux->prox = temp;
    strcpy(temp->nome,para->valor);
    temp->pai = diretorio_atual;
    temp->criador = usuario_atual;
    temp->ishome = 0;
    temp->prox = temp->filho = temp->irmao = NULL;
    if(diretorio_atual->filho==NULL)
        diretorio_atual->filho = temp;
    else{
        aux = diretorio_atual->filho;
        while(aux->irmao!=NULL)
            aux = aux->irmao;
        aux->irmao = temp;
    }
    data *temp_data = (data*)malloc(sizeof(data));
    strcpy(temp_data->ano,"00");
    strcpy(temp_data->mes,"00");
    strcpy(temp_data->dia,"00");
    strcpy(temp_data->hora,"00");
    strcpy(temp_data->minuto,"00");
    strcpy(temp_data->segundo,"00");
    temp->criacao = temp_data;

    store_dir();
    return 0;

}

int rmdir(parametro *para){
    if(para==NULL)
        return 1;
    if(para->prox!=NULL)
        return 1;

    diretorio *temp_dir, *aux_dir, *aux2_dir;
    aux_dir = root_dir;
    while(1){
        temp_dir = aux_dir;
        aux_dir = aux_dir->prox;
        if(aux_dir==NULL)
            break;
        if(!strcmp(aux_dir->nome,para->valor)&&diretorio_atual==aux_dir->pai){
            if(aux_dir->filho==NULL)
                if(aux_dir->criador==usuario_atual||usuario_atual==root){
                    if(aux_dir->ishome==0){
                        if(diretorio_atual->filho==aux_dir)
                            diretorio_atual->filho = aux_dir->irmao;
                        else{
                            aux2_dir = diretorio_atual->filho;
                            while(aux2_dir->irmao!=aux_dir)
                                aux2_dir = aux2_dir->irmao;
                            aux2_dir->irmao = aux_dir->irmao;
                        }
                        temp_dir->prox = aux_dir->prox;
                        free(aux_dir);
                        return 0;
                    }
                    return 7;
                }
                else
                    return 3;
            else
                return 6;

        }
    }

    return 5;
}

#endif // FUNCOES_DIRETORIO_H_INCLUDED
