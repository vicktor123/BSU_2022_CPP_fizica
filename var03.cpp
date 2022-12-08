#include <iostream>
#include <climits>

#include <ctime>


using namespace std;

void initialize(int *&arr, int size, int lim) {
    srand(time(NULL));
    arr = new int[size];
    for (int i = 0; i < size; i++) {

        arr[i] = (rand() % lim);
    }
}

void find_max_min_index(int ar[], int size, int* max, int* min) {
    int mx = INT_MIN;
    int mn = INT_MAX;
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < size; i++) {
        if (ar[i] > mx) {
            mx = ar[i];
            index1 = i;
        }
        if (ar[i] < mn) {
            mn = ar[i];
            index2 = i;
        }
    }
    *max = index1;//возврат индекса максимального
    *min = index2;//возврат индекса минимального
}



void print_arr(int ar[], int size) {
    for (int j = 0; j < size; j++)
        cout << ar[j] << " ";
    cout << endl;
}

void swap(int ar[], int size, int imx, int position) {
    int tt = ar[imx];  ar[imx] = ar[position]; ar[position] = tt;

}

void foo(int *&ar, int size) {
    initialize(ar, size, 100);
    cout << "print array!\n";
    print_arr(ar, size);
    int imax, imin = -1;
    //ищем индекс максимального элемента
    find_max_min_index(ar, size, &imax, &imin);

    //перестановка первого и максимального в массиве
    swap(ar, size, imax, 0);
    
    //ищем индекс минимальный элемента еще раз
    find_max_min_index(ar, size, &imax, &imin);
    //перестановка последнего и минимального в массиве
    swap(ar, size, imin, size - 1);
}


int choice1 = 0;
void mainMenu(void) {

    cout << "Main Menu\n";
    cout << "1 - Start  \n";
    cout << "2 - Print result array\n";
    cout << "3 - Quit\n";
    cout << "Please choose: ";
    cin >> choice1;

}

void menu(int ar[]) {
    int size=0;
    do {        
        mainMenu();
        switch (choice1) {

        case 1:
            if (ar) delete[] ar;
            cout << "input size array and run work!\n";
             cin >> size;
            foo(ar, size);            
            break;

        case 2:
            cout << "print new array!\n";
            print_arr(ar, size);
            break;

        case 3:
            if (ar) delete[] ar;
            break;

        }

    } while (choice1 != 3);


}

int main() {

    
    int* ar=NULL;
    menu(ar);    

    return 0;

}