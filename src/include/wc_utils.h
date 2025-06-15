/*
 * utils for wordcount program
 */

#ifndef WC_UTILS_H
#define WC_UTILS_H

#include "dl_list.h"
#include "wc_entry.h"
#include <stdio.h>
#include <string.h>

/*** ASCII LETTER CHECK FUNCTIONS ***/

//isal: is ascii letter
_Bool isal(uint8_t c);

//isacl: is ascii capital letter
_Bool isacl(uint8_t c);

/*** WC_ENTRY IN LIST FUNCTIONS  ***/

//get node from "list" with "word"; return null if couldn't get
struct wc_entry *wce_get(struct dl_list *list, char *word);

//if wc_entry in "list" has "word", increment that wc_entry's count
//if there is no wc_entry in "list" with "word", add new wc_entry with "word"
_Bool wce_log(struct dl_list *list, char *word, uint16_t length);

_Bool dll_print_wc(struct dl_list *list);

#endif /* WC_UTILS_H */
