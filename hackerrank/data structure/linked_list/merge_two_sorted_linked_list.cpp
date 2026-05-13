/*
 * Problem: Merge two sorted linked lists
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem
 * Difficulty: Easy
 */

#include <iostream>
using std::cout;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

/**
 * Merges two sorted linked lists into a single sorted linked list.
 * Reuses existing nodes by changing their next pointers.
 */
Node* merge_list(Node* head1, Node* head2) {
    // If one of the lists is empty, return the other list
    if (!head1) return head2;
    if (!head2) return head1;

    // Dummy node to simplify edge cases
    Node dummy(0);
    Node* tail = &dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes of the non-empty list
    if (head1) tail->next = head1;
    if (head2) tail->next = head2;

    // The merged list is next to the dummy node
    return dummy.next;
}

void print_list(Node* head) {
    while (head != nullptr) {
        cout << head->data << (head->next ? " -> " : " -> NULL\n");
        head = head->next;
    }
}

int main() {
    // List 1: 1 -> 3 -> 5 -> NULL
    Node* h1 = new Node(1);
    h1->next = new Node(3);
    h1->next->next = new Node(5);

    // List 2: 2 -> 4 -> 6 -> NULL
    Node* h2 = new Node(2);
    h2->next = new Node(4);
    h2->next->next = new Node(6);

    cout << "List 1: ";
    print_list(h1);
    cout << "List 2: ";
    print_list(h2);

    Node* merged_head = merge_list(h1, h2);

    cout << "Merged List: ";
    print_list(merged_head);

    // Memory cleanup
    // Note: Since we merged the lists, all nodes are now reachable from merged_head
    while (merged_head != nullptr) {
        Node* temp = merged_head;
        merged_head = merged_head->next;
        delete temp;
    }

    return 0;
}