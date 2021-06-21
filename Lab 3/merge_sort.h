#pragma once
//Copyright 2021 Axel Matus (B74597) Rodrigo Li (B94263) Wendy Ortiz alfaro (B75584)
//Tarea Programada #1: Mergesort

#include<iostream>
#include<vector>

using namespace std;

/**
* this method divide the original array into halves and order
*  each half
* @param the original and disordered array, the first position
*   of the array and the last position of it.
* @return NA
*/
template<typename T> //you can use any type of data in array
void merge(T array[], int first_position, int last_position) {

    int temporary_index;
    int first_half;
    int second_half;
    int half;

    vector<T> temporary_array(last_position - first_position + 1);
    // divide the array 
    half =  (first_position + last_position) / 2;
    temporary_index = 0;
    // identify the halves 
    first_half = first_position;
    second_half = half + 1;

    // compare the data of each half 
    while (first_half <= half && second_half <= last_position) {
        if (array[first_half] < array[second_half]) {
            temporary_array[temporary_index] = array[first_half];
            ++first_half;
            ++temporary_index;
        }
        else {
            temporary_array[temporary_index] = array[second_half];
            ++second_half;
            ++temporary_index;
        }
    }

    while (first_half <= half) {
        temporary_array[temporary_index] = array[first_half];
        ++first_half;
        ++temporary_index;
    }

    while (second_half <= last_position) {
        temporary_array[temporary_index] = array[second_half];
        ++second_half;
        ++temporary_index;
    }

    for (int index = first_position; index <= last_position; ++index) {
        array[index] = temporary_array[index - first_position];
    }

}

/**
* this method join the halves of the ordered array
* @param the ordered array, the first position
*   of the array and the last position of it.
* @return NA
*/
template<typename T>
void merge_sort(T array[], int first_position, int last_position) {

    if(first_position < last_position) {
        int half =  (first_position + last_position) / 2;
        // do the merge sort with the fristPosition to the half
        merge_sort(array, first_position, half);
        // do the merge sort with the half + 1 to the last_position
        merge_sort(array, half + 1, last_position);
        // do merge with the two parts 
        merge(array, first_position, last_position);
    }

}

template<typename T>
void init_merge_sort(T array[], int length){
    merge_sort(array,0, length-1);
}

/** This method print the array
* @param Array of T that we need to print; n is the size of it
*  and a message for show in a screen
* @return NA
*/
template<typename T>
void print_merge_sort(T array[], int size, string message) {
    cout << message <<"\n";
    for (int index = 0; index < size; ++index) {
        cout << array[index] << " ";
    }
    cout << "\n\n";
}


