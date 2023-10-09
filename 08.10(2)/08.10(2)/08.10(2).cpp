#include <iostream>

int generateRandomNumber() {
    static int seed = 5323;
    seed = (8253729 * seed + 2396403);
    return seed % 100;
}

void добавитьСлучайныеЭлементы(int*& массив, int& текущийРазмер, int количество) {
    int новыйРазмер = текущийРазмер + количество;
    int* новыйМассив = new int[новыйРазмер];

    for (int i = 0; i < текущийРазмер; ++i) {
        новыйМассив[i] = массив[i];
    }

    for (int i = текущийРазмер; i < новыйРазмер; ++i) {
        новыйМассив[i] = generateRandomNumber();
    }

    delete[] массив;
    массив = новыйМассив;
    текущийРазмер = новыйРазмер;
}

int main() {
    int* dynamicArray = nullptr;
    int текущийРазмер = 0;
    int количество_элементов = 5;

    добавитьСлучайныеЭлементы(dynamicArray, текущийРазмер, количество_элементов);

    for (int i = 0; i < текущийРазмер; ++i) {
        std::cout << dynamicArray[i] << " ";
    }

    delete[] dynamicArray;

    return 0;
}
