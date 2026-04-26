#ifndef TASK_H
#define TASK_H

#define TASK_TEXT_MAX 256

typedef struct {
    char text[TASK_TEXT_MAX];
} Task;

int task_set_text(Task *task, const char *text);

#endif