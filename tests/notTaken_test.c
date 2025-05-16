
#include <stdio.h>
int main(){
    int counter = 0;
    int i = 0;
for (i = 0; i < 10000; i++) {
    if (i < 10) {
        counter++;  // 90 nottaken 10 taken
    }
}
return 0;
}