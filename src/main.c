#include "include/wordcount.h"

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("ERROR: usage: wordcount <filename>\n");
        return 1;
    }

    FILE *file_cp = fopen(argv[1], "r");

    FILE *file_cs = fopen(argv[1], "r");

    if(file_cp == NULL || file_cs == NULL){
        printf("ERROR: cannot open file %s\n", argv[1]);
        return 1;
    }

    struct dl_list *list = dll_new();

    struct word *word_save;

    char *letters;

    unsigned short i;

    //"cp": character primary; stops at start of word, terminates process at EOF
    //"cs": character secondary; stops while waiting for cp to catch up, does not terminate process at EOF
    char cp, cs;

    //"iw": in word; false if not, true if so
    _Bool iw = 0;

    //"lc": letter count
    unsigned short lc;

    while(cp != EOF){
        if(iw == 0){
            cp = fgetc(file_cp);
            cs = fgetc(file_cs);
            if((cp >= 'A' && cp <= 'Z') || (cp >= 'a' && cp <= 'z')){
                iw = 1;
                lc = 1;
            }
        }
        if(iw == 1){
            cs = fgetc(file_cs);
            if(cs < 'A' || (cs > 'Z' && cs < 'a') || (cs > 'z')){
                iw = 0;
                letters = (char*)malloc(sizeof(char)*lc+1);
                letters[lc] = '\0';
                for(i = 0; i < lc; i++){
                    if(cp >='A' && cp <= 'Z'){
                        cp += 32;
                    }
                    letters[i] = cp;
                    cp = fgetc(file_cp);
                }
                printf("string:%s\n", letters);
                word_save = word_retrieve(list, letters);
                if(word_save != 0){
                    ++word_save->count;
                    free(letters);
                    printf("duplicate: letters:%s length:%d count:%d\n", word_save->letters, word_save->length, word_save->count);
                }
                else{
                    dll_insert_tail(list, word_new(letters, lc, 1));
                    word_save = (struct word*)list->tail->data;
                    printf("letters:%s length:%d count:%d\n", word_save->letters, word_save->length, word_save->count);
                }
            }
            else{
                lc++;
            }
        }
        printf("%c, %c\n", cp, cs);
    }

    //FOLLOWING IS TEMPORARY EXCEPT FOR "return 0;}"
    struct dl_node *walker;

    printf("\n↓ ↓ ↓ HEAD ↓ ↓ ↓\n");
    walker = list->head;
    while(walker != 0){
        word_save = (struct word*)walker->data;
        printf("letters: %s | length: %d | count: %d\n", word_save->letters, word_save->length, word_save->count);
        walker = walker->next;
    }
    printf("\n↓ ↓ ↓ TAIL ↓ ↓ ↓\n");
    walker = list->tail;
    while(walker != 0){
        word_save = (struct word*)walker->data;
        printf("letters: %s | length: %d | count: %d\n", word_save->letters, word_save->length, word_save->count);
        walker = walker->prev;
    }
    return 0;
}
