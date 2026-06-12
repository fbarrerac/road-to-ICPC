/*
 * Problem: Preorder Transversal
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/tree-preorder-traversal/problem
 * Difficulty: Easy
 */

#include <iostream>
using std::cout;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void preOrder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Example usage:
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};

    preOrder(root);  // Output: 1 2 4 5 3

    return 0;
}