/*
 * Problem: Arrays Introduction
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/arrays-introduction/problem
 * Difficulty: Easy
 */

#include <iostream>
using namespace std;

/**
 * Punto de entrada del programa.
 * Gestiona la lectura de N enteros y su posterior impresión inversa.
 */
int main() {
    int n;
    if (!(cin >> n)) return 0;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
