#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
// n log n

template <typename DataType>
size_t merge (std::vector<DataType>& array, size_t start, size_t end) {
  	
  DataType pin_Value = array[end];

  size_t pin_Index = start;

  for(size_t index = start; index < end; index++){
    if(array[index] < pin_Value){

      DataType temp = array[index];
      array[index] = array[pin_Index];
      array[pin_Index] = temp;
      pin_Index++;
    }	
  }

  DataType temp = array[pin_Index];
  array[pin_Index] = array[end];
  array[end] = temp;

  return pin_Index;
}

template <typename DataType>
void merge_sort (std::vector<DataType>& array, size_t start, size_t end) {
	if (start < end && end != (size_t)-1 ) {

		size_t index = merge(array, start, end);
	    merge_sort(array, start, index-1);
	    merge_sort(array, index+1, end);
	}
}

int main(){

	double vdoubles[] = {1.2,3.4,3.14,1.56,2.45,1.5,4.98,4.0,1.19,9.25,6.47};

	std::vector<double> value_doubles(vdoubles, vdoubles + sizeof(vdoubles) / sizeof(double));

	merge_sort(value_doubles, 0, value_doubles.size()-1);	


	for (vector<double>::iterator it = value_doubles.begin() ; it != value_doubles.end(); it++){
		cout << ' ' << *it << ' ' << endl;
	}

	return 0;
}


