
#include <iostream>

using namespace std;

bool possible(const int matrix[][9], const int x, const int y, const int value){

	int x_subMatrix = (x/3)*3;
	int y_subMatrix = (y/3)*3;

	for(int rows = 0 ; rows < 9; rows++){
		if(matrix[rows][y] == value){
			return false;
		}
	}

	for (int cols = 0; cols < 9; cols++){
		if(matrix[x][cols] == value){
			return false;
		}	
	}

	for(int rows = 0; rows < 3; rows++){
		for(int cols = 0; cols < 3; cols++){
			if(matrix[x_subMatrix + rows][ y_subMatrix + cols] == value){
				return false;
			}
		}
	}
	return true;	
}

void solve_sudoku(int matrix[][9]){

	for(int rows = 0; rows < 9; rows++){
		for(int cols = 0; cols < 9; cols++){

			if (matrix[rows][cols] == 0) {
				for(int possible_value = 1; possible_value <= 9; possible_value++ ) {
					if( possible(matrix, rows, cols, possible_value )){
						//if(rows == 8 && cols == 8)
						//cout << possible_value << " ";

						matrix[rows][cols] = possible_value;
						//cout << possible_value << " ";
						solve_sudoku(matrix);
							matrix[rows][cols] = 0;
					}
				}
				return;
			}
		}
	}

	for(int i = 0; i < 9; i++){
		for(int j = 0 ; j < 9; j++){
			cout << matrix[i][j] << " "; 
		}
		cout << "\n";
	}

	return;
}

int main (){

	int sudoku[9][9] = {{0,2,6,0,4,3,0,0,0},
						{0,0,0,6,0,0,0,0,0},
						{0,0,3,0,0,0,2,0,5},
						{5,6,8,0,0,0,0,0,2},
						{0,0,0,0,0,0,9,0,1},
						{0,0,7,0,0,0,0,3,0},
						{0,1,0,0,0,0,0,4,6},
						{7,0,0,0,6,0,0,0,0},
						{0,8,0,9,7,4,0,0,0}};

	solve_sudoku(sudoku);
	
	return 0;
}