#include <stdio.h>
#include "../src/include/dl_list.h"

struct dl_node *dl_list_get_int(struct dl_list *list, int data){
    struct dl_node *walker = list->head;
    while(walker != 0){
        if(*(int*)walker->data == data){
            return walker;
        }
        walker = walker->next;
    }
    return 0;
}

void dl_list_walk(struct dl_list *list){
    struct dl_node *walker = list->head;
    printf("\n|-----------|\n");
    printf("\nSTARTING HEAD\n");
    while(walker != 0){
        printf("%d\n", *(int*)walker->data);
        walker = walker->next;
    }
    walker = list->tail;
    printf("\nSTARTING TAIL\n");
    while(walker != 0){
        printf("%d\n", *(int*)walker->data);
        walker = walker->prev;
    }
    printf("\n|___________|\n");
}

int main(int argc, char *argv[]){
    int i;
    int *data;

 return 0;
}