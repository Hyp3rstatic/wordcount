/*
 * header for utils in wordcount
 */

#ifndef UTIL_H
#define UTIL_H

#include "dl_list.h"
#include "word.h"
#include <stdio.h>
#include <string.h>

extern const unsigned char A;
extern const unsigned char Z;
extern const unsigned char a;
extern const unsigned char z;

//retrieve the node with "letters" in list, return null if there is not
struct word *word_retrieve(struct dl_list *list, char *letters);

#endif /* UTIL_H */