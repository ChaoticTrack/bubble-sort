/*
 * Sorts a vector using a modified bubble sort algorithm.
*/

#include <vector>

void swapElements(std::vector<int> &list, int a, int b);
void bSort(std::vector<int> &numbers);

int main()
{
    std::vector<int> numbers = {3, 23, -16, 54};
    bSort(numbers);

    return 0;
}


void swapElements(std::vector<int> &list, int a, int b)
{
    int temp = list[b];
    list[b] = list[a]; // set new first num == old second num
    list[a] = temp; // set new second num == old first num

    return;
}

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
