// Characters are sorted in a form of a list (non continuous).  We have to check if the list of characters has a given character in it or not.

#include <iostream>
#include <list>

bool isCharacterPresent(const std::list<char>& charList, char targetChar) {
    for (char c : charList) {
        if (c == targetChar) {
            return true;
        }
    }
    return false;
}

int main() {
    std::list<char> charList = {'a', 'b', 'c', 'd', 'e'};
    char targetChar = 'c';

    if (isCharacterPresent(charList, targetChar)) {
        std::cout << "Character " << targetChar << " is present in the list." << std::endl;
    } else {
        std::cout << "Character " << targetChar << " is not present in the list." << std::endl;
    }

    return 0;
}
