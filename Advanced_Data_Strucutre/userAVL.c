#include "Display_Tree.h"
#include <stdio.h>

int main(){
    DataType values[] = {20,30,25,19,24,26,31},
             n = sizeof(values)/sizeof(values[0]),
             ll[] = {50,40,30,20,65,55,45,35},
             rr[] = {20,30,40,50,15,25,35,45,55},
             lr[] = {50,40,45,41,46,30,55},
             other[] = {50,40,9,60,30,45,60,55,15,35,51,56,9,10,52};

    avlNode_t* root = NULL;
    root = createNode(10);

    for(int i = 0; i < n; i++){
        insertAVL(root, createNode(values[i]));    
        print_t(root);
        printf("\n\n");
    }
    rl_rotate(root->right, root);
    print_t(root);
}