/*
 * Problem: Basic Data Types
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
 * Difficulty: Easy
 */

#include <cstdio>

int main() {
    int i = 3;
    long long l = 12345678912345;
    char c = 'a';
    float f = 334.23f;
    double d = 14049.30493;

    printf("%d\n%lld\n%c\n%.2f\n%.5lf", i, l, c, f, d);

    return 0;
}