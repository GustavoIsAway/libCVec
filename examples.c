#include <stdio.h>
#include "src/CVec.h"

int main(){
  c_vec vetor = vec_new(int);

  for (int i = 0; i < vec_getCapacity(vetor); i++)
    vec_push(vetor, i);

  vec_printVec(vetor);

  vec_destroy(vetor);
  return 0;
}
