/*
 * header for wordcount specific structure and functions
 */

#ifndef WORD_H
#define WORD_H

#include "dl_list.h"
#include <stdio.h>
#include <string.h>

struct word{
 char *letters;
 unsigned short length;
 unsigned short count;
};

struct word *word_new(char *letters, unsigned short length, unsigned short count);

//retrieve the node with "letters" in list, return null if there is not
struct word *word_retrieve(struct dl_list *list, char *letters);

#endif /* WORD_H */