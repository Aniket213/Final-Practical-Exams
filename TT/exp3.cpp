// Names of persons are saved in a list. Create function to check if the names are palindrome or not.

#include <iostream>
#include <string>
#include <list>

bool isPalindrome(const std::string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

void checkPalindromeNames(const std::list<std::string>& names) {
    for (const std::string& name : names) {
        if (isPalindrome(name)) {
            std::cout << name << " is a palindrome." << std::endl;
        } else {
            std::cout << name << " is not a palindrome." << std::endl;
        }
    }
}
int main() {
    std::list<std::string> names = {"madam", "john", "civic", "anna", "hello"};

    checkPalindromeNames(names);

    return 0;
}



















