#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#define BLOCK_SIZE 64

void multiplicarBloques(const vector<vector<double>>& A,
                        const vector<vector<double>>& B,
                        vector<vector<double>>& C,
                        int i_start, int j_start, int k_start, int block_size, int n) {
    for (int i = i_start; i < min(i_start + block_size, n); i++) {
        for (int j = j_start; j < min(j_start + block_size, n); j++) {
            for (int k = k_start; k < min(k_start + block_size, n); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplicarMatricesPorBloques(const vector<vector<double>>& A,
                                   const vector<vector<double>>& B,
                                   vector<vector<double>>& C, int n) {
    for (int i = 0; i < n; i += BLOCK_SIZE) {
        for (int j = 0; j < n; j += BLOCK_SIZE) {
            for (int k = 0; k < n; k += BLOCK_SIZE) {
                multiplicarBloques(A, B, C, i, j, k, BLOCK_SIZE, n);
            }
        }
    }
}

void inicializarMatriz(vector<vector<double>>& M, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = rand() % 100;
        }
    }
}

int main() {
    srand(time(0));
    vector<int> tamanos = {100, 200, 500};

    for (int n : tamanos) {
        vector<vector<double>> A(n, vector<double>(n));
        vector<vector<double>> B(n, vector<double>(n));
        vector<vector<double>> C(n, vector<double>(n, 0.0));

        inicializarMatriz(A, n);
        inicializarMatriz(B, n);

        clock_t inicio = clock();
        multiplicarMatricesPorBloques(A, B, C, n);
        clock_t fin = clock();

        double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;
        cout << "Multiplicacion de matrices por bloques de dimension" << n << " x " << n
             << " completada en " << tiempo << " segundos." << endl;
    }

    return 0;
}
