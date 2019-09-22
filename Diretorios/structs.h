#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define debug_mode 1

typedef struct usuarioStruct{
    char nome[8];
    char senha[8];
    int block;
    char home[16];
    struct usuarioStruct *prox;
} usuario;

typedef struct dataStruct{
    char hora[3];
    char minuto[3];
    char segundo[3];
    char dia[3];
    char mes[3];
    char ano[3];
} data;

typedef struct diretorioStruct{
    char nome[16];
    usuario *criador;
    int ishome;
    data *criacao;
    struct diretorioStruct *pai;
    struct diretorioStruct *filho;
    struct diretorioStruct *irmao;
    struct diretorioStruct *prox;
} diretorio;

typedef struct parametroStruct{
    char valor[8];
    struct parametroStruct *prox;
} parametro;

diretorio *diretorio_atual;
diretorio *root_dir;
usuario *usuario_atual;
usuario *root;

#endif // STRUCTS_H_INCLUDED
