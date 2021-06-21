#include <iostream>
#include <algorithm>

using namespace std;
/**
 * @brief sorts any type of array with gnomeSort function
 * @param a is the array to be sorted
 * @param size is the size of the array, must be higher than 1
 * @return n/a
 * */
template<typename T>void init_gnomeSort(T a[],int size){
    int index=1; //Establece que el nomo da un paso adelante
    while(index < size){
        if(a[index] >= a[index-1]){ //Se fija en su posicion anterior y comprueba si es menor
            ++index; //en el caso de ser menor, sube al nomo una posicion
        }
        else{ //en el caso contrario, el nomo cambia los "floreros" y se va un paso atras
            swap(a[index],a[index-1]);
            --index;
        }
        if(index==0){ // si se va atras hasta la posicion 0, evita un segmentation fault posible y vuelve a la posicion 1
            ++index;
        }
    }
}