#include "hash_table.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){

	hash_t<int> hash_table1(5);

	cout << "Capacity:" << hash_table1.table_size << " Elements:"<<hash_table1.size() << endl;

	hash_table1.insert("Hola", 5);
	hash_table1.insert("Mundo", 6);
	hash_table1.insert("Axel", 8);
	hash_table1.insert("Matus",10);

	cout << "Capacity:" << hash_table1.table_size << " Elements:"<<hash_table1.size() << endl;
	
	for(size_t index = 0; index < hash_table1.table_size; ++index){
		cout << hash_table1.hash_table[index].key << endl;
	};

	hash_table1.insert("A", 1);

	cout << "Capacity:" << hash_table1.table_size << " Elements:"<<hash_table1.size() << endl;

	for(size_t index = 0; index < hash_table1.table_size; ++index){
		cout << hash_table1.hash_table[index].key << endl;
	};

	return 0;
}