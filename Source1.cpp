#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <random>



using namespace std;
int ran(int min, int max)
{
	std::random_device r;
	std::mt19937 gen(r());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

int** initialize(int n, int m) {
	srand(time(0));
	int** arr = new int* [n];

	for (int i = 0;i < n;i++) {
		arr[i] = new int[m];

		for (int j = 0; j < m; j++) {
			arr[i][j] = ran(-10, 40);
		}
	}
	return arr;
}

void print_array(int** mass, int rows, int columns) {
	cout << "print array" << endl << endl;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < columns;j++)
			cout << setw(3) << mass[i][j];
		cout << endl;
	}	
	cout << endl;
}

void create_2d_array(int** &mass, int rows, int columns) {
	
	
	mass = initialize(rows, columns);
	print_array(mass, rows, columns);
	
}

void destruction(int** &mass,int row) {
	if (mass) {
		for (int i = 0;i < row;i++)
			delete[] mass[i];
		delete[] mass;
	}
}

int** sum_two_array(int** m1, int** m2, int rows, int columns) {
	int **m3 = NULL;
	m3 = initialize(rows, columns);
	for (int i = 0;i < rows;i++)
		for (int j = 0;j < columns;j++)
			m3[i][j] = m1[i][j] + m2[i][j];
	print_array(m3, rows, columns);
	return m3;

}
int main() {

    
    int **ar1=NULL;
	int rows, columns;
	cout << " input rows and columns " << endl;
	cin >> rows >> columns;
	create_2d_array(ar1,rows,columns);

	int **ar2 = NULL;
	create_2d_array(ar2, rows, columns);

	int** result = sum_two_array(ar1, ar2, rows, columns);

	destruction(ar1, rows);
	destruction(ar2, rows);
	destruction(result, rows);
    return 0;

}