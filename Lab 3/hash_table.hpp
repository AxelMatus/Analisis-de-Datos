#ifndef HASH_TABLE
#define HASH_TABLE

#include <cstddef>
#include <string>

#include <iostream>

template<typename D>
class hash_node{

public:
	D data;
	std::string key;

	hash_node(){
	}

	hash_node(const D data, const std::string key): data(data), key(key) {
	}

	~hash_node(){
	}

};

template<typename D>
class hash_t{
public:
	size_t table_size;
	size_t actual_elements;
	hash_node<D>* hash_table;

	hash_t() = delete;
	hash_t(size_t size);
	~hash_t();
	size_t hash_modulo(std::string key, size_t modulo); // private
	void resize(); // private
	void insert(std::string key, D data);
	D& get(std::string key);
	inline size_t size(){return this->actual_elements;}
	bool is_prime(size_t num);


};

template<typename D>
hash_t<D>::hash_t(size_t size){
	if(!is_prime(size)){
		if(!(size & 1)) ++size; // if even
		while(!is_prime(size)){
			size += 2;
		}
	}
	table_size = size;
	actual_elements = 0;
	hash_table = new hash_node<D>[table_size];
	for(size_t index = 0; index < table_size; ++index){
		hash_table[index] = hash_node<D>(0,"");
	}
};

template<typename D>
hash_t<D>::~hash_t(){
	table_size = 0;
	actual_elements = 0;
	delete [] hash_table;
};

template<typename D>
size_t hash_t<D>::hash_modulo(std::string key, size_t modulo){
	size_t sum = 0;
	for (size_t i = 0; i < key.length(); ++i) {
    	sum += int(key[i]);
  	}
  	size_t result = sum % modulo;
  	return result;
};

template<typename D>
void hash_t<D>::resize(){
	size_t new_table_size = table_size * 2; // new table is aprox 2 times bigger
	if(!is_prime(new_table_size)){
		if(!(new_table_size & 1)) ++new_table_size; // if even
		while(!is_prime(new_table_size)){
			new_table_size += 2;
		}
	}

	hash_node<D>* new_hash_table = new hash_node<D>[new_table_size];

	// Copy and inicialize the array
	for(size_t index = 0; index < new_table_size; index++){
		new_hash_table[index] = hash_node<D>(0,"");
	}
	// Its necesary to rehash
	hash_node<D>* old_hash_table = hash_table;
	size_t old_size = table_size;
	hash_table = new_hash_table;
	table_size = new_table_size;
	actual_elements = 0;

	for(size_t index = 0; index < old_size; index++){
		if(old_hash_table[index].key != ""){
			insert(old_hash_table[index].key, old_hash_table[index].data);
		}
	}

	delete [] old_hash_table;
};

template<typename D>
void hash_t<D>::insert(std::string key, D data){
	// If the hash table is full, resize the table
	if((actual_elements + 1) == table_size){ 
		resize();
	}

	size_t base = hash_modulo(key, table_size);
	size_t jump = 1 + hash_modulo(key, table_size-1);
	size_t index = base;
	while(hash_table[index].key != ""){
		index += jump;
	}

	hash_table[index] = hash_node<D>(data,key);
	actual_elements++;
};

template<typename D>
D& hash_t<D>::get(std::string key){
	size_t base = hash_modulo(key, table_size);
	size_t jump = 1 + hash_modulo(key, table_size-1);
	size_t index = base;
	while(hash_table[index].key != ""){
		if(hash_table[index].key == key){
			return hash_table[index].data;
		}
		index += jump;
	}
};

template<typename D>
bool hash_t<D>::hash_t::is_prime(size_t num){
	if (num <= 1) return false;
	if (num == 2) return true;
	if (num > 2 && !(num & 1)) return false;
	for (size_t oddnum_iterator = 3; oddnum_iterator < num; oddnum_iterator+=2) {
    	if (num % oddnum_iterator == 0) return false;
  	}
	return true;
};

#endif