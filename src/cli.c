#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "store.h"

static void print_usage(void) {
    puts("task - minimal task manager");
    puts("");
    puts("Usage:");
    puts("  task init <path>         Create/open a database");
    puts("  task add <path> <text>   Add a task");
    puts("  task list <path>         List tasks");
}

int cli_run(int argc, char **argv) {
    if (argc < 2) {
        print_usage();
        return 2;
    }

    if (strcmp(argv[1], "init") == 0) {
        if (argc != 3) {
            print_usage();
            return 2;
        }

        Store store;
        if (!store_open(&store, argv[2])) {
            fprintf(stderr, "error: could not initialize database at '%s'\n", argv[2]);
            return 1;
        }

        store_close(&store);
        puts("ok");
        return 0;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc != 4) {
            print_usage();
            return 2;
        }

        Store store;
        if (!store_open(&store, argv[2])) {
            fprintf(stderr, "error: could not open database at '%s'\n", argv[2]);
            return 1;
        }

        if (!store_add(&store, argv[3])) {
            fprintf(stderr, "error: could not add task\n");
            store_close(&store);
            return 1;
        }

        store_close(&store);
        puts("ok");
        return 0;
    }

    if (strcmp(argv[1], "list") == 0) {
        if (argc != 3) {
            print_usage();
            return 2;
        }

        Store store;
        if (!store_open(&store, argv[2])) {
            fprintf(stderr, "error: could not open database at '%s'\n", argv[2]);
            return 1;
        }

        if (!store_list(&store)) {
            fprintf(stderr, "error: could not list tasks\n");
            store_close(&store);
            return 1;
        }

        store_close(&store);
        return 0;
    }

    print_usage();
    return 2;
}