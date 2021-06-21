#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdlib.h>
#include <cstddef>
#include <iostream>

template <typename T>
class Priority_Queue {

public:
	struct Node	{

		T value;
		int priority;

		Node()
			:value{T()}
			,priority{999}
		{
		}

		Node(const T& value, int priority)
			:value{value}
			,priority{priority}
		{
		}

		~Node(){
		}
	};

private:
	int capacity;
	int size;
	Node* node_array;

public:
	Priority_Queue()
		:capacity{0}
		,size{0}
		,node_array{nullptr}
		{
		}

	~Priority_Queue(){
		delete[] node_array;
		this->node_array = nullptr;
		this->size = 0;
		this->capacity = 0;
	}

	bool insertar_elemento(const T& value, int priority){
		if(size == capacity){
			if(incrementar_capacidad() != true){
				return false;
			}
		}
		node_array[size++] = Node(value, priority);
		ordenar();
		return true;
	}

	void print(){
		std::cout << "------" << std::endl;
		for(int i = 0; i < size; i++){
			std::cout << "value: " << node_array[i].value << " priority: " << node_array[i].priority << std::endl;
		}
	}

	T maximo(){
		if(size > 0){
			return node_array[0].value;
		} else {
			return T();
		}
	}

	T extraer_max(){
		if(size > 0){
			Node temp = node_array[0];
			node_array[0] = node_array[size];
			size--;
			ordenar();
			return temp.value;
		} else{
			return T();
		}
	}

	//int incrementar_prioridad(){}
private:
void corregir_cima(Node* array, int pos_k, int length){
	int hijo_izq = pos_k << 1;
	int hijo_der = (pos_k << 1) | 1;
	int max = pos_k;
	if(hijo_izq < length && array[pos_k].priority < array[hijo_izq].priority ){
		max = hijo_izq;
	}
	if(hijo_der < length && array[max].priority < array[hijo_der].priority){
		max = hijo_der;
	}

	if(pos_k != max){
		Node temp = array[pos_k];
		array[pos_k] = array[max];
		array[max] = temp;

		corregir_cima(array, max, length);
	}
}

void monticularizar(Node* array, int length){
	int padre = length >> 1;

	while(padre >= 0){
		corregir_cima(array, padre, length);
		--padre;
	}
}

void ordenar(){
	monticularizar(node_array, size);
	int index = size-1;

	while(index > 0){
		Node temp = node_array[0];
		node_array[0] = node_array[index];
		node_array[index] = temp;
		monticularizar(node_array, index);
		index--;
	}
}

bool incrementar_capacidad() {
  int new_capacity = 10 * (capacity ? capacity : 1);
  Node* new_elements = new Node[new_capacity];

  if (new_elements) {
  	for(int i = 0; i < size; i++){
  		new_elements[i] = node_array[i];
  	}

  	delete[] node_array;

    capacity = new_capacity;
    node_array = new_elements;
    return true;
  } else {
    return false;
  }
}

};

#endif //PRIORITY_QUEUE_H