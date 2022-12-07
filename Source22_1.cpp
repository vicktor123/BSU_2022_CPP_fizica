#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
const int SIZE = 5;

//function create array and return pointer to 2d array
int** initialize(int n, int m) {
	srand(time(NULL));
	int **arr = new int* [n];

	for (int i = 0;i < n;i++) {
		arr[i] = new int[m];

		for (int j = 0; j < m; j++) {
			arr[i][j] = (rand() % 20) - 10;
		}
	}
	return arr;
}

void print(int** m, int r, int c) {
	for (int i = 0;i < r;i++) {		

		for (int j = 0; j < c; j++) {
			cout<<setw(3)<<m[i][j];
		}
		cout << endl;
	}
}


int min_row(int* m, int c) {
	int min = *m;
	for (int* p = m;p!=(m + c);p++)
		if (min > *p) min = *p;
	return min;
}

//return 2(pair) values
pair<int, int> all_solution(int** arr, int rows, int columns) {
	int max = min_row(arr[0], columns);
	int index = 0;
	for (int i = 1;i < rows;i++) {
		int curr = min_row(arr[i],columns);
		if (curr > max) {
			max = curr;
			index = i;
		}
	}
	return make_pair(max, index);
}
	
int main() {

	int** m = NULL;
	int rows, columns;
	cout << " input rows and columns " << endl;
	cin >> rows >> columns;
	m=initialize(rows, columns);
	print(m, rows, columns);

	
	pair<int, int> answer = all_solution(m,rows,columns);


	cout << "max item=" << answer.first << ":row index=" << answer.second << endl;


	

	for (int i = 0;i < rows;i++) {
		delete[] m[i];
	}
	delete[] m;


	return 0;
}