/*
 * dl_list function definitions
 */

#include "include/dl_list.h"

/****************************
    GENERAL NODE FUNCTIONS
 ****************************/

/*** INTERNAL ***/

static struct dl_node *_dln_new(void *data){
    struct dl_node *new_node = (struct dl_node*)malloc(sizeof(struct dl_node));
    new_node->data = data;
    return new_node;
}

/****************************
    GENERAL LIST FUNCTIONS
 ****************************/

/*** EXTERNAL ***/

struct dl_list *dll_new(void){
    struct dl_list *new_list = (struct dl_list*)malloc(sizeof(struct dl_list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

/***************************
    INSERT LIST FUNCTIONS
 ***************************/

/*** INTERNAL ***/

static _Bool _dll_insert_first(struct dl_list *list, void *data){
    //safety
    if(list == NULL || data == NULL){
        return 1;
    }
    if(list->head != NULL || list->tail != NULL){
        return 1;
    }
    //insert head and tail on the same node
    list->head = _dln_new(data);
    list->head->prev = NULL;
    list->tail = list->head;
    list->tail->next = NULL;
    return 0;
}

/*** EXTERNAL ***/

_Bool dll_insert_head(struct dl_list *list, void *data){
    //safety
    if(list == NULL || data == NULL){
        return 1;
    }
    //if no head, create tail and head with "data"
    if(list->head == NULL){
        return _dll_insert_first(list, data);
    }
    //inserting head
    list->head->prev = _dln_new(data);
    list->head->prev->next = list->head;
    list->head = list->head->prev;
    list->head->prev = NULL;
    return 0;
}

_Bool dll_insert_tail(struct dl_list *list, void *data){
    //safety
    if(list == NULL || data == NULL){
        return 1;
    }
    //if no tail, create head and tail with "data"
    if(list->tail == NULL){
        return _dll_insert_first(list, data);
    }
    //inserting tail
    list->tail->next = _dln_new(data);
    list->tail->next->prev = list->tail;
    list->tail = list->tail->next;
    list->tail->next = NULL;
    return 0;
}

_Bool dll_insert(struct dl_list *list,
                     void *data,
                     struct dl_node *target_above,
                     struct dl_node *target_below){
    //safety
    if(list == NULL || data == NULL || target_above == target_below){
        return 1;
    }
    if(target_above != NULL){
        if( (target_above->next != target_below) && target_below != NULL){
            return 1;
        }
    }
    if(target_below != NULL){
        if( (target_below->prev != target_above) && target_above != NULL){
            return 1;
        }
    }
    //inserting new head
    if(target_below == list->head){
        return dll_insert_head(list, data);
    }
    //inserting new tail
    if(target_above == list->tail){
        return dll_insert_tail(list, data);
    }
    //insert above target_below when target_above is null
    if(target_above == NULL){
        target_below->prev->next = _dln_new(data);
        target_below->prev->next->prev = target_below->prev;
        target_below->prev = target_below->prev->next;
        target_below->prev->next = target_below;
        return 0;
    }
    //insert below target_above when target_below is null
    if(target_below == NULL){
        target_above->next->prev = _dln_new(data);
        target_above->next->prev->next = target_above->next;
        target_above->next = target_above->next->prev;
        target_above->next->prev = target_above;
        return 0;
    }
    //inserting when both targets exist
    target_above->next = _dln_new(data);
    target_below->prev = target_above->next;
    target_above->next->prev = target_above;
    target_below->prev->next = target_below;
    return 0;
}

/***************************
    DELETE LIST FUNCTIONS
 ***************************/

/*** INTERNAL ***/

static _Bool _dll_delete_last(struct dl_list *list){
    //safety
    if(list == NULL){
        return 1;
    }
    if(list->head != list->tail){
        return 1;
    }
    if(list->head == NULL || list->tail == NULL){
        return 1;
    }
    //delete tail and head on the same node
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    return 0;
}

/*** EXTERNAL ***/

_Bool dll_delete_head(struct dl_list *list){
    //safety
    if(list == NULL){
        return 1;
    }
    if(list->head == NULL){
        return 1;
    }
    //if head and tail are the same delete both
    if(list->head == list->tail){
        return _dll_delete_last(list);
    }
    //delete head
    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
    return 0;
}

_Bool dll_delete_tail(struct dl_list *list){
    //safety
    if(list == NULL){
        return 1;
    }
    if(list->tail == NULL){
        return 1;
    }
    if(list->tail == list->head){
        return _dll_delete_last(list);
    }
    //delete tail
    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;
    return 0;
}

_Bool dll_delete(struct dl_list *list, struct dl_node *target){
    //safety
    if(list == NULL || target == NULL){
        return 1;
    }
    //delete target as head
    if(list->head == target){
        return dll_delete_head(list);
    }
    //delete target as tail
    if(list->tail == target){
        return dll_delete_tail(list);
    }
    //delete target as body
    target->next->prev = target->prev;
    target->prev->next = target->next;
    free(target);
    return 0;
}
