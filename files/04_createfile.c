/*
 *  createfile.c
 *
 *  A program demonstrating creating new files.
 *
 *  The program checks for the existence of a file whose name is
 *  provided by the user via the command line. If the file does not
 *  yet exist, it is created on the spot.
 *  The user can additionaly provide text to be written into the file
 *  on creation.
 *
 *  Usage: createfile filename [content]
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXNAMELENGTH 255

bool checkfile(char *filename);
bool writefile(char *filename, char *content);

int main(int argc, char *argv[])
{
    char *filename;

    if (argc < 2) {
        printf("Not enough arguments provided!\n");
        printf("Usage: createfile filename [content]\n");
    } else {
        filename = argv[1];
        char *content = argv[2];

        // check if user provided a content string
        if(content) {
            printf("Content is: %s\n", content);
        }

        if (checkfile(filename) == true) {
            printf("File %s exists!\n", filename);

        // try to create file if it does not exist yet
        } else {
            printf("File %s does not exist yet.\n", filename);
            // create file if possible
            if (writefile(filename, content) == true) {
                return 0;
            } else {
                exit(1);
            }
        }
    }
    return 0;
}

bool checkfile(char *filename) {

    FILE *f;
    if ((f = fopen(filename, "r")) != NULL) {
        return true;
        fclose(f);
    } else {
        return false;
    }
}

bool writefile(char *filename, char *content) {

    FILE *fnew;
    if ((fnew = fopen(filename, "w")) != NULL) {
        printf("Successfully created %s!\n", filename);
        // only write content into the file if content is not NULL
        if (content) {
            fprintf(fnew, "%s\n", content);
        }
        fclose(fnew);
        return true;
    // output error message if file cannot be created
    // e.g. due to missing permissions for the parent directory
    } else {
        fprintf(stderr, "Cannot write file %s.\n", filename);
        fprintf(stderr, "Check if you have the necessary permissions "
            "to write to its parent directory.\n");
        return false;
    }
}
