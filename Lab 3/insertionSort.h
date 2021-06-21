#include <iostream>

using namespace std;
/** 
 *  @brief Sorts any type of array with insertionSort
 *  @param a is the array to be sorted
 *  @param n is the size of the array
 *  @return n/a
 * */
template <typename T>void init_insertionSort(T a[], int n)
{
    for (int i = 1; i < n; i++)
    { 
        int reference = a[i];  // establece una referencia, que se va moviendo por el for, asi para ir acomodando
        int j = i - 1;
        while (j >= 0 && a[j] > reference) //Corre todos los numeros hacia la izquierda que sean mayores que la referencia
        {
            a[j + 1] = a[j]; 
            j = j - 1;
        }
        a[j + 1] = reference;
    }

}