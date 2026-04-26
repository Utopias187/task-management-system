#include <string.h>
#include "task.h"

int task_set_text(Task *task, const char *text) {
    size_t len;

    if (task == NULL || text == NULL) {
        return 0;
    }

    len = strlen(text);
    if (len == 0 || len >= TASK_TEXT_MAX) {
        return 0;
    }

    strcpy(task->text, text);
    return 1;
}