#include <stdio.h>
#include <string.h>
#include "pes.h"
#include "index.h"
#include "commit.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: pes <command> [args]\n");
        return 1;
    }

    if (strcmp(argv[1], "init") == 0) {
        cmd_init();
    }
    else if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            printf("Usage: pes add <file>...\n");
            return 1;
        }
        cmd_add(argc - 2, &argv[2]);
    }
    else if (strcmp(argv[1], "commit") == 0) {
        if (argc < 4 || strcmp(argv[2], "-m") != 0) {
            printf("Usage: pes commit -m \"message\"\n");
            return 1;
        }
        cmd_commit(argv[3]);
    }
    else if (strcmp(argv[1], "log") == 0) {
        cmd_log();
    }
    else {
        printf("Unknown command\n");
    }

    return 0;
}
