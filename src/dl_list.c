/*
 * dl_list function definitions
 */
#include "include/dl_list.h"

struct dl_list *dl_list_new(void){
 struct dl_list *new = (struct dl_list*)malloc(sizeof(struct dl_list));
 new->head = 0;
 new->tail = 0;
 return new;
}

_Bool dl_list_add_above( struct dl_list *list,
                         void *data,
                         struct dl_node *target){

//safety checks
 if(data == 0 || list == 0){
  return 1;
 }

//assign flag to proper number
 short flag = dl_list_add_case_handler(list, target, 0);

//add node with "data" to "list" above "target"
 return dl_list_add(list, data, target, flag);
}

_Bool dl_list_add_below( struct dl_list *list,
                         void *data,
                         struct dl_node *target){

//safety checks
 if(data == 0 || list == 0){
  return 1;
 }

//assign flag to proper number
 short flag = dl_list_add_case_handler(list, target, 1);

//add node with "data" to "list" above "target"
 return dl_list_add(list, data, target, flag);
}

_Bool dl_list_del(struct dl_list *list, struct dl_node *node){

//saftey checks
 if(node == 0 || list == 0){
  return 1;
 }

//assign flag to proper number
 short flag = dl_list_del_case_handler(list, node);

//delete "node" from "list"
 return __dl_list_del(list, node, flag);
}

struct dl_node *dl_node_new(void *data){
 struct dl_node *new = (struct dl_node*)malloc(sizeof(struct dl_node));
 new->data = data;
 return new;
}

_Bool dl_list_empty_add(struct dl_list **list, void *data){
 (*list)->head = dl_node_new(data);
 (*list)->head->prev = 0;
 (*list)->tail = (*list)->head;
 (*list)->tail->next = 0;
 return 0;
}

_Bool dl_list_head_add(struct dl_list **list, void *data){
 (*list)->head->prev = dl_node_new(data);
 (*list)->head->prev->next = (*list)->head;
 (*list)->head = (*list)->head->prev;
 (*list)->head->prev = 0;
 return 0;
}

_Bool dl_list_tail_add(struct dl_list **list, void *data){
 (*list)->tail->next = dl_node_new(data);
 (*list)->tail->next->prev = (*list)->tail;
 (*list)->tail = (*list)->tail->next;
 (*list)->tail->next = 0;
 return 0;
}

_Bool __dl_list_add_above(void *data, struct dl_node **target){
 (*target)->prev->next = dl_node_new(data);
 (*target)->prev->next->prev = (*target)->prev;
 (*target)->prev = (*target)->prev->next;
 (*target)->prev->next = (*target);
 return 0;
}

_Bool __dl_list_add_below(void *data, struct dl_node **target){
 (*target)->next->prev = dl_node_new(data);
 (*target)->next->prev->next = (*target)->next;
 (*target)->next = (*target)->next->prev;
 (*target)->next->prev = (*target);
 return 0;
}

//default fail
_Bool dl_list_add(  struct dl_list *list,
                    void *data,
                    struct dl_node *target,
                    unsigned short flag){
 switch(flag){
 case 0:
  return dl_list_empty_add(&list, data);
 case 1:
  return dl_list_head_add(&list, data);
 case 2:
  return dl_list_tail_add(&list, data);
 case 3:
  return __dl_list_add_above(data, &target);
 case 4:
  return __dl_list_add_below(data, &target);
 default:
  return 1;
 }
}

//"flag" = 0: adding above
//"flag" = 1: adding below
//-1 fail
short dl_list_add_case_handler( struct dl_list *list,
                                struct dl_node *target,
                                _Bool flag){
 if(list->head == 0 && list->tail == 0 && target == 0){
  return 0;
 }

 if(target == 0){
  return -1;
 }

 if(flag == 0){
  if(target == list->head){
   return 1;
  }
  else{
   return 3;
  }
 }

 if(flag == 1){
  if(target == list->tail){
   return 2;
  }
  else{
   return 4;
  }
 }
 return -1;
}

_Bool dl_list_del_to_empty(struct dl_list **list){
 free((*list)->head);
 (*list)->head = 0;
 (*list)->tail = 0;
 return 0;
}

_Bool dl_list_del_head(struct dl_list **list){
 (*list)->head = (*list)->head->next;
 free((*list)->head->prev);
 (*list)->head->prev = 0;
 return 0;
}

_Bool dl_list_del_tail(struct dl_list **list){
 (*list)->tail = (*list)->tail->prev;
 free((*list)->tail->next);
 (*list)->tail->next = 0;
 return 0;
}

_Bool dl_list_del_between(struct dl_node **node){
 (*node)->next->prev = (*node)->prev;
 (*node)->prev->next = (*node)->next;
 free(*node);
 return 0;
}

//default fail
_Bool __dl_list_del(struct dl_list *list, struct dl_node *node, short flag){
 switch(flag){
  case 0:
   return dl_list_del_to_empty(&list);
  case 1:
   return dl_list_del_head(&list);
  case 2:
   return dl_list_del_tail(&list);
  case 3:
   return dl_list_del_between(&node);
  default:
   return 1;
 }
}

//-1 corresponds to a failed case
short dl_list_del_case_handler(struct dl_list *list, struct dl_node *node){

 if(list->head->next == 0){
  return 0;
 }

 if(list->head == node){
  return 1;
 }

 if(list->tail == node){
  return 2;
 }

 return 3;
}
