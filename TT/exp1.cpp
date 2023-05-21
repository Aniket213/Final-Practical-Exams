// A data structure needs to be implemented in such a way that we have the references i.e. the addresses of the values. 
// None of the addresses are in continuous memory block. Each time a new value needs to be stored, we need to allocate memory. 
// Write a program to implement the following:
// Addition of new value at a given position
// Delete a value at a given position
// Print all the values in the list


#include <iostream>

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insertion at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        std::cout << "Inserted " << data << " at the beginning of the linked list." << std::endl;
    }

    // Insertion at a specific position in the list
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);

        if (position <= 0) {
            std::cout << "Invalid position. Insertion failed." << std::endl;
            return;
        }

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            std::cout << "Inserted " << data << " at position " << position << " in the linked list." << std::endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        int currentPosition = 1;

        while (curr != nullptr && currentPosition < position) {
            prev = curr;
            curr = curr->next;
            currentPosition++;
        }

        if (curr == nullptr && currentPosition < position) {
            std::cout << "Invalid position. Insertion failed." << std::endl;
            return;
        }

        prev->next = newNode;
        newNode->next = curr;
        std::cout << "Inserted " << data << " at position " << position << " in the linked list." << std::endl;
    }

    // Deletion of a node at a specific position in the list
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            std::cout << "Linked list is empty. Cannot perform deletion." << std::endl;
            return;
        }

        if (position <= 0) {
            std::cout << "Invalid position. Deletion failed." << std::endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Deleted node at position " << position << " from the linked list." << std::endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        int currentPosition = 1;

        while (curr != nullptr && currentPosition < position) {
            prev = curr;
            curr = curr->next;
            currentPosition++;
        }

        if (curr == nullptr && currentPosition < position) {
            std::cout << "Invalid position. Deletion failed." << std::endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        std::cout << "Deleted node at position " << position << " from the linked list." << std::endl;
    }

    // Print the linked list
    void print() {
        if (head == nullptr) {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        std::cout << "Linked list elements: ";
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

// Main function
int main() {
    LinkedList list;

    int choice, data, position;

    do {
        std::cout << "------------------------" << std::endl;
        std::cout << "Linked List Operations:" << std::endl;
        std::cout << "1. Insert at the beginning" << std::endl;
        std::cout << "2. Insert at a specific position" << std::endl;
        std::cout << "3. Delete at a specific position" << std::endl;
        std::cout << "4. Print the linked list" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the data to insert at the beginning: ";
                std::cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                std::cout << "Enter the data to insert: ";
                std::cin >> data;
                std::cout << "Enter the position to insert at: ";
                std::cin >> position;
                list.insertAtPosition(data, position);
                break;
            case 3:
                std::cout << "Enter the position to delete: ";
                std::cin >> position;
                list.deleteAtPosition(position);
                break;
            case 4:
                list.print();
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (choice != 5);

    return 0;
}
