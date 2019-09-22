#include "structs.h"
#include "processa.h"
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include "loader.h"
#include "login.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    load_users();
    load_dir();

    login();

    store_user();
    store_dir();

    int ver = 1;

    while(ver){
        printf("$");
        char linha_comando[100];
        gets(linha_comando);
        ver = geral(linha_comando) - 1;
    }

    return 0;
}
