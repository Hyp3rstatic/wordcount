#include "include/wc_qsort.h"

struct dl_node *dln_get(struct dl_list *list, uint32_t i){
    struct dl_node *tmp = list->head;
    while(i > 1){
        tmp = tmp->next;
        i--;
    }
    return tmp;
}

uint32_t partition(struct dl_list *list, uint32_t left, uint32_t right){
    srand(time(NULL));
    uint32_t random = left + rand() % (right - left);
    dll_swap(list, dln_get(list, random), dln_get(list, left));
    
    struct wc_entry *pivot = (struct wc_entry*)dln_get(list, left)->data;
    struct wc_entry *data;
    uint32_t i = left - 1, j = right + 1;
    
    while(1){
        do{
            i++;
            data = (struct wc_entry*)dln_get(list, i)->data;
        }while(data->count < pivot->count);
        do{
            j--;
            data = (struct wc_entry*)dln_get(list, j)->data;
        }while(data->count > pivot->count);

        if (i >= j)
            return j;
        
        dll_swap(list, dln_get(list, i), dln_get(list, j));
    }
}

_Bool wc_qsort(struct dl_list *list, uint32_t left, uint32_t right){
    if(left < right){
        uint32_t pivot = partition(list, left, right);
        wc_qsort(list, left, pivot);
        wc_qsort(list, pivot+1, right);
    }   
}








/*
//dll_size returns the amount of nodes in "list"
uint32_t partition_size(struct dl_node *left, struct dl_node *right){
    if(left == NULL || right == NULL){
        return -1;
    }
    struct dl_node *travel = left;
    uint32_t partition_size = 1;
    for(; travel != right; travel = travel->next){
        ++partition_size;
    }
    return partition_size;
}

struct dl_node *get_pivot(struct dl_node *left, struct dl_node *right){
    if(left == NULL || right == NULL){
        return NULL;
    }
    struct dl_node *pivot = left;
    uint32_t i;
    uint32_t pos = prand(partition_size(left, right));
    for(i = 1; i <= pos; i++){
        pivot = pivot->next;
    }
    struct wc_entry *dat = (struct wc_entry*)pivot->data;
    return pivot;
}

struct dl_node *qsort_partition(struct dl_list *list,
                      struct dl_node *left,
                      struct dl_node *right){
    uint32_t lp = dln_pos(list, left);
    printf("GETTING PIVOT\n");
    struct dl_node *pivot = get_pivot(left, right);
    printf("CHECKING LEFT\n");
    if(pivot == left){
        printf("SWITCHING LEFT\n");
        left = left->next;
        printf("IS NULL LEFT\n");
        if(left == NULL){
            printf("RETURN PIVOT\n");
            return pivot;
        }
    }
    printf("IS RIGHT PIVOT\n");
    if(right != pivot){
        printf("SWAP PIVOT AND RIGHT\n");
        dll_swap(list, pivot, right);
        printf("RIGHT IS PIVOT\n");
        right = pivot;
        printf("DECS NEXT\n");
    }
    struct dl_node *save = NULL;
    printf("HERE 1\n");
    struct dl_node *new_left;
    printf("HERE 2\n");
    struct wc_entry *p_data = (struct wc_entry*)pivot->data;
    printf("HERE 3\n");
    struct wc_entry *l_data;
    printf("HERE 4\n");
    printf("lp: %d\n", lp);
    printf("/// PIVOT START: word: %s, count: %d///\n", p_data->word, p_data->count);
    while(dln_pos(list, left) <= dln_pos(list, right)){
        printf("1\n");
        l_data = (struct wc_entry*)left->data;
        printf("2\n");
        if(save == NULL && l_data->count > p_data->count){
            printf("3\n");
            save = left;
            printf("4\n");
        }
        else if(save != NULL && l_data->count < p_data->count){
            printf("5\n");
            new_left = save;
            printf("6\n");
            save = save->next;
            printf("7\n");
            dll_swap(list, left, new_left);
            printf("8\n");
            if(left == save){
                printf("9\n");
                save = new_left;
                printf("10\n");
            }
            printf("11\n");
            left = new_left;
        }
        printf("12\n");
        left = left->next;
        if(left == NULL){
             printf("13\n");
             break;
        }
    }
    if(save != NULL){
        printf("14\n");
        dll_swap(list, pivot, save);
        right = save;
    }
    struct dl_node *tmp = list->head;
    while(lp > 1){
        tmp = tmp->next;
        p_data = (struct wc_entry*)tmp->data;
        printf("()()()()() tempstr: %s\n", p_data->word);
        --lp;
    }
    left = tmp;
    p_data = (struct wc_entry*)left->data;
    printf("$$$$$$$$$ left: %s\n", p_data->word);
    p_data = (struct wc_entry*)left->data;
    printf("/// PIVOT END: word: %s, count: %d///\n", p_data->word, p_data->count);
    if(pivot->next != NULL){
        p_data = (struct wc_entry*)pivot->next->data;
        printf("/// PIVOTNEXT: word: %s, count: %d///\n", p_data->word, p_data->count);    
    }else{printf("PIVOTNEXT NULL\n");}
    if(pivot->prev != NULL){
        p_data = (struct wc_entry*)pivot->prev->data;
        printf("/// PIVOTPREV: word: %s, count: %d///\n", p_data->word, p_data->count);
    }else{printf("PIVOTPREV NULL\n");}
    return pivot;
}

uint32_t dln_pos(struct dl_list *list, struct dl_node *node){
    if(list == NULL || node == NULL){
        printf("dln_pos: LIST OR NODE PASSED IS NULL\n");
        return 0;
    }
    if(list->head == NULL || list->tail == NULL){
        printf("dl_pos: LIST HEAD OR LIST TAIL IS NULL\n");
        return 0;
    }
    struct dl_node *travel = list->head;
    uint32_t pos = 1;
    for(;travel != NULL; travel = travel->next){
        if(travel == node){
            printf("pos: %d\n", pos);
            return pos;
        }
        ++pos;
    }
    return -1;
}

_Bool qsort_word_count(struct dl_list *list,
                       struct dl_node *left,
                       struct dl_node *right){
    uint32_t lp = dln_pos(list, left);
    uint32_t rp = dln_pos(list, right);
    if(left != NULL){
        struct wc_entry *data = (struct wc_entry*)left->data;
        printf("left->data->word: %s\n", data->word);
    }
    static uint8_t i;
    i++;
    if(list == NULL || left == NULL || right == NULL){
        printf("NULL value given\n");
        return 1;
    }
    printf("***************** qsort: %d ********************\n", i);
    dll_print_wc(list);
    if(dln_pos(list, left) >= dln_pos(list, right)){
        printf("early leave\n");
        return 0;
    }
    printf("normal plan\n");
    struct dl_node *pivot = qsort_partition(list, left, right);
    struct dl_node *tmp = list->head;
    while(lp > 1){
        tmp = tmp->next;
        --lp;
    }
    left = tmp;
    tmp = list->head;
    while(rp > 1){
        tmp = tmp->next;
        --rp;
    }
    right = tmp;
    printf("PASSED PARTITION\n");
    qsort_word_count(list, left, pivot->prev);
    printf("PASSED QSORT TWO\n");
    qsort_word_count(list, pivot->next, right);
    printf("PASSED QSORT THREE\n");
}
220     while(lp > 1){
*/
