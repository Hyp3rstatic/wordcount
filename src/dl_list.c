/*
 * dl_list function definitions
 */

#include "include/dl_list.h"

/* dl_list_add_above */
//supply a "target" in "list" for "node" to be added above, NULL as target makes "node" new "list" head
_Bool dl_list_add_above( struct dl_list *list,
                         struct dl_node *node,
                         struct dl_node *target){

//safety checks before proceeding
 if(!dl_list_check_pass_add(list, node, target)){
  return 1;
 }

//assign flag to proper number
 short flag = dl_list_add_case_handler(list, node, target, 0);

//properly add "node" to "list"

 return dl_list_add(list, node, target, flag);
}

/* dl_list_add_below */
//supply a "target" in "list" for "node" to be added below, NULL as target makes "node" new "list" tail
_Bool dl_list_add_below( struct dl_list *list,
                         struct dl_node *node,
                         struct dl_node *target){

//safety checks before proceeding
 if(!dl_list_check_pass_add(list, node, target)){
  return 1;
 }

//assign flag to proper number
short flag = dl_list_add_case_handler(list, node, target, 1);

//properly add "node" to "list"
 return dl_list_add(list, node, target, flag);
}

/* dl_list_del */
//delete "node" from "list"
_Bool dl_list_del(struct dl_list *list, struct dl_node *node){

//check if "list" or "node" are null before proceeding
 if(!dl_list_null_check_pass(list, node)){
  return 1;
 }

//assign flag to proper number
 short flag = dl_list_del_case_handler(list, node);

//properly delete "node" from "list"
 return __dl_list_del(list, node, flag);
}

//pass if "node" is not null
_Bool dl_node_valid(struct dl_node *node){
 if(node != 0){
  return TRUE;
 }
 return FALSE;
}

//return TRUE if "list" is not null
_Bool dl_list_valid(struct dl_list *list){
 if(list != 0){
  return TRUE;
 }
 return FALSE;
}

//return TRUE if "list" and "node" are not null
_Bool dl_list_null_check_pass(struct dl_list *list, struct dl_node *node){
 if(dl_list_valid(list) && dl_node_valid(node)){
  return TRUE;
 }
 return FALSE;
}

//return TRUE if "list" and "node" are not pointing to the same address
_Bool dl_list_duplicate_check_pass(struct dl_node *node, struct dl_node *target){
 if(node != target){
  return TRUE;
 }
 return FALSE;
}

//return TRUE if
//1. "list" and "node" are not null
//2. "node" and "target" are not pointing to the same adress
_Bool dl_list_check_pass_add(struct dl_list *list, struct dl_node *node, struct dl_node *target){
 if(dl_list_null_check_pass(list, node) && dl_list_duplicate_check_pass(node, target)){
  return TRUE;
 }
 return FALSE;
}

//return TRUE if "list" head is not null
_Bool dl_list_empty(struct dl_list *list){
 if(list->head == 0){
  return TRUE;
 }
 return FALSE;
}

//add "node" to empty "list"
_Bool dl_list_empty_add(struct dl_list **list, struct dl_node *node){
 (*list)->head = node;
 (*list)->tail = node;
 (*list)->head->next = 0;
 (*list)->head->prev = 0;
 return 0;
}

//make "node" the new "list" head
_Bool dl_list_head_add(struct dl_list **list, struct dl_node **node){
 (*node)->next = (*list)->head;
 (*list)->head->prev = (*node);
 (*list)->head = (*node);
 (*node)->prev = 0;
 return 0;
}

//make "node" the new "list" tail
_Bool dl_list_tail_add(struct dl_list **list, struct dl_node **node){
 (*node)->prev = (*list)->tail;
 (*list)->tail->next = (*node);
 (*list)->tail = (*node);
 (*node)->next = 0;
 return 0;
}

//add "node" above "target"
_Bool __dl_list_add_above(struct dl_node **node, struct dl_node **target){
   (*node)->prev = (*target)->prev;
   (*node)->prev->next = (*node);
   (*node)->next = (*target);
   (*target)->prev = (*node);
   return 0;
}

//add "node" below "target"
_Bool __dl_list_add_below(struct dl_node **node, struct dl_node **target){
  (*node)->next = (*target)->next;
  (*node)->next->prev = (*node);
  (*node)->prev = (*target);
  (*target)->next = (*node);
  return 0;
}

//"flag" = 0: add "node" to empty "list"
//"flag" = 1: make "node" the new "list" head
//"flag" = 2: make "node" the new "list" tail
//"flag" = 3: add "node" to "list" above "target"
//"flag" = 4: add "node" to "list" below "target"
//default is a fail
_Bool dl_list_add(  struct dl_list *list,
                    struct dl_node *node,
                    struct dl_node *target,
                    unsigned short flag){
 switch(flag){
 case 0:
  return dl_list_empty_add(&list, node);
 case 1:
  return dl_list_head_add(&list, &node);
 case 2:
  return dl_list_tail_add(&list, &node);
 case 3:
  return __dl_list_add_above(&node, &target);
 case 4:
  return __dl_list_add_below(&node, &target);
 default:
  return 1;
 }
}

//return 1 if target is null
//return 3 if target is not null
//return -1 if fail
short dl_list_add_case_handler_above(struct dl_list *list, struct dl_node *target){
 if(dl_list_node_is_head(list, target)){
  return 1;
 }
 if(dl_node_valid(target)){
  return 3;
 }
 return -1;
}

//return 2 if target is null
//return 4 if target is not null
//return -1 if fail
short dl_list_add_case_handler_below(struct dl_list *list, struct dl_node *target){
 if(dl_list_node_is_tail(list, target)){
  return 2;
 }
 if(dl_node_valid(target)){
  return 4;
 }
 return -1;
}

//"flag" = 0: adding above
//"flag" = 1: adding below
//-1 corresponds to a failed case
short dl_list_add_case_handler( struct dl_list *list,
                                struct dl_node *node,
                                struct dl_node *target,
                                _Bool flag){
 if(dl_list_empty(list) && !dl_node_valid(target)){
  return 0;
 }

 if(flag == 0){
  return dl_list_add_case_handler_above(list, target);
 }

 if(flag == 1){
  return dl_list_add_case_handler_below(list, target);
 }

 return -1;
}

//return TRUE if "list" head == "list" tail
_Bool dl_list_one_node(struct dl_list *list){
 if(list->head == list->tail){
  return TRUE;
 }
 return FALSE;
}

//return TRUE if "node" is "list" head
_Bool dl_list_node_is_head(struct dl_list *list, struct dl_node *node){
 if(list->head == node){
  return TRUE;
 }
 return FALSE;
}

//return TRUE if "node" is "list" tail
_Bool dl_list_node_is_tail(struct dl_list *list, struct dl_node *node){
 if(list->tail == node){
  return TRUE;
 }
 return FALSE;
}

//set "list" head and tail to null
_Bool dl_list_del_to_empty(struct dl_list **list){
 (*list)->head = 0;
 (*list)->tail = 0;
 return 0;
}

//delete current "list" head
_Bool dl_list_del_head(struct dl_list **list){
 (*list)->head = (*list)->head->next;
 (*list)->head->prev = 0;
 return 0;
}

//delete current "list" tail
_Bool dl_list_del_tail(struct dl_list **list){
 (*list)->tail = (*list)->tail->prev;
 (*list)->tail->next = 0;
 return 0;
}

//delete "node"
_Bool dl_list_del_between(struct dl_node **node){
 (*node)->next->prev = (*node)->prev;
 (*node)->prev->next = (*node)->next;
 return 0;
}

//"flag" = 0: delete head and tail
//"flag" = 1: delete head
//"flag" = 2: delete tail
//"flag" = 3: delete neither header nor tail
//default is a fail
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

 if(dl_list_one_node(list)){
  return 0;
 }

 if(dl_list_node_is_head(list, node)){
  return 1;
 }

 if(dl_list_node_is_tail(list, node)){
  return 2;
 }

 return 3;
}
