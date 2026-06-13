/*
 * Problem: Postorder Transversal
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/tree-postorder-traversal/problem
 * Difficulty: Easy
 */

#include <iostream>
using std::cout;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void postOrder(Node* root) {
    if (root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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

    postOrder(root);  // Output: 4 5 2 3 1

    return 0;
}
