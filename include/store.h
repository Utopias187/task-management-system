#ifndef STORE_H
#define STORE_H

#include <stdio.h>
#include "task.h"

#define STORE_PATH_MAX 260

typedef struct {
    FILE *fp;
    char path[STORE_PATH_MAX];
} Store;

int store_open(Store *store, const char *path);
int store_add(Store *store, const char *text);
int store_list(Store *store);
void store_close(Store *store);

#endif