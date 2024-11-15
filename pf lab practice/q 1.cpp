#include <stdio.h>
#include <stdlib.h>
typedef struct Box {
    int weight;         
    struct Box **subBoxes;
    int subBox_Count;  
} Box;

int calculate_weight(Box *box) {
    int totalWeight = box->weight;

    for (int j = 0; j < box->subBox_Count; j++) {
        totalWeight += calculate_weight(box->subBoxes[j]);
    }
    return totalWeight;
}


Box* create_box(int weight, Box **subBoxes, int subBox_Count) {
    Box *newBox = (Box*)malloc(sizeof(Box));
    newBox->weight = weight;
    newBox->subBoxes = subBoxes;
    newBox->subBox_Count = subBox_Count;
    return newBox;
}

int main() {

    Box *box1 = create_box(10, NULL, 0);  
    Box *box2 = create_box(20, NULL, 0); 
    
   
    Box *subBoxes[] = {box1, box2};
    Box *box3 = create_box(5, subBoxes, 2); 

    Box *subSubBoxes[] = {box3};
    Box *box4 = create_box(30, subSubBoxes, 1); 

    printf("Total weight of box4: %d\n", calculate_weight(box4));
    
   
    free(box1);
    free(box2);
    free(box3);
    free(box4);

    return 0;
}
