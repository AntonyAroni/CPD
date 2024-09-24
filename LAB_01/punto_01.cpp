#include <iostream>
#include <ctime>
#include <vector>

#define MAX 1000

void inicializar(std::vector<std::vector<double>>& A,
    std::vector<double>& x, std::vector<double>& y) {
    for (int i = 0; i < MAX; i++) {
        x[i] = i * 0.5;
        y[i] = 0.0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = (i + j) * 0.1;
        }
    }
}

void bucles_filas(const std::vector<std::vector<double>>& A,
    const std::vector<double>& x, std::vector<double>& y) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void bucles_columnas(const std::vector<std::vector<double>>& A,
    const std::vector<double>& x, std::vector<double>& y) {
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    std::vector<std::vector<double>> A(MAX,
        std::vector<double>(MAX));
    std::vector<double> x(MAX), y(MAX);

    inicializar(A, x, y);

    clock_t inicio = clock();
    bucles_filas(A, x, y);
    clock_t fin = clock();
    double tiempo_filas = double(fin - inicio) / CLOCKS_PER_SEC;

    std::fill(y.begin(), y.end(), 0.0);

    inicio = clock();
    bucles_columnas(A, x, y);
    fin = clock();
    double tiempo_columnas = double(fin - inicio) / CLOCKS_PER_SEC;

    std::cout << "Tiempo acceso por filas: "
    << tiempo_filas << " segundos" << std::endl;
    std::cout << "Tiempo acceso por columnas: "
    << tiempo_columnas << " segundos" << std::endl;

    return 0;
}
