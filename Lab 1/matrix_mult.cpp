#include <cstddef>
#include <iostream>

void destroy_matrix(float** matrix, const size_t rows){
	if ( matrix ){
		for ( size_t row = 0; row < rows; ++row ){
			delete [] matrix[row];
		}
	}

	delete [] matrix;
}

float** create_matrix(const size_t rows, const size_t columns)
{
	float** matrix = new float*[rows]();
	if ( matrix == nullptr )
		return nullptr;

	for ( size_t row = 0; row < rows; ++row )
	{
		if ( ( matrix[row] = new float[columns]() ) == nullptr )
		{
			destroy_matrix(matrix, rows);
			return nullptr;
		}
	}

	return matrix;
}

void print_matrix( float** matrix, const size_t rows, const size_t columns) {

	for ( size_t row = 0; row < rows; ++row ){
		for ( size_t column = 0; column < columns; ++column ){
			std::cout << matrix[row][column] << (column < columns - 1 ? ' ' : '\n');
		}
	}
	printf("\n");
}

/*

  N^3

*/
void matrix_Mul(float** matrixNM, float** matrixMP, float** matrixNP, unsigned int n, unsigned int m, unsigned int p){

	for(unsigned int rows = 0; rows < n; rows++){
		for (unsigned int cols = 0; cols < p; cols++){
			int mult = 0;
			for(unsigned int pos = 0; pos < m ; pos++){
				mult += matrixNM[rows][pos] * matrixMP[pos][cols];
			}
			matrixNP[rows][cols] = mult;
		}
	}
}

int main()
{
	float** matrix1 = create_matrix(2,2);
	float** matrix2 = create_matrix(2,3);
	float** matrix_result = create_matrix(2,3);

	matrix1[0][0] = 1; matrix1[0][1] = 2;
	matrix1[1][0] = 3; matrix1[1][1] = 1;

	matrix2[0][0] = 1; matrix2[0][1] = 0; matrix2[0][2] = 1;
	matrix2[1][0] = 2; matrix2[1][1] = 1; matrix2[1][2] = 0;

	matrix_Mul(matrix1, matrix2, matrix_result, 2, 2, 3);

	print_matrix( matrix_result, 2, 3);

	destroy_matrix(matrix1, 2);
	destroy_matrix(matrix2, 2);
	destroy_matrix(matrix_result, 2);

}