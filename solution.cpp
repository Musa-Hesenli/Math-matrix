#include <iostream>
using namespace std;

void print_matrix(float arr[][100], int n);

int main() {
    int n, entry;
    float matrix[100][100], lower_matrix[100][100];
    cout << "Enter column & row number:\n";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter entries for " << i + 1 << ". row:\n";
        for(int j = 0; j < n; j++) {
            cin >> entry;
            matrix[i][j] = entry;
        }
    }
    cout << endl << endl << endl << "*****************************\n";
    cout << "Original matrix is:" << endl;
    print_matrix(matrix, n);
    for(int s = 0; s < n; s++) {
        for(int i = s + 1; i < n + 1;i++) {
            if(!matrix[s][s]) {
                continue;
            }
            float divider = - (matrix[i][s] / matrix[s][s]);
            lower_matrix[i][s] = -(divider);
            for (int j = 0; j < n + 1; j++) {
                float value = matrix[i][j] + (divider * (matrix[s][j]));
                matrix[i][j] = value;
            }   
        }
    };
    cout << "Upper matrix is:" << endl;
    print_matrix(matrix, n);
    cout << "Lower matrix is:\n";
    print_matrix(lower_matrix, n);
    cout << "Determinant finded by using upper matrix: ";
    int determinant = 1;
    for(int i = 0; i < n; i++) {
        determinant *= matrix[i][i];
    };
    cout << determinant;
}

void print_matrix(float arr[][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}