#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>

int max_Pieces(int length) {
    if (length == 0) {
        return 0;
    }
    if (length < 0) {
        return -1000; 
    }

    int cut1 = 1 + max_Pieces(length - 1);  
    int cut2 = 1 + max_Pieces(length - 2);  
    int cut3 = 1 + max_Pieces(length - 3);  

    int max_Cuts = cut1 > cut2 ? cut1 : cut2;
    max_Cuts = max_Cuts > cut3 ? max_Cuts : cut3;

    return max_Cuts;
}

int main() {
    int length;

    printf("Enter the length of the rope: ");
    scanf("%d", &length);

    int result = max_Pieces(length);
    printf("Maximum number of pieces: %d\n", result);

    return 0;
}
