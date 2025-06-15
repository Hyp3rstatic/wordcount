#include "include/wc_qsort.h"

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

    char *letters = (char*)malloc(sizeof(char)*1);

    char cp, cs;

    //"lc": letter count
    unsigned short lc;

    //"iw": in word; false if not, true if so
    _Bool iw = 0;

    unsigned short i;

    while(cp != EOF){
        if(!iw){
            cp = fgetc(file_cp);
            cs = fgetc(file_cs);
            if(isal(cp)){
                iw = 1;
                lc = 1;
            }
        }
        if(iw){
            cs = fgetc(file_cs);
            if(!isal(cs)){
                iw = 0;
                letters = realloc(letters, sizeof(char)*(lc+1));
                letters[lc] = '\0';
                for(i = 0; i < lc; ++i){
                    if(isacl(cp)){
                        cp += 32;
                    }
                    letters[i] = cp;
                    cp = fgetc(file_cp);
                }
                wce_log(list, letters, lc);
            }
            else{
                lc++;
            }
        }
    }
    
    dll_print_wc(list);
    
    uint32_t tailpos = 1;
    for(struct dl_node *tmp = list->head; tmp != list->tail; tmp = tmp->next){
        ++tailpos;
    }
    wc_qsort(list, 0, tailpos);
    
    dll_print_wc(list);
    
    return 0;
}
