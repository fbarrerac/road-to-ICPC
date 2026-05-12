/*
 * Problem: Compare two linked lists
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/compare-two-linked-lists/problem
 * Difficulty: Easy
 */

#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

bool compare_lists(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;  // Lists are not identical
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == nullptr && head2 == nullptr;  // Both should reach nullptr for lists to be identical
}

int main() {
    // Creating first linked list: 1 -> 2 -> 3 -> NULL
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // Creating second linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);

    // Comparing the two lists
    if (compare_lists(head1, head2)) {
        cout << "The linked lists are identical." << "\n";
    } else {
        cout << "The linked lists are not identical." << "\n";
    }

    // Memory cleanup for first list
    while (head1 != nullptr) {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    // Memory cleanup for second list
    while (head2 != nullptr) {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
