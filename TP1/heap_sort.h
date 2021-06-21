#pragma once
//Copyright 2021 Axel Matus (B74597) Rodrigo Li (B94263) Wendy Ortiz alfaro (B75584)
//Tarea Programada #1: heap_sort

#include <iostream>
using namespace std;

/** put all elements in a heap from position k down - makes it a heap
* @param array of T; n is the size of it and k is the actual position
* @return NA
*/
template<typename T> // you can use any type of data in array
void correct_top(T array[], int n, int k) {
    int j = k; // temporary
    int left = 2 * k; // formula 2 * i + 1
    int right = 2 * k + 1; // formula 2 * i + 2

    // if the element that is in position k is greater than its children
    if (left < n && array[left] > array[j]){
        j = left;
    }
    if (right < n && array[right] > array[j]){
        j = right;
    }
    // if the element is not greater than its children
    if (j != k) {
        // in j is the maximum
        swap(array[k], array[j]);
        // Recursively with j
        correct_top(array, n, j);
    }
}

/** reallocate the array elements - the top one should be the largest
* @param array of T that we need to reallocate; n is the size of it
* @return NA
*/
template<typename T>
void monticularize(T array[], int n) {
    // rearrange array
    for (int index = n / 2; index >= 0; index--) { // last father
        correct_top(array, n, index);
    }
}

/** Extract the maximum and put it in the last position of the array
* @param array of T that works as a heap; n is the size of it
* @return NA
*/
template<typename T>
void extract_maximum(T array[], int n) {
    // remove the largest and put it last
    for (int index = n - 1; index > 0; index--) {
        swap(array[0], array[index]);
        //rearrange everything to remain heap
        correct_top(array, index, 0);
    }
}

/** This function checks that the heap is not empty
* @param the array that we need to check
* @return true if is empty
*/
template<typename T>
bool empty(T array[]) {
    return array[0] == 0;
}

/** This function sort the array
* @param Array of T that we need to sort; n is the size of it
* @return NA
*/
template<typename T>
void init_heap_sort(T array[], int n) {

    monticularize(array, n);
    if (empty(array) != true) {
        extract_maximum(array, n);
    }
}

/** This method print the array
* @param Array of T that we need to print; n is the size of it
*  and a message for show in a screen
* @return NA
*/
template<typename T>
void print_heap_sort(T array[], int n, string message) {
    cout << message << "\n";

    for (int index = 0; index < n; ++index) {
        cout << array[index] << " ";
    }
    cout << "\n\n";
}