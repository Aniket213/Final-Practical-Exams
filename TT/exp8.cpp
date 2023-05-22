#include <iostream>
#include <map>
#include <vector>

void sortArray(std::vector<int> &arr)
{
    std::map<int, int> freqMap;

    // Count the frequencies of each element
    for (int num : arr)
    {
        freqMap[num]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (const auto &pair : freqMap)
    {
        for (int i = 0; i < pair.second; i++)
        {
            arr[index++] = pair.first;
        }
    }
}

int main()
{
    std::vector<int> arr = {9, 4, 6, 2, 9, 1, 3, 6, 4, 2, 1, 8, 5, 7};

    std::cout << "Original Array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sortArray(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
