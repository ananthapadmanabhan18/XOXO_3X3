// XOXO_3X3.cpp : Defines the entry point for the application.
//
#include "XOXO_3X3.h"
#include <vector>

using namespace std;

int main()
{	
	const int n_rows = 3;
	const int n_cols = 3;

	//create a 3x3 board with all 0
	vector<vector<int>> board(n_rows, vector<int>(n_cols, 0));

	for (int i = 0; i < n_rows; i++){
		for (int j = 0; j < n_cols; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}	


	cout << "Hello CMake." << endl;

	return 0;
}
