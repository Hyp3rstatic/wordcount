/*
 * word structure function definitions
 */
#include "include/wordcount.h"

const unsigned char A = 65;
const unsigned char Z = 90;
const unsigned char a = 97;
const unsigned char z = 122;

struct word *word_new(char *letters, unsigned short length, unsigned short count){
 struct word *new = (struct word*)malloc(sizeof(struct word));
 new->letters = letters;
 new->length = length;
 new->count = count;
 return new;
}

struct word *word_retrieve(struct dl_list *list, char *letters){
 struct dl_node *retriever = list->head;
 struct word *data;
 while(retriever != 0){
  data = (struct word*)retriever->data;
  if(strcmp(data->letters, letters) == 0){
   return retriever->data;
  }
  retriever = retriever->next;
 }
 return 0;
}