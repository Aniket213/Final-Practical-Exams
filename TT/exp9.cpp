#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to swap two nodes
void swapNodes(Node* node1, Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Function to perform Bubble Sort on the linked list
void bubbleSortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    bool swapped;
    Node* currentNode;
    Node* lastNode = nullptr;

    do {
        swapped = false;
        currentNode = head;

        while (currentNode->next != lastNode) {
            if (currentNode->data > currentNode->next->data) {
                swapNodes(currentNode, currentNode->next);
                swapped = true;
            }
            currentNode = currentNode->next;
        }
        lastNode = currentNode;
    } while (swapped);
}

// Function to print the linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to deallocate memory for the linked list
void deleteLinkedList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a sample linked list
    Node* head = new Node(64);
    head->next = new Node(34);
    head->next->next = new Node(25);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(22);

    std::cout << "Linked List before sorting: ";
    printLinkedList(head);

    // Sort the linked list using Bubble Sort
    bubbleSortLinkedList(head);

    std::cout << "Linked List after sorting: ";
    printLinkedList(head);

    // Deallocate memory for the linked list
    deleteLinkedList(head);

    return 0;
}
