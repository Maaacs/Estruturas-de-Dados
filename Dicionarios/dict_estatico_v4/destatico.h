typedef struct destatico TDEstatico;
typedef int(*TCompararDE)(void*, void*);

TDEstatico* criar_DE(int tamanho, TCompararDE comparar);

void* buscar_DE(TDEstatico* de, void* chave);
int ocupacao_DE(TDEstatico* de);

void carga_DE(TDEstatico* de, void* info);
void dashboard_DE(TDEstatico *de);
