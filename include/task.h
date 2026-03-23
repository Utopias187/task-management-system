#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint64_t id;
    char *title;      // heap-owned
    uint8_t done;     // 0/1
} Task;

typedef struct {
    Task *items;
    size_t len;
    size_t cap;
    uint64_t next_id;
} TaskList;

void tasklist_init(TaskList *tl);
void tasklist_free(TaskList *tl);

int tasklist_add(TaskList *tl, const char *title, uint64_t *out_id);
