#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../include/binary_search.h"


std::vector<int> generateRandomSortedArray(int size, int minStep, int maxStep) {
    std::vector<int> data(size);

    int current = 1;
    data[0] = current;

    for (int i = 1; i < size; i++) {
        int step = minStep + (std::rand() % (maxStep - minStep + 1));
        current += step;
        data[i] = current;
    }

    return data;
}

int main() {
    std::srand(std::time(0));

    std::vector<int> data = generateRandomSortedArray(10000000, 1, 10);

    int target = data[std::rand() %data.size()];
    int result = binarySearch(data, target);

    if (result != -1) {
        std::cout << "Target found at index: " << result << std::endl;
    } else {
        std::cout << "Target not found." << std::endl;
    }

    return 0;
}