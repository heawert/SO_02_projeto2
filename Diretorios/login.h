#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <stdio.h>
#include "funcoes_diretorio.h"

char erros_l[3][100] = {"usuário não existe", "senha incorreta", "usuário bloqueado"};

int login(){
    while(1){
        clear();
        char user[9], senha[9];
        usuario *temp;
        temp = root;
        int erro_l;

        printf("Usuário: ");
        scanf("%s",user);
        printf("Senha: ");
        scanf("%s",senha);
        getchar();

        while(temp!=NULL){
            if(!strcmp(user,temp->nome))
                if(!strcmp(senha,temp->senha))
                    if(!temp->block){
                        clear();
                        diretorio_atual = busca_dir(temp->home);
                        usuario_atual = temp;
                        return 0;
                    }
                    else{
                        erro_l = 2;
                        break;
                    }
                else
                {
                    erro_l = 1;
                    break;
                }
            else
                erro_l = 0;
            temp = temp->prox;
        }
        printf("%s\n",erros_l[erro_l]);
        pause();
    }
}

#endif // LOGIN_H_INCLUDED
