#ifndef TEST_DL_LIST_H
#define TEST_DL_LIST_H

#include <stdio.h>
#include "../../../src/include/dl_list.h"

struct dl_node *dl_list_get_int(struct dl_list *list, int data);

void dl_list_walk(struct dl_list *list);

#endif /* TEST_DL_LIST_H */