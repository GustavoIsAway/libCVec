#ifndef CVEC_H
#define CVEC_H

#define vec_get(v, i, tipo) *((tipo*)vec_getData(v, i))
#define vec_new(tipo) vec_newVec(sizeof(tipo))
#define vec_push(vec, x) _Generic((x), \
  int: vec_push_int, \
  unsigned: vec_push_int, \
  float: vec_push_float, \
  double: vec_push_double \
) (vec, x)
#define vec_changeVec(vetor, idx, valor) _Generic((valor), \
  int: vec_changeVec_int, \
  unsigned: vec_changeVec_int, \
  float: vec_changeVec_float, \
  double: vec_changeVec_double \
) (vetor, idx, valor)
#define vec_insert(v, i, val) _Generic((val), \
int: vec_insert_int, \
unsigned: vec_insert_int, \
float: vec_insert_float, \
double: vec_insert_double \
) (v, i, val)

//STRUCT E TIPO
typedef struct Vector Vector;
typedef Vector* c_vec;


//CONSTRUTORES E DESTRUTORES
Vector* vec_newVec(int tamanho_dado);
void vec_destroy(Vector* vetor);


//GETTERS E SETTERS
int vec_getSize(const Vector* vetor);
int vec_getCapacity(const Vector* vetor);
void vec_printVec(const Vector* vetor);
void* vec_getData(const Vector* vetor, int idx);


//"SOBRECARGA" DE MÉTODOS
void vec_push_int(Vector* vetor, int valor);
void vec_push_float(Vector* vetor, float valor);
void vec_push_double(Vector* vetor, double valor);
void vec_insert_int(Vector* vetor, int valor, int idx);
void vec_insert_float(Vector* vetor, float valor, int idx);
void vec_insert_double(Vector* vetor, double valor, int idx);
void vec_changeVec_int(Vector* vetor, int idx, int val);
void vec_changeVec_float(Vector* vetor, int idx, float val);
void vec_changeVec_double(Vector* vetor, int idx, double val);


//MÉTODOS PADRÃO
void vec_remove(Vector** vetor, int idx);
void vec_pop(Vector* vetor);

#endif
