/*
 * Problem: Pointer
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
 * Difficulty: Easy
 */

#include <iostream>
#include <cmath>
using namespace std;

void update(int* pa, int* pb) {
    int a = *pa;
    *pa += *pb;
    *pb = abs(a - *pb);
}

int main() {
    int a, b;
    cin >> a >> b;

    update(&a, &b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}
