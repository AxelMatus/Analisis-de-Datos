#include <cstddef>
#include <iostream>

void corregir_cima(int array[], int pos_k, int length){
	int hijo_izq = pos_k << 1;
	int hijo_der = (pos_k << 1) | 1;
	int max = pos_k;
	if(hijo_izq < length && array[pos_k] < array[hijo_izq] ){
		max = hijo_izq;
	}
	if(hijo_der < length && array[max] < array[hijo_der]){
		max = hijo_der;
	}

	if(pos_k != max){
		int temp = array[pos_k];
		array[pos_k] = array[max];
		array[max] = temp;

		corregir_cima(array, max, length);
	}
}

void monticularizar(int array[], int length){
	int padre = length >> 1;

	while(padre >= 0){
		corregir_cima(array, padre, length);
		--padre;
	}
}

void ordenar(int array[], int length ){
	monticularizar(array, length);
	int index = length-1;

	while(index > 0){
		int temp = array[0];
		array[0] = array[index];
		array[index] = temp;
		monticularizar(array, index);
		index--;
	}

}


int main (){

	int array1[7] = {1,2,1,1,1,1,1};
	int array2[15] = {15,17,29,87,42,1,23,32,31,30,13,12,7,8,96};
	int array3[24] = {98,65,34,23,11,14,76,86,99,55,51,40,43,4,3,90,87,58,72,19,20,42,30,29};

	ordenar(array1, 7);
	ordenar(array2, 15);
	ordenar(array3, 24);

	for (int i = 0; i < 7; i++){
		std::cout << array1[i] << ' ';
	}
	std::cout << '\n';
	
	for (int i = 0; i < 15; i++){
		std::cout << array2[i] << ' ';  
	}
	
	std::cout << '\n';
	for (int i = 0; i < 24; i++){
		std::cout << array3[i] << ' ';
	}

	return 0;
}