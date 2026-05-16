/*
 * Problem: Cycle Detection
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem
 * Difficulty: Medium
 */

#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

/**
 * Detects if a linked list contains a cycle.
 *
 * Strategy: Floyd's Cycle-Finding Algorithm (Tortoise and Hare).
 * We use two pointers moving at different speeds. If they meet,
 * there is a cycle. If the fast pointer reaches NULL, there is no cycle.
 */
bool has_cycle(Node* head) {
    if (head == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;        // Moves one step at a time
        fast = fast->next->next;  // Moves two steps at a time

        // If pointers meet, a cycle is detected
        if (slow == fast) {
            return true;
        }
    }

    // If we exit the loop, fast reached the end (no cycle)
    return false;
}

int main() {
    // Creating a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;  // Creates a cycle

    if (has_cycle(head)) {
        cout << "Cycle detected in the linked list." << "\n";
    } else {
        cout << "No cycle detected in the linked list." << "\n";
    }

    /*
     * CRITICAL MEMORY NOTE:
     * We do not perform a standard 'delete' loop here.
     * 1. A standard loop would become infinite since head never reaches nullptr.
     * 2. Deleting a node in a cycle leaves 'dangling pointers'. When the loop
     *    returns to the deleted address, it triggers Undefined Behavior.
     * To safely free this memory, one MUST break the cycle first (setting nullptr
     * to the last node before the cycle) before calling a cleanup routine.
     */

    return 0;
}
