/*
 * Problem: Binary Search Tree: Lowest Common Ancestor
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* lca(Node* root, int v1, int v2) {
    if (root == nullptr) return nullptr;

    if (root->data > v1 && root->data > v2) {
        return lca(root->left, v1, v2);
    } else if (root->data < v1 && root->data < v2) {
        return lca(root->right, v1, v2);
    } else {
        return root;  // This is the lowest common ancestor
    }
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Example usage:
    Node* root = new Node{4, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{6, nullptr, nullptr};
    root->left->left = new Node{1, nullptr, nullptr};
    root->left->right = new Node{3, nullptr, nullptr};
    root->right->left = new Node{5, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};

    int v1 = 1;
    int v2 = 3;
    Node* ancestor = lca(root, v1, v2);

    cout << ancestor->data << "\n";  // Output: 2

    return 0;
}
