#include <cstddef>
#include <iostream>

using namespace std;
// n log n

/** 
 *  @brief Sorts any type of array with quick_sort
 *  @param arreglo is the array to be sorted
 *	@param inicio is the first index of partition 
 *  @param tamano is the size of the array
 *  @return n/a
 * */
void quick_sort(int* arreglo, int inicio, int tamano) {

  int aux;
  int i = inicio;
  int j = tamano;
  int x = arreglo[(inicio + tamano) / 2];
  do {
    while ((arreglo[i] < x) && (j <= tamano)){
      i++;
    }

    while ((x < arreglo[j]) && (j > inicio)) {
      j--;
    }

    if (i <= j) {
      aux = arreglo[i]; 
      arreglo[i] = arreglo[j]; 
      arreglo[j] = aux;
      
      ++i;  
      --j;
    }
  } while (i <= j);

  if (inicio < j){
       quick_sort(arreglo, inicio, j);
  }
  
  if (i < tamano){
    quick_sort(arreglo, i, tamano);
  }
    

};
/*
	Inicializa el algoritmo de ordenamiento
*/
void init_quick_sort(int* array, int lenght){
  quick_sort(array, 0, lenght-1);
}
