/*
 * word structure function definitions
 */
#include "include/wordcount.h"

struct word *word_new(char *letters, unsigned short length, unsigned short count){
    struct word *new_word = (struct word*)malloc(sizeof(struct word));
    new_word->letters = letters;
    new_word->length = length;
    new_word->count = count;
    return new_word;
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