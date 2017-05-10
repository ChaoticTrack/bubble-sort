/*
 * Fills an integer vector with random numbers, sorts
 * the vector using a modified bubble sort algorithm,
 * and prints each element of the vector inline.
*/

#include <iostream> // cout
#include <vector> // vector
#include <ctime> // rand, srand

void fillVectorRandomly(std::vector<int> &numbers, int n, int min, int max);
void swapElements(std::vector<int> &list, int a, int b);
void bSort(std::vector<int> &numbers);
void printVector(std::vector<int> numbers);

int main()
{
    std::vector<int> numbers;
    int iterations = 100, min = 1, max = 1000;

    fillVectorRandomly(numbers, iterations, min, max);
    bSort(numbers);
    printVector(numbers);

    return 0;
}

/* ===================== FUNCTIONS ===================== */
// fill (vector) of ints (n) times between (min) and (max)
void fillVectorRandomly(std::vector<int> &numbers, int n, int min, int max)
{
    srand((unsigned)time(0));

    for (int i = 0; i < n; i++) {
        numbers.push_back( rand() % (max - min + 1) + min );
    }

    return;
}

void swapElements(std::vector<int> &list, int a, int b)
{
    int temp = list[b];
    list[b] = list[a]; // set new first num == old second num
    list[a] = temp; // set new second num == old first num

    return;
}

// bubble sort an integer (vector) array
void bSort(std::vector<int> &numbers)
{
    int sortedIterations = 0; // iterations without swapping numbers
    bool sorted = false;

    do {
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] < numbers[i - 1]) {
                swapElements(numbers, i, i - 1);
                sortedIterations = 0; // restart counter
            } else if (sortedIterations == numbers.size()) {
                sorted = true;
                break;
            } else {
                sortedIterations++; // no swap, therefore in the correct order
            }
        }

    } while (!sorted);

    return;
}

// print every element of (vector) inline
void printVector(std::vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << ' ';
    }

    return;
}
