#include "stdio.h"
#include "stdlib.h"
#include "abb.h"
#include "assert.h"

typedef struct palavra{
    int ocorrencial;
    int pagina;
}TPalavra;

TPalavra* criarPalavra(int ocorrencia, int pagina){
    TPalavra* p = malloc(sizeof(TPalavra));
    p->pagina = pagina;
    p->ocorrencial = ocorrencia;
    return p;
}

void imprimirPalavra(void *palavra) {
    TPalavra* p = palavra;
    printf ("Pagina: %d Ocorrencia: %d\n" , p->pagina, p->ocorrencial);
}

int compararPalavra(void* p1, void* p2){
    // casting
    TPalavra *pp1 = p1;
    TPalavra *pp2 = p2;

    //insere as palavras baseado na página
    return (pp1->pagina - pp2->pagina);
}

int main(int argc, char const *argv[]){
    TABB* dasPalavras = criarABB(compararPalavra, imprimirPalavra);
    assert(dasPalavras!=NULL);
    int pagina, ocorre;
    scanf("%d", &pagina);
    while(pagina!=-1){
        scanf("%d", &ocorre);
        TPalavra* p = criarPalavra(ocorre, pagina);
        inserirABB(dasPalavras, p );
        scanf("%d", &pagina);
    }
    return 0;
}