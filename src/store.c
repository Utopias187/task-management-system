#include <stdio.h>
#include <string.h>
#include "store.h"
#include "task.h"

int store_open(Store *store, const char *path) {
    if (store == NULL || path == NULL) {
        return 0;
    }

    store->fp = fopen(path, "a+");
    if (store->fp == NULL) {
        return 0;
    }

    strncpy(store->path, path, STORE_PATH_MAX - 1);
    store->path[STORE_PATH_MAX - 1] = '\0';
    return 1;
}

int store_add(Store *store, const char *text) {
    Task task;

    if (store == NULL || store->fp == NULL || text == NULL) {
        return 0;
    }

    if (!task_set_text(&task, text)) {
        return 0;
    }

    if (fseek(store->fp, 0, SEEK_END) != 0) {
        return 0;
    }

    if (fprintf(store->fp, "[ ] %s\n", task.text) < 0) {
        return 0;
    }

    fflush(store->fp);
    return 1;
}

int store_list(Store *store) {
    char line[512];
    int count = 0;

    if (store == NULL || store->fp == NULL) {
        return 0;
    }

    if (fseek(store->fp, 0, SEEK_SET) != 0) {
        return 0;
    }

    while (fgets(line, sizeof(line), store->fp) != NULL) {
        count++;
        printf("%d. %s", count, line);

        if (strchr(line, '\n') == NULL) {
            putchar('\n');
        }
    }

    if (count == 0) {
        puts("No tasks found.");
    }

    return 1;
}

void store_close(Store *store) {
    if (store == NULL) {
        return;
    }

    if (store->fp != NULL) {
        fclose(store->fp);
        store->fp = NULL;
    }
}