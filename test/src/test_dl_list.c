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

//adding new head test
 printf("adding new head test starting\n");
 for(i = 0; i < 1000; i++){
  data = (int*)malloc(sizeof(int));
  *data = i;

  dl_list_add_above(&list, data, list.head);
  dl_list_add_above(listp, data, listp->head);
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("adding new head test over\n");

//deleting list nodes
 printf("deleting list nodes 1 starting\n");
 for(i = 0; i < 1000; i++){
  dl_list_del(&list, dl_list_get_int(&list, i));
  dl_list_del(listp, dl_list_get_int(listp, i));
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("deleting list nodes 1 over\n");

//adding new tail test
 printf("adding new tail test starting\n");
 for(i = 0; i < 1000; i++){
  data = (int*)malloc(sizeof(int));
  *data = i;

  dl_list_add_below(&list, data, list.tail);
  dl_list_add_below(listp, data, listp->tail);
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("adding new tail test over\n");

//deleting list nodes
 printf("deleting list nodes 2 starting\n");
 for(i = 0; i < 1000; i++){
  dl_list_del(&list, dl_list_get_int(&list, i));
  dl_list_del(listp, dl_list_get_int(listp, i));
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("deleting list nodes 2 over\n");

//deleting list nodes
 printf("deleting list nodes 3 starting\n");
 for(i = 0; i < 1000; i++){
  dl_list_del(&list, dl_list_get_int(&list, i));
  dl_list_del(listp, dl_list_get_int(listp, i));
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("deleting list nodes 3 over\n");

//adding null below
 printf("adding null starting\n");
 for(i = 0; i < 1000; i++){
  dl_list_add_below(&list, 0, list.head);
  dl_list_add_below(listp, 0, listp->tail);
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("adding null over\n");

//adding between below
 printf("adding new tail test starting\n");
 for(i = 0; i < 1000; i++){
  data = (int*)malloc(sizeof(int));
  *data = i;

  dl_list_add_below(&list, data, dl_list_get_int(&list, 0));
  dl_list_add_above(listp, data, dl_list_get_int(listp, 0));
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("adding new tail test over\n");

//adding null above
 printf("adding null above starting\n");
 for(i = 0; i < 1000; i++){
  dl_list_add_above(&list, 0, list.head);
  dl_list_add_above(listp, 0, listp->tail);
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("adding null below over\n");

//adding to null list
 printf("adding to null list starting\n");
 for(i = 0; i < 1000; i++){
  data = (int*)malloc(sizeof(int));
  *data = i;

  dl_list_add_above(0, data, list.tail);
  dl_list_add_below(0, data, listp->tail);
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("adding to null list over\n");

//adding with null target
 printf("adding with null target starting\n");
 for(i = 0; i < 1000; i++){
  data = (int*)malloc(sizeof(int));
  *data = i;

  dl_list_add_below(&list, data, 0);
  dl_list_add_above(listp, data, 0);
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("adding with null target over\n");

//deleting list nodes
 printf("deleting list nodes 4 starting\n");
 for(i = 0; i < 1000; i++){
  dl_list_del(&list, list.head);
  dl_list_del(listp, listp->tail);
 }
 dl_list_walk(&list);
 dl_list_walk(listp);
 printf("deleting list nodes 4 over\n");

 return 0;
}