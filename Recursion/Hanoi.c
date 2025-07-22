#include<stdio.h>

void hanoi(int n, char from, char to, char via) {
    //base case
if(n == 1){
    printf("Move disk 1 from %c to %c\n", from, to);

}
else{
//recursive case

hanoi(n-1, from, via, to);

printf("Move disk %d from %c to %c\n", n, from, to);

hanoi(n-1, via, to, from);

 }
}

int main() {

int n = 3;

char from = 'A';

char to = 'C';

char via = 'B';

//calling hanoi() method

hanoi(n, from, to, via);

}