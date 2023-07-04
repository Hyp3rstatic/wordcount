#include "include/test_dl_list.h"

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
 struct dl_list list = DL_LIST_NULL;
 struct dl_list *listp = dl_list_new();

 for(i = 0; i < 1000; i++){
  data = (int*)malloc(sizeof(int));
  *data = i;

  dl_list_add_above(&list, data, list.head);

  dl_list_add_above(listp, data, listp->head);
 }
 for(i = 0; i < 1000; i++){
  dl_list_del(&list, dl_list_get_int(&list, i));
  dl_list_del(listp, dl_list_get_int(listp, i));
 }

 dl_list_walk(&list);
 dl_list_walk(listp);
 return 0;
}