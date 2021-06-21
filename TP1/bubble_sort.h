#pragma once
//Copyright 2021 Axel Matus (B74597) Rodrigo Li (B94263) Wendy Ortiz alfaro (B75584)
//Tarea Programada #1: Mergesort

#include <iostream>
using namespace std;

/** this method exchanges two values
 * @param the values that we need to swap
 * @return NA
*/
template<typename T> // you can use any type of data in array
void swap(T* first_value, T* second_value) {
    T temporary = *first_value;
    *first_value = *second_value;
    *second_value = temporary;
}

/** This function sorts with the bubble method
 * @param The array that we need to sort and the size of it.
 * @return NA
*/
template<typename T>
void init_bubble_sort(T array[], int array_size) {
    bool flag = true;
    for (int i = 0; i < array_size-1; i++){
        flag = false;
        for (int j = 0; j < array_size-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
        if (flag == true) {// not to do all the comparisons.
            break;
        }
    }
}

/** This method print the array
* @param Array of T that we need to print; n is the size of it
*  and a message for show in a screen
* @return NA
*/
template<typename T>
void print_bubble(T array[], int size, string message) {
    cout << message << "\n";
    for (int index = 0; index < size; index++){
        cout << array[index] << " ";
    }
    cout << "\n\n";;
}
 