/*
 *  renamefile.c
 *
 *  A program for renaming files.
 *
 *  Usage: renamefile oldfilename newfilename
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *f;
    // FILE *frenamed;
    char *oldname;
    char *newname;

    // print out usage message if there are not enough arguments
    if (argc < 3) {
        printf("Usage: renamefile oldfilename newfilename\n");

    } else {
        oldname = argv[1];
        newname = argv[2];

        // check if file exists
        if ((f = fopen(oldname, "r")) == NULL) {
            fprintf(stderr, "The file you tried to rename does not exist, "
                        "please try again.\n");
            exit(1);

        } else {
            return 0;
        }
    }

    return 0;
}