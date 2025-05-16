#include <stdio.h>
  void foo() {
    // Some logic
}

void bar() {
    foo();
}


int main() {
    int i = 0;
    for (i = 0; i < 100; i++) {
        bar();  // Repeated nested function calls
    }
}

