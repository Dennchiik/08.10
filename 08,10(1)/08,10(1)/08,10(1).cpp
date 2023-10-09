#include <iostream>

int generateRandomNumber() {
    static int seed = 5323;
    seed = (8253729 * seed + 2396403);
    return seed % 100;
}

int main() {
    int* dynamicArray = nullptr;
    int количество_элементов = 5;

    dynamicArray = new int[количество_элементов];

    for (int i = 0; i < количество_элементов; ++i) {
        dynamicArray[i] = generateRandomNumber();
    }

    for (int i = 0; i < количество_элементов; ++i) {
        std::cout << dynamicArray[i] << " ";
    }

    delete[] dynamicArray;

    return 0;
}
