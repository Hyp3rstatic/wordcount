/*
 * common header for doubly-linked list structure(dl_list)
 * includes basic dl_list related functionality
 */

#ifndef DL_LIST_H
#define DL_LIST_H

#include <stdlib.h>

// set new dl_list to DL_LIST_NULL
#define DL_LIST_NULL {0, 0}

struct dl_node{
 void *data;
 struct dl_node *next;
 struct dl_node *prev;
};

struct dl_list{
 struct dl_node *head;
 struct dl_node *tail;
};

struct dl_list *dl_list_new(void);

//add node with "data" to "list" above "target"
//return 0 on success, return 1 on fail
_Bool dl_list_add_above( struct dl_list *list,
                         void  *data,
                         struct dl_node *target);

//add node with "data"  to "list" below "target"
//return 0 on success, return 1 on fail
_Bool dl_list_add_below( struct dl_list *list,
                         void *data,
                         struct dl_node *target);

//delete "node" from "list"
//return 0 on success, return 1 on fail
_Bool dl_list_del(struct dl_list *list, struct dl_node *node);

struct dl_node *dl_node_new(void *data);

_Bool dl_list_empty_add(struct dl_list **list, void *data);

_Bool dl_list_head_add(struct dl_list **list, void *data);

_Bool dl_list_tail_add(struct dl_list **list, void *data);

_Bool dl_list_add(  struct dl_list *list,
                    void *data,
                    struct dl_node *target,
                    unsigned short flag);

short dl_list_add_case_handler( struct dl_list *list,
                                struct dl_node *target,
                                _Bool flag);

_Bool dl_list_del_to_empty(struct dl_list **list);

_Bool dl_list_del_head(struct dl_list **list);

_Bool dl_list_del_tail(struct dl_list **list);

_Bool dl_list_del_between(struct dl_node **node);

_Bool __dl_list_del(struct dl_list *list, struct dl_node *node, short flag);

short dl_list_del_case_handler(struct dl_list *list, struct dl_node *node);

#endif /* DL_LIST_H */
