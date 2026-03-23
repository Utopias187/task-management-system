#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "store.h"

static void print_usage(void) {
    puts("task - minimal task manager (WIP)");
    puts("");
    puts("Usage:");
    puts("  task init <path>        Create/open a database");
    puts("  task add  <path> <txt>  Add a task");
    puts("  task list <path>        List tasks");
}

int cli_run(int argc, char **argv) {
    if (argc < 2) {
        print_usage();
        return 2;
    }

    if (strcmp(argv[1], "init") == 0) {
        if (argc != 3) { print_usage(); return 2; }
        Store s;
        if (!store_open(&s, argv[2])) return 1;
        store_close(&s);
        puts("ok");
        return 0;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc < 4) { print_usage(); return 2; }
        Store s;
        if (!store_open(&s, argv[2])) return 1;
        if (!store_add(&s, argv[3])) { store_close(&s); return 1; }
        store_close(&s);
        puts("ok");
        return 0;
    }

    if (strcmp(argv[1], "list") == 0) {
        if (argc != 3) { print_usage(); return 2; }
        Store s;
        if (!store_open(&s, argv[2])) return 1;
        store_list(&s);
        store_close(&s);
        return 0;
    }

    print_usage();
    return 2;
}
