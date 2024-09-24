#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void multiplicarMatrices(const vector<vector<double>>& A,
                         const vector<vector<double>>& B,
                         std::vector<vector<double>>& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
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
        vector<vector<double>> C(n, vector<double>(n));

        inicializarMatriz(A, n);
        inicializarMatriz(B, n);

        clock_t inicio = clock();
        multiplicarMatrices(A, B, C, n);
        clock_t fin = clock();

        double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

        cout << "Multiplicacion de matrices de demension " << n << " x " << n
                  << " completada en " << tiempo << " segundos." << std::endl;
    }

    return 0;
}
