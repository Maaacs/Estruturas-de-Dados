#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
#include "lista.h"
#include "ddinamico.h"

struct ddinamico{
    // dados
    int tamanho;
    int nro_elementos; //numero de elementos (ocupacao)

    TListaSE* *entradas; // vetor dinamico de ponteiros para listas encadeadas
    // estatística

    int nro_consulta;
    int nro_busca;
    int nro_insercao;
    long int nro_cmps_por_rmc;
    long int nro_cmps_por_bsc;
};

static int hashing(TDDinamico* dd, int chave){
    return (chave % dd->tamanho);
}

static int primo_proximo(int num){
    short encontrou = 0;
    while(!encontrou){
        int i=2;
        while((i<num) && ((num%i)!=0)){
            i++;
        }
        if(i == num){
            encontrou=1;
        }else{
            num+=1;
        }
    }
    return num;
}

TDDinamico* criar_DD(int tamanho, TCompararDD comparar){
    TDDinamico* dd = malloc(sizeof(TDDinamico));

    dd->tamanho = primo_proximo(tamanho);
    dd->nro_elementos = 0;
    dd->entradas = malloc(sizeof(TListaSE*)*dd->tamanho); //multiplica pelo tamanho /sizeof de ponteiro (TListaSE)
    
    for(int i=0; i<dd->tamanho; i++){
        dd->entradas[i] = criarLSE(NULL,NULL);
        //dd->entradas[i] = criarLSE(NULL, comparar);//se quiser comparar
    }
    dd->nro_busca = dd->nro_consulta = dd->nro_insercao = 0;
    dd->nro_cmps_por_bsc = dd->nro_cmps_por_rmc = 0;

    return dd;
}

typedef struct entrada{
    int chave;
    void* info;
}TEntradaDD;

TEntradaDD* criar_entrada_DD(int chave, void* info){ //retorna ponteiro
    TEntradaDD* e = malloc(sizeof(TEntradaDD));
    e->chave = chave;
    e->info = info;

    return e;
}

void inserir_DD(TDDinamico *dd, int chave, void* info){
    int k = hashing(dd, chave);
    TListaSE* l =  dd->entradas[k];
    inserirInicioLSE(l, criar_entrada_DD(chave, info));
}

void* buscar_DD(TDDinamico *dd, int chave){

  return NULL;
}

void* remover_DD(TDDinamico *dd, int chave){
  return NULL;
}