#ifndef QSORT_H
#define QSORT_H

#include "wc_utils.h"
#include <time.h>

struct dl_node *dln_get(struct dl_list *list, uint32_t i);

_Bool wc_qsort(struct dl_list *list, uint32_t left, uint32_t right);

#endif /* QSORT_H */
