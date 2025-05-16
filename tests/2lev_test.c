
#include <stdio.h>
int main(){
    int counter = 0;
    int i = 0;
for (i = 0; i < 100; i++) {
    if ((i % 4) != 3) {
        counter++;  // branch taken 3 times out of 4
    }
}
return 0;
}