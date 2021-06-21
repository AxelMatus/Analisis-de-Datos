#include "insertionSort.h"
#include "selectionSort.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"
#include "gnomeSort.h"
#include "radix_sort.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <time.h>

void add_to_file(ofstream& file, float duration, const char* testname);
int* create_array(int lenght, short flag);
void copy_array(int array[], int array_c[], int lenght);
bool is_sorted(int array[], int lenght);
void sort(ofstream& file, const char* testname, void (*func)(int func_array[], int func_lenght),int array[], int lenght);
void print_arr(int array[], int lenght);
/*
	Main
	Ejecuta los casos de prueba de diferentes algoritmos de ordenamiento
	Realiza 3 experimentos con tamaños de arreglo diferentes y ordenados de manera diferente
	Crea un archivo .csv donde almacena los datos obtenidos
	Imprime en consola el porcentaje de pruebas realizadas
*/
int main (){
	std::ofstream new_file("sorting_algorithms_test.csv");

	float porcentage = 0.0f;
	float count = 0.0f;
	
    for(int i = 0; i < 3; i++){
    	for(int arr_length = 16384; arr_length <= 262144; arr_length*=2){
    		printf("array lenght: %i\n", arr_length);
    	//for(int arr_length = 10000  ; arr_length < 10005 ; arr_length++){
    		for(int j = 0; j < 3; j++){

    			int* testing_array = create_array(arr_length, j);
    			int* copy = new int[arr_length];

				copy_array(testing_array, copy, arr_length);
    			sort(new_file, "selectionSort", &init_selectionSort, copy, arr_length);

    			count++;
    			porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));


    			copy_array(testing_array, copy, arr_length);
    			sort(new_file, "insertionSort", &init_insertionSort, copy, arr_length);
    			count++;
    			
				porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));

				copy_array(testing_array, copy, arr_length);
    			sort(new_file, "mergeSort", &init_merge_sort, copy, arr_length);

    			count++;
    			porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));
    			

				copy_array(testing_array, copy, arr_length);
    			sort(new_file, "heapSort", &init_heap_sort, copy, arr_length);

    			count++;
    			porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));

				copy_array(testing_array, copy, arr_length);
    			sort(new_file, "quickSort", &init_quick_sort, copy, arr_length);

    			count++;
    			porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));

				copy_array(testing_array, copy, arr_length);
    			sort(new_file, "radixSort", &init_radix_sort, copy, arr_length);

    			count++;
    			porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));

				// extras
				copy_array(testing_array, copy, arr_length);
    			sort(new_file, "bubbleSort", &init_bubble_sort, copy, arr_length);

    			count++;
    			porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));

				copy_array(testing_array, copy, arr_length);
    			sort(new_file, "gnomeSort", &init_gnomeSort, copy, arr_length);

    			count++;
    			porcentage = (count*100) / 360;
    			printf("Completado: %f\n", (porcentage));

    			delete[] testing_array;
    			delete[] copy;
    		}
    	}
    }
    printf("------end------");
	return 0;
}

/*	Crea un arreglo en memoria dinamica y le asigna valores dependiendo la bandera
	Si flag = 0, crea un arreglo aleatorio,
	si flag = 1 ordena arreglo ascendentemente,
	si flag = 2 o cualquier otro ordena arreglo descendentemente.
*/
int* create_array(int lenght, short flag){
	srand(time(0));
	int* new_array = new int[lenght];
	if (new_array != NULL) {

		if(flag == 0){
			for(int i = 0; i < lenght; i++){
				int num_rand = rand() % 1000000;
				new_array[i] = num_rand;
			}	
		} else {
			if(flag == 1){
				for(int i = 0; i < lenght; i++){
					new_array[i] = i;
				}
			} else {
				int index = 0;
				for(int num = lenght-1; num >= 0; num--){
					new_array[index] = num;
					index++;
				}
			}
		}
	}
	return new_array;
}

/*	Copia todos los valores de un arreglo en otro arreglo

*/
void copy_array(int* array, int* array_c, int lenght){
	if (array != NULL && array_c != NULL){
		for(int i = 0; i < lenght; i++){
			array_c[i] = array[i];
		}
	}
}

/*	Verifica si un arreglo esta ordenado ascendentemente
*/
bool is_sorted(int* array, int lenght){
	for(int i = 1; i < lenght; i++){
		if(array[i] < array [i-1]){
			return false;
		}
	}
	return true;
}

/*	Agrega a un archivo pasado por parametro, un tiempo (duracion), y el nombre de un test 
*/
void add_to_file(ofstream& file, float duration, const char* testname){
	char sep = ',';
	file << testname << sep << duration << std::endl;
}

/* 	Metodo encargado de realizar las pruebas, recibe el metodo a probar
	y determina el tiempo de ejecucion total del metodo probado,
	Imprime en consola el nombre del algoritmo que falle en su funcion de ordenar el arreglo 

*/
void sort(ofstream& file, const char* testname, void (*func)(int func_array[], int func_lenght),int array[], int lenght){
	printf("Test: %s\n", testname);

	auto start = std::chrono::high_resolution_clock::now();
	func(array, lenght);
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;

	printf("Tiempo: %lf",duration.count());
	if( !is_sorted(array, lenght) ){
		printf("Test failed: %s", testname);
	} else {
		add_to_file(file,duration.count(), (testname) );
	}	
}
