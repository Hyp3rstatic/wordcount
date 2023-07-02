/*
 * common header for doubly-linked list structure(dl_list)
 * includes basic dl_list related functionality
 */

#ifndef DL_LIST_H
#define DL_LIST_H

#include <stdlib.h>

// set new dl_node to DL_NODE_NULL
#define DL_NODE_NULL {0, 0, 0}

// set new dl_list to DL_LIST_NULL
#define DL_LIST_NULL {0, 0}

#ifndef TRUE
#define TRUE 1
#endif /* TRUE */

#ifndef FALSE
#define FALSE 0
#endif /* FALSE */

struct dl_node{
 void *data;
 struct dl_node *next;
 struct dl_node *prev;
};

struct dl_list{
 struct dl_node *head;
 struct dl_node *tail;
};

//add "node" to "list" above "target"
//return 0 on success, return 1 on fail
_Bool dl_list_add_above( struct dl_list *list,
                         struct dl_node *node,
                         struct dl_node *target);

//add "node" to "list" below "target"
//return 0 on success, return 1 on fail
_Bool dl_list_add_below( struct dl_list *list,
                         struct dl_node *node,
                         struct dl_node *target);

//delete "node" from "list" referencing the
//return 0 on success, return 1 on fail
_Bool dl_list_del(struct dl_list *list, struct dl_node *node);

_Bool dl_node_valid(struct dl_node *node);

_Bool dl_list_valid(struct dl_list *list);

_Bool dl_list_null_check_pass(struct dl_list *list, struct dl_node *node);

_Bool dl_list_duplicate_check_pass(struct dl_node *node, struct dl_node *target);

_Bool dl_list_check_pass_add(struct dl_list *list, struct dl_node *node, struct dl_node *target);

_Bool dl_list_empty(struct dl_list *list);

_Bool dl_list_empty_add(struct dl_list **list, struct dl_node *node);

_Bool dl_list_head_add(struct dl_list **list, struct dl_node **node);

_Bool dl_list_tail_add(struct dl_list **list, struct dl_node **node);

_Bool dl_list_add(  struct dl_list *list,
                    struct dl_node *node,
                    struct dl_node *target,
                    unsigned short flag);

short dl_list_add_case_handler_above(struct dl_list *list, struct dl_node *target);

short dl_list_add_case_handler_below(struct dl_list *list, struct dl_node *target);

short dl_list_add_case_handler( struct dl_list *list,
                                struct dl_node *node,
                                struct dl_node *target,
                                _Bool flag);

_Bool dl_list_node_is_head(struct dl_list *list, struct dl_node *node);

_Bool dl_list_node_is_tail(struct dl_list *list, struct dl_node *node);

_Bool dl_list_one_node(struct dl_list *list);

_Bool dl_list_del_to_empty(struct dl_list **list);

_Bool dl_list_del_head(struct dl_list **list);

_Bool dl_list_del_tail(struct dl_list **list);

_Bool dl_list_del_between(struct dl_node **node);

_Bool __dl_list_del(struct dl_list *list, struct dl_node *node, short flag);

short dl_list_del_case_handler(struct dl_list *list, struct dl_node *node);

#endif /* DL_LIST_H */
