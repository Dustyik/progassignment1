#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    // 6. Close the FILE*
    // 7. Print out how many lines are there in this particular filename
    // 8. Return 1, to exit program

    ssize_t line_size;
    size_t size = SHELL_BUFFERSIZE;
    char *buffer = malloc(sizeof(char) * size);
    int count = 0;

    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    FILE *fp = fopen(args[1], "r");

    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    if (fp == NULL) {
        printf("File does not exist\n");
        exit(1);
    }

    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    line_size = getline(&buffer, &size, fp);

    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    while (line_size >= 0) {
        count++;
        line_size = getline(&buffer, &size, fp);
    }

    // 6. Close the FILE*
    free(buffer);
    buffer = NULL;
    fclose(fp);

    // 7. Print out how many lines are there in this particular filename
    printf("There are %d lines in %s\n", count, args[1]);

    // 8. Return 1, to exit program
    return 1;
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}