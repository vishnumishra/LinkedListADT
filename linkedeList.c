#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"


int main(){
    struct node *root;
    root =  malloc( sizeof(struct node) ); 
    root->next = NULL;
    root->x = 5;
}