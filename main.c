#include <stdio.h>
#include <stdlib.h>
#include "dvector.h"

int main(int argc, char **argv)
{
    /* arguments parsing */
    if (argc < 2)
    {
        fprintf(stderr, "usage: append <elements>\n");
    }

    /* creating a new dynamic vector */
    dvector *new_vec;

    if (dvector_create(&new_vec))
    {
        fprintf(stderr, "error: could not create new vector\n");
        exit(1);
    }

    /* appending arguments */
    for (int i = 1; i < argc; i++)
    {
        int *element = malloc(sizeof(int));
        if (!element)
        {
            fprintf(stderr, "error: could not allocate element\n");
            exit(1);
        }
        *element = atoi(argv[i]);
        if (dvector_append(new_vec, element))
        {
            fprintf(stderr, "error: could not append element\n");
            exit(1);
        }
    }

    /* printing arguments */
    int *n = NULL;

    for (int i = 0; i < dvector_size(new_vec); i++)
    {
         n = (int *) dvector_read_element(new_vec, i);
         printf("%d ", *n);
    }

    printf("\n");

    /* destroying the vector */
    if (dvector_destroy(new_vec))
    {
        fprintf(stderr, "error: could not destroy vector\n");
        exit(1);
    }

    return 0;
}
