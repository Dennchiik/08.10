#include <iostream>

bool contains(const int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    int M, N;

    std::cout << "Введите размер массива A (M): ";
    std::cin >> M;

    std::cout << "Введите размер массива B (N): ";
    std::cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    std::cout << "Введите элементы массива A:" << std::endl;
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i];
    }

    std::cout << "Введите элементы массива B:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    int* C = new int[std::min(M, N)];
    int размер_C = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i] == B[j] && !contains(C, размер_C, A[i])) {
                C[размер_C++] = A[i];
            }
        }
    }

    std::cout << "Общие элементы массивов A и B без повторений (массив C):" << std::endl;
    for (int i = 0; i < размер_C; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
