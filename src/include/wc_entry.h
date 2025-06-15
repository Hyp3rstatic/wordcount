/*
 * header for wc_entry structure
 */

#ifndef WC_ENTRY_H
#define WC_ENTRY_H

#include <stdint.h>
#include <stdlib.h>

struct wc_entry{
    char *word;
    uint16_t length;
    uint16_t count;
};

/*** GENERAL WC_ENTRY FUNCTIONS ***/

struct wc_entry *wce_new(char *word, uint16_t length);

#endif /* WC_ENTRY_H */
