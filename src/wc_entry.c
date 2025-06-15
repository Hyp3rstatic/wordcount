/*
 * wc_entry structure function definitions
 */

#include "include/wc_entry.h"

/********************************
    GENERAL WC_ENTRY FUNCTIONS
 ********************************/

/*** EXTERNAL **/

struct wc_entry *wce_new(char *word, uint16_t length){
    struct wc_entry *new_entry = (struct wc_entry*)malloc(sizeof(struct wc_entry));
    new_entry->word = word;
    new_entry->length = length;
    new_entry->count = 1;
    return new_entry;
}

