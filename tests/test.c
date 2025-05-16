#include <stdio.h>

// Recursive function to stress RAS and 2-level prediction
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function with many branches to exercise 2-bit, 2-level, and BTB
void branch_test(int x) {
    int sum = 0;
    int i = 0;
    for ( i = 0; i < x; i++) {
        if (i % 2 == 0)     // predictable branch
            sum += 1;
        else
            sum += 2;

        if (i % 3 == 0)     // less predictable branch
            sum += 3;

        if (i % 5 == 0)     // less frequent branch
            sum += 5;

        if (i % 7 == 0 && i % 2 != 0)  // composite branch
            sum += 7;

        if (i > 1000)       // always not taken if x is small
            sum -= 100;
    }

    printf("Branch test result: %d\n", sum);
}

// Function with multiple calls to test RAS
void ras_test() {
    fibonacci(4);  // causes recursive calls, checks RAS
    fibonacci(5);
    fibonacci(3);
}

// Simple taken/not-taken alternating pattern for 2-bit predictor
void two_bit_predictor_test(int n) {
    int i =0;
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) // predict taken
            printf("Even: %d\n", i);
        else            // predict not taken
            ;
    }
}

int main() {
    // Run different prediction stress tests
    branch_test(50);               // Triggers BTB, 2-bit, 2-level
    two_bit_predictor_test(50);   // Tests 2-bit saturating counter
    ras_test();                   // Tests return address stack

    return 0;
}
