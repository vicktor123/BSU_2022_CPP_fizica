#include<iostream>
#include<cmath>
#include<random>
#include<iomanip>
#include<cstdlib>

using  namespace std;
int ran(int min, int max) {

	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

int** initialize(int n, int m) {
	srand(time(0));
	int** arr = new int* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];

		for (int j = 0; j < m; j++) {
			arr[i][j] = ran(-10, 10);
		}
	}
	return arr;
}

void print_array(int** mass, int rows, int columns) {

	cout << "print array" << endl << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			cout << setw(5) << mass[i][j];
		cout << endl;

	}
	cout << endl;
}
void show_array(int**& mass, int rows, int columns) {
	mass = initialize(rows, columns);
	if (rows == columns) {
		print_array(mass, rows, columns);
	}
	else {
		rows != columns;
		cout << "not correct!" << endl;
	}
}

double round_up(double value, int decimal_places) {
	const double multiplier = std::pow(10.0, decimal_places);
	return std::ceil(value * multiplier) / multiplier;
}

double norma_vector(int* arr, int columns) {
	double res = 0;
	for (int i = 0;i < columns;i++) {
		res = res + pow(arr[i], 2);
	}
	return sqrt(res);
}

void destruction(int**& mass, int row) {
	if (mass) {
		for (int i = 0;i < row;i++)
			delete[] mass[i];
		delete[] mass;
	}
}

void max_norma(int** arr, int rows, int columns) {
	double max = -1;
	int index = -1;
	double temp = 0.0;
	for (int i = 0;i < rows;i++) {
		temp = norma_vector(arr[i], columns);
		if (temp > max) {
			index = i;
			max = temp;
		}
	}
	cout << " max value=" << round_up(max,2) << " index row=" << index;
}

int main() {

	int** arr = NULL;
	int rows, columns;
	cout << " input rows and columns " << endl;
	cout << " dont forget that number of rows = number of columns" << endl;
	cin >> rows >> columns;
	show_array(arr, rows, columns);
	max_norma(arr, rows, columns);


	destruction(arr, rows);
	return 0;


}