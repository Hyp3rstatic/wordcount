#include "include/wc_utils.h"

/**********************************
    ASCII LETTER CHECK FUNCTIONS
 **********************************/

/*** EXTERNAL ***/

_Bool isal(uint8_t c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 1 : 0;
}

_Bool isacl(uint8_t c){
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

/*****************************
    WC_ENTRY LIST FUNCTIONS
 *****************************/

/*** EXTERNAL ***/

struct wc_entry *wce_get(struct dl_list *list, char *word){
    struct dl_node *tmp = list->head;
    struct wc_entry *data;
    while(tmp != NULL){
        data = (struct wc_entry*)tmp->data;
        if(strcmp(data->word, word) == 0){
            return tmp->data;
        }
        tmp = tmp->next;
    }
    return 0;
}

_Bool wce_log(struct dl_list *list,
              char *word,
              uint16_t length){
    struct wc_entry *entry = wce_get(list, word);
    char *str = (char*)malloc(sizeof(char)*(length+1));
    strncpy(str, word, length+1);
    if(entry == NULL){
        entry = wce_new(str, length);
        dll_insert_tail(list, entry);
        return 0;
    }   
    ++entry->count;
    return 0;
}

_Bool dll_print_wc(struct dl_list *list){
    if(list == NULL){
        return 1;
    }
    struct dl_node *tmp;
    struct wc_entry *data;
    printf("\n↓ ↓ ↓ HEAD ↓ ↓ ↓\n");
    tmp = list->head;
    while(tmp != NULL){ 
        data = (struct wc_entry*)tmp->data;
        printf("word: %s | length: %d | count: %d\n", data->word, data->length, data->count);
        tmp = tmp->next;
    }   
    printf("\n↓ ↓ ↓ TAIL ↓ ↓ ↓\n");
    tmp = list->tail;
    while(tmp != NULL){ 
        data = (struct wc_entry*)tmp->data;
        printf("word: %s | length: %d | count: %d\n", data->word, data->length, data->count);
        tmp = tmp->prev;
    }
    return 0;
}
