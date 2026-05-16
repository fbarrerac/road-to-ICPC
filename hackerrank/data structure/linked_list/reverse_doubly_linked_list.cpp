#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

/**
 * Reverses a doubly linked list by swapping next and prev pointers for every node.
 *
 * Strategy:
 * 1. Traverse the list node by node.
 * 2. Swap the 'next' and 'prev' pointers of the current node.
 * 3. Use the old 'next' (now stored in 'prev') to move to the next node.
 */
Node* reverse_list(Node* head) {
    if (head == nullptr) return nullptr;

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // The node that was current->next is now current->prev.
        // We update head to the last non-null node we process.
        head = current;
        current = current->prev;
    }

    return head;
}

void print_list(Node* head) {
    while (head != nullptr) {
        cout << head->data << (head->next ? " <-> " : " -> NULL\n");
        head = head->next;
    }
}

int main() {
    // Create a list: 1 <-> 2 <-> 3 <-> 4 -> NULL
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    cout << "Original list: ";
    print_list(head);

    head = reverse_list(head);

    cout << "Reversed list: ";
    print_list(head);

    // Memory cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
