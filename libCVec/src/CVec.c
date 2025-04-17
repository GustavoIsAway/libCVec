#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CVec.h"


struct Vector{
  int tamanho;
  int capacidade;
  int tamanhoDado;
  void* dados; //vetor
};


//Construtor e Destrutor
Vector* vec_newVec(int tamanho_dado){
  Vector* vetor = (Vector*) malloc(sizeof(Vector));

  vetor->tamanho = 0;
  vetor->capacidade = 10;
  vetor->tamanhoDado = tamanho_dado;
  vetor->dados = malloc(vetor->capacidade * vetor->tamanhoDado);
  if (vetor->tamanhoDado == sizeof(int)){
    int* dados = (int*) vetor->dados; 
    for (int i = 0; i < vetor->capacidade; i++)
      dados[i] = 0;
  } else if (vetor->tamanhoDado == sizeof(float)){
    float* dados = (float*) vetor->dados; 
    for (int i = 0; i < vetor->capacidade; i++)
      dados[i] = 0.0f;
  } else if (vetor->tamanhoDado == sizeof(double)){
    double* dados = (double*) vetor->dados; 
    for (int i = 0; i < vetor->capacidade; i++)
      dados[i] = 0.0;
  }
  
  return vetor;
}


void vec_destroy(Vector* vetor){
  free(vetor->dados);
  free(vetor);
}


//Getters e Setters
void* vec_getData(const Vector* vetor, int idx) {
  if (idx >= vetor->tamanho){
    fprintf(stderr, "ERR: Índice fornecido está além da capacidade.\n");
    exit(EXIT_FAILURE);
  }
  return ((char*)vetor->dados) + (idx * vetor->tamanhoDado);
}

int vec_getSize(const Vector* vetor){
  return vetor->tamanho;
}

int vec_getCapacity(const Vector* vetor){
  return vetor->capacidade;
}


//Operações Pop
void vec_pop(Vector* vetor){
  if (vetor->tamanho == 0) return;
  vetor->tamanho--;
}


//Operações Push
void vec_push_int(Vector* vetor, int valor){
  if (vetor->tamanho >= vetor->capacidade) {
    vetor->capacidade *= 2;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * vetor->tamanhoDado);
  }
  if (sizeof(valor) != vetor->tamanhoDado){
    fprintf(stderr, "ERR: tipo passado não corresponde ao vetor (int)");
    exit(EXIT_FAILURE);
  }

  int* dados = (int*) vetor->dados;
  dados[vetor->tamanho] = valor;
  vetor->tamanho++;
}


void vec_push_float(Vector* vetor, float valor){
  if (vetor->tamanho >= vetor->capacidade) {
    vetor->capacidade *= 2;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * vetor->tamanhoDado);
  }
  if (sizeof(valor) != vetor->tamanhoDado){
    fprintf(stderr, "ERR: tipo passado não corresponde ao vetor (float).\n");
    exit(EXIT_FAILURE);
  }
  float* dados = (float*) vetor->dados;
  dados[vetor->tamanho] = valor;
  vetor->tamanho++;
}


void vec_push_double(Vector* vetor, double valor){
  if (vetor->tamanho >= vetor->capacidade) {
    vetor->capacidade *= 2;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * vetor->tamanhoDado);
  }
  if (sizeof(valor) != vetor->tamanhoDado){
    fprintf(stderr, "ERR: tipo passado não corresponde ao vetor (double).\n");
    exit(EXIT_FAILURE);
  }
  double* dados = (double*) vetor->dados;
  dados[vetor->tamanho] = valor;
  vetor->tamanho++;
}


void vec_changeVec_int(Vector* vetor, int idx, int val){
  if (idx >= vetor->tamanho){
    fprintf(stderr, "ERR: Índice fornecido está além da capacidade.\n");
    exit(EXIT_FAILURE);
  }
  if (sizeof(val) != vetor->tamanhoDado){
    fprintf(stderr, "ERR: tipo passado não corresponde ao vetor (int).");
    exit(EXIT_FAILURE);
  }
  int* dado = (int*) vetor->dados;
  dado[idx] = val;
}

void vec_changeVec_float(Vector* vetor, int idx, float val){
  if (idx >= vetor->tamanho){
    fprintf(stderr, "ERR: Índice fornecido está além da capacidade.\n");
    exit(EXIT_FAILURE);
  }
  if (sizeof(val) != vetor->tamanhoDado){
    fprintf(stderr, "ERR: tipo passado não corresponde ao vetor (float).\n");
    exit(EXIT_FAILURE);
  }
  float* dado = (float*) vetor->dados;
  dado[idx] = val;
}

void vec_changeVec_double(Vector* vetor, int idx, double val){
  if (idx >= vetor->tamanho){
    fprintf(stderr, "ERR: Índice fornecido está além da capacidade.\n");
    exit(EXIT_FAILURE);
  }
  if (sizeof(val) != vetor->tamanhoDado){
    fprintf(stderr, "ERR: tipo passado não corresponde ao vetor (double).");
    exit(EXIT_FAILURE);
  }
  double* dado = (double*) vetor->dados;
  dado[idx] = val;
}


void vec_insert_int(Vector* vetor, int valor, int idx){
  if (vetor->tamanho >= vetor->capacidade) {
    vetor->capacidade *= 2;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * vetor->tamanhoDado);
  }

  int* dados = (int*) vetor->dados;
  for (int i = vetor->tamanho; i > idx; i--){
    dados[i] = dados[i - 1];
  }
  dados[idx] = valor;
  vetor->tamanho++; 
}


void vec_insert_float(Vector* vetor, float valor, int idx){
  if (vetor->tamanho >= vetor->capacidade) {
    vetor->capacidade *= 2;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * vetor->tamanhoDado);
  }

  float* dados = (float*) vetor->dados;
  for (int i = vetor->tamanho; i > idx; i--){
    dados[i] = dados[i - 1];
  }
  dados[idx] = valor;
  vetor->tamanho++; 
}


void vec_insert_double(Vector* vetor, double valor, int idx){
  if (vetor->tamanho >= vetor->capacidade) {
    vetor->capacidade *= 2;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * vetor->tamanhoDado);
  }

  double* dados = (double*) vetor->dados;
  for (int i = vetor->tamanho; i > idx; i--){
    dados[i] = dados[i - 1];
  }
  dados[idx] = valor;
  vetor->tamanho++; 
}


void vec_remove(Vector** vetor, int idx){
  if (idx >= (*vetor)->tamanho){
    fprintf(stderr, "ERR: Índice fornecido está além da capacidade.\n");
    exit(EXIT_FAILURE);
  }
  if ((*vetor)->tamanho == 0)
    return;

  Vector* novoVetor = malloc(sizeof(Vector));
  novoVetor->tamanho = (*vetor)->tamanho - 1;
  novoVetor->tamanhoDado = (*vetor)->tamanhoDado;
  novoVetor->capacidade = (*vetor)->capacidade;
  novoVetor->dados = malloc(novoVetor->tamanho * novoVetor->tamanhoDado);

  char* destino = (char*)novoVetor->dados;
  char* origem = (char*)(*vetor)->dados;

  memcpy(destino, origem, idx * (*vetor)->tamanhoDado);
  memcpy(destino + idx * (*vetor)->tamanhoDado,
        origem + (idx + 1) * (*vetor)->tamanhoDado,
        ((*vetor)->tamanho - idx - 1) * (*vetor)->tamanhoDado);

  free((*vetor)->dados);
  free((*vetor));

  *vetor = novoVetor;
}


void vec_printVec(const Vector* vetor){
  printf("[");
  for (int i = 0; i < vetor->tamanho; i++){
    printf("%d", ((int*)vetor->dados)[i]);
    if (i != vetor->tamanho - 1)
    printf(", ");
  }
    
  printf("]\n");
}
