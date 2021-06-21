#pragma once
//Copyright 2021 Axel Matus (B74597) Rodrigo Li (B94263) Wendy Ortiz alfaro (B75584)
//Tarea Programada #1: radix_sort

#include <cmath>
#include <iostream>
using namespace std;


/** This method is for get the maximum number in the array
 * @param The array and the size of it 
 * @return The maximum number of the array
 */
int maximum_number(int array[], int size) {
    int maximum = array[0];
    for (int index = 1; index < size; index++){
        if (array[index] > maximum) {
            maximum = array[index];
        }
    }
    return maximum;
}

/** This method do the count and sort the array depending of the exponent
 * @param the array that we need to sort, the size of it and the exponent
 * @return NA
 */
void counter_of_array(int array[], int size, int exponent) {
    int output[size]; // For do a copy
    int counter[10] = { 0 };
 
    for (int index = 0; index < size; index++) {
        counter[(array[index] / exponent) % 10]++;
    }
 
    for (int index = 1; index < 10; index++){
        counter[index] += counter[index - 1];
    }

    for (int index = size - 1; index >= 0; index--) {
        output[counter[(array[index] / exponent) % 10] - 1] = array[index];
        counter[(array[index] / exponent) % 10]--;
    }
    
    for (int index = 0; index < size; index++){
        array[index] = output[index];
    }
}
 

/** This method sort the array with the radix sort method
 * @param The array that we need to sort
 * @return NA
 */
void init_radix_sort(int array[], int size) {
    int maximum = maximum_number(array, size);
    // exponent = 10 ^ actual digit
    for (int exponent = 1; maximum / exponent > 0; 
        exponent *= 10) {
        counter_of_array(array, size, exponent);
    }
}

/** This method prints the array
* @param Array of integers that we need to print; n is the size of it
*  and a message for show in a screen
* @return NA
*/
void print(int array[], int size, string message) {
    cout << message << "\n";;

    for (int index = 0; index < size; index++) {
        cout << array[index] << " ";
    }
    cout << "\n\n";
}
 
