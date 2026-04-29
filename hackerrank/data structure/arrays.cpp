/*
 * Problem: Arrays - DS
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/arrays-ds/problem
 * Difficulty: Easy
 */

/* *
 * Note: This file contains the 'reverse_array' function developed for the challenge.
 * The original HackerRank boilerplate (I/O logic) was removed to provide 
 * a clean, standalone implementation.
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

// Logic developed for the HackerRank challenge
vector<int> reverse_array(vector<int> a) {
    int v_size = a.size();
    vector<int> arr;

    arr.reserve(v_size);

    for (int i = v_size - 1; i >= 0; i--) {
        arr.push_back(a[i]);
    }

    return arr;
}

// Local main to ensure code functionality outside the platform
int main() {
    vector<int> test = {1, 4, 3, 2};
    vector<int> res = reverse_array(test);

    for (int x : res) cout << x << " ";

    return 0;
}
