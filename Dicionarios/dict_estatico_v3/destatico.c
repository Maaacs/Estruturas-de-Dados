#include "destatico.h"
#include "stdlib.h"
#include "stdio.h"

// TEntradaDic criar_entrada(int chave, void* info){
//   TEntradaDic e;// = malloc(sizeof(TEntradaDic));
//   e.chave = chave;
//   e.info = info;
//   return e;
// }

struct estatistica{
  int nro_cmp;
  int nro_bsc;
};

struct destatico{
    void* *entradas;
    int tamanho;
    int ocupacao;
    TCompararDE comparar;
    struct estatistica;
};

TDEstatico* criar_DE(int tamanho, TCompararDE comparar){
    TDEstatico *de = malloc(sizeof(TDEstatico));
    de->tamanho = tamanho;
    de->ocupacao = 0;
    de->comparar = comparar;

    de->entradas = malloc(sizeof(void*)*de->tamanho);

    return de;
}

void* buscar_DE(TDEstatico* de, void* chave){

  de->nro_bsc++;

  void* entrada=NULL;
  int inicio=0;
  int fim = de->ocupacao-1;
  short encontrou = 0; // falso
  while( (!encontrou) && (inicio<=fim)){
      int meio = (inicio+fim)/2;
      int status = de->comparar(de->entradas[meio], chave);
      if (status == 0){
        de->nro_cmp+=1;
        encontrou=1; //verdade
        entrada = de->entradas[meio].info;
      }else if(status > 0){
        de->nro_cmp+=2;
        fim = meio-1;
      }else{
        de->nro_cmp+=3;
        inicio = meio+1;
      }
  }
  return entrada;
}

int ocupacao_DE(TDEstatico* de){
    return de->ocupacao;
}

void carga_DE(TDEstatico* de, int chave, void* info){
    de->entradas[de->ocupacao] = entrada;
    de->ocupacao++;
}

void dashboard_DE(TDEstatico *de){
  printf("Nro buscas: %d\n", de->nro_bsc );
  printf("Nro comparacoes: %d\n", de->nro_cmp );
  printf("Media comparacoes por busca: %.2lf\n", (double) de->nro_cmp/de->nro_bsc );

}
