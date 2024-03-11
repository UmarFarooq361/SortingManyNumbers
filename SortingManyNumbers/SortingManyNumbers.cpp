#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int static getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void static fillRandomNumbers(std::vector<int>& vec, int count) {
    vec.clear();
    for (int i = 0; i < count; ++i) {
        vec.push_back(getRandomNumber(1, 1000));
    }
}

void static bubbleSort(std::vector<int>& vec, int& passCount, int& swapCount, bool ascending) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && vec[j] > vec[j + 1]) || (!ascending && vec[j] < vec[j + 1])) {
                std::swap(vec[j], vec[j + 1]);
                ++swapCount;
                swapped = true;
            }
        }
        ++passCount;
        if (!swapped) {
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numCount;
    while (true) {
        std::cout << "Enter the number of random numbers to generate (between 100 and 1,000,000): ";
        std::cin >> numCount;

        if (numCount >= 100 && numCount <= 1000000) {
            break;
        }

        std::cout << "Invalid number count. Please enter a number between 100 and 1,000,000." << std::endl;
    }

    std::vector<int> numbers;
    fillRandomNumbers(numbers, numCount);

    std::cout << "Unsorted numbers: " << std::endl;
    for (int i = 0; i < numbers.size(); ++i) {
        if (i % 25 == 0) {
            std::cout << std::endl;
        }
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int passCount = 0;
    int swapCount = 0;
    int ascending;

    while (true) {
        std::cout << "Enter 1 for ascending order or 0 for descending order: ";
        std::cin >> ascending;

        if (ascending == 0 || ascending == 1) {
            break;
        }

        std::cout << "Invalid input. Please enter 1 for ascending order or 0 for descending order." << std::endl;
    }

    bubbleSort(numbers, passCount, swapCount, ascending);

    std::cout << "Sorted numbers: " << std::endl;
    for (int i = 0; i < numbers.size(); ++i) {
        if (i % 25 == 0) {
            std::cout << std::endl;
        }
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Number of passes: " << passCount << std::endl;
    std::cout << "Number of swaps: " << swapCount << std::endl;

    return 0;
}
