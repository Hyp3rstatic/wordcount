/*
 * common header for doubly-linked list structure(dl_list)
 * includes basic doubly linked list inserting and deleteting functions
 */

#ifndef DL_LIST_H
#define DL_LIST_H

#include <stdlib.h>

// set new struct dl_list to DL_LIST_NULL
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

/*** GENERAL LIST FUNCTIONS ***/

// set new struct dl_list* to dl_list_new()
struct dl_list *dll_new(void);

/*** INSERT LIST FUNCTIONS ***/

_Bool dll_insert_head(struct dl_list *list, void *data);

_Bool dll_insert_tail(struct dl_list *list, void *data);

_Bool dll_insert(struct dl_list *list,
                 void *data,
                 struct dl_node *target_above,
                 struct dl_node *target_below);

/*** DELETE LIST FUNCTIONS ***/

_Bool dll_delete_head(struct dl_list *list);

_Bool dll_delete_tail(struct dl_list *list);

_Bool dll_delete(struct dl_list *list, struct dl_node *target);

#endif /* DL_LIST_H */
