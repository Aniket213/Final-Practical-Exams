#include <iostream>
#include <stack>
#include <vector>

void reverseArrays(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::stack<int> stack1, stack2;

    // Push elements from arr1 into stack1
    for (int num : arr1) {
        stack1.push(num);
    }

    // Push elements from arr2 into stack2
    for (int num : arr2) {
        stack2.push(num);
    }

    // Pop elements from stack1 and assign them to arr1
    for (int i = 0; i < arr1.size(); i++) {
        arr1[i] = stack1.top();
        stack1.pop();
    }

    // Pop elements from stack2 and assign them to arr2
    for (int i = 0; i < arr2.size(); i++) {
        arr2[i] = stack2.top();
        stack2.pop();
    }
}

int main() {
    std::vector<int> arr1 = {90, 80, 70, 60, 50};
    std::vector<int> arr2 = {95, 85, 75, 65, 55};

    std::cout << "Original Arrays:" << std::endl;
    std::cout << "Array 1: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reverse the arrays
    reverseArrays(arr1, arr2);

    std::cout << "Reversed Arrays:" << std::endl;
    std::cout << "Array 1: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
