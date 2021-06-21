#include <algorithm>
#include <iostream>
using namespace std;
/**
 * @brief sorts an array with selectionSort
 * @param a is the array to be sorted
 * @param n is the array size
 * @return n/a
 * */
template <typename T>void init_selectionSort(T a[], int n) 
{ 
    for (int i = 0; i < n-1; i++) 
    { 
        int value = i; //establece el espacio inicial para ser intercambiado (en caso de ser necesario)
        for (int j = i+1; j < n; j++) //Recorre el arreglo para revisar si hay algun valor menor
        if (a[j] < a[value]){  //en el caso de encontrar uno menor, reemplaza @value para ser intercambiado
            value = j;  
        }
        std::swap(a[value], a[i]); //en el caso de no encontrar ninguno menor, solo se reemplaza consigo mismo
    } 
} 