/*
 * header for word structure
 */

#ifndef WORD_H
#define WORD_H

#include <stdlib.h>

struct word{
 char *letters;
 unsigned short length;
 unsigned short count;
};

struct word *word_new(char *letters, unsigned short length, unsigned short count);

#endif /* WORD_H */