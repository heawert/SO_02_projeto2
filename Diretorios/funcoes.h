#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <locale.h>
#include <stdio.h>
#include "p_windows.h"
#include "funcoes_usuario.h"
#include "funcoes_diretorio.h"
#include "login.h"


///0 pwd, 1 cd 2 ls 3 mkdir 4 rmdir 5 adduser 6 del 7 lock 8 unlock 9 whoami 10 logoff 11 poweroff 12 showuser 13 help 14 copyright

int geral(char *linha_comando);
int erro(int valor_erro);
int help();

int geral(char *linha_comando){
    parametro *parametros;
    parametros = malloc(sizeof(parametro));
    switch(processa(linha_comando,&parametros)){
        case 0:
            erro(pwd());
            break;
        case 1:
            erro(cd(parametros));
            break;
        case 2:
            erro(ls(parametros));
            break;
        case 3:
            erro(mkdir(parametros));
            break;
        case 4:
            erro(rmdir(parametros));
            break;
        case 5:
            erro(add_user(parametros));
            break;
        case 6:
            erro(del(parametros));
            break;
        case 7:
            erro(lock(parametros));
            break;
        case 8:
            erro(unlock(parametros));
            break;
        case 9:
            erro(whoami());
            break;
        case 10:
            login();
            break;
        case 11:
            return 1;
            break;
        case 12:
            showuser();
            break;
        case 13:
            help();
            break;
        case 14:
            break;
        case 15:
            clear();
            break;
        case P: //imprime mensagem de ajuda
            erro(2);
    }
    return 0;
}

int erro(int valor_erro){
    switch(valor_erro){
        case 0:
            return 0;
        case 1:
            printf("parametros invalido\n");
            break;
        case 2:
            printf("comando inexistente\n");
            break;
        case 3:
            printf("voc� n�o tem permi��o para essa a��o\n");
            break;
        case 4:
            printf("este usu�rio n�o existe\n");
            break;
        case 5:
            printf("este diret�rio n�o existe\n");
            break;
        case 6:
            printf("este diret�rio n�o est� vazio\n");
            break;
        case 7:
            printf("este diret�rio � o diret�rio principal de uma usu�rio\n");
            break;
        printf("n�o � possivel");
        }
        return 0;
}

int help()
{
    printf("pwd:       mostra o diret�rio atual\n");
    printf("cd:        se movimenta para outro diret�rio\n");
    printf("ls:        mostra os sub diret�rios\n");
    printf("mkdir:     cria um novo diret�rio\n");
    printf("rmdir:     remove um diret�rio existente\n");
    printf("adduser:   cria um novo usu�rio\n");
    printf("del:       deleta um usu�rio\n");
    printf("lock:      trava um usu�rio\n");
    printf("unlock:    destrava um usu�rio\n");
    printf("whoami:    mostra o usu�rio atual\n");
    printf("showuser:  mostra todos os usu�rios\n");
    printf("logoff:    desconecta do usu�rio atual\n");
    printf("poweoff:   desliga o sistema\n");
    printf("copyright: mostra os respons�veis pelo projeto\n");
    printf("help:      mostra esse menu\n");
    return 0;
}

#endif // FUNCOES_H_INCLUDED
