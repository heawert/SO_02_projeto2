#ifndef GERENCIADOR_H_INCLUDED
#define GERENCIADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include "structs.h"
#include "processa.h"
int processa();
#include "funcoes.h"
int geral(char *linha_comando);
int erro(int valor_erro);
int help();
#include "p_windows.h"
int clear();
int pause();
#include "funcoes_usuario.h"
int whoami();
int add_user(parametro *para);
int del(parametro *para);
int lock(parametro *para);
int unlock(parametro *para);
int showuser();
int logoff();
#include "funcoes_diretorio.h"
int pwd();
int cd(parametro *para);
#include "loader.h"
data * load_data(FILE *arquivo);
int load_users();
int load_dir();
int store_user();
int store_dir();
#include "login.h"
int login();








#endif // GERENCIADOR_H_INCLUDED
