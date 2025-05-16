
#include <stdio.h>
int main(){
    int counter = 0;
    int i = 0;
for (i = 0; i < 100; i++) {
    if (i % 2 == 0) {
        counter++;  // Alternates taken/not taken
    }
}
return 0;
}