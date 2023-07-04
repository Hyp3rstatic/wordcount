/*
 * word structure function definitions
 */

#include "include/word.h"

//"length" + 1 bytes of memory allocated to word "letters"
struct word *word_new(char *letters, unsigned short length, unsigned short count){
 struct word *new = (struct word*)malloc(sizeof(struct word));
 new->letters = letters;
 new->length = length;
 new->count = count;
 return new;
}