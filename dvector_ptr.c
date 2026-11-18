
/* dvector_ptr.c */

#include <stdlib.h>
#include "dvector.h"

#define INIT_CAP 4
#define GROW_TRESH 1000

struct dvector
{
    void **elements;
    size_t capacity;
    size_t length;
};

/* grow
 *
 * Grow vector 'v's maximum capacity. Returns: 0 if there was no
 * error, 1 if the vector was NIL, 2 if there wasn't enough
 * memory. */
static int grow(dvector *v)
{
    if (!v) return 1;

    size_t nc;

    if (v->capacity <= GROW_TRESH) {
        nc = v->capacity * 2;
    } else {
        nc = v->capacity * 1.5;
    }

    void **ne = (void **) realloc(v->elements, nc * sizeof(void *));

    if (!ne) return 2;

    v->elements = ne;
    v->capacity = nc;

    return 0;
}

dvector *dvector_create(void)
{
    dvector *v = malloc(sizeof(*v));

    if (!v) return NULL;

    v->elements = (void **) malloc(INIT_CAP * sizeof(void *));

    if (!v->elements) {
        free(v);
        return NULL;
    }

    v->capacity = INIT_CAP;
    v->length = 0;

    return v;
}

void dvector_destroy(dvector *v)
{
    if (!v) return;
    // for (size_t i = 0; i < v->length; i++)
    // {
    //     free(v->elements[i]);
    // }
    free(v->elements);
    free(v);
}

/* append
 *
 * Tail insert the element 'e' into the vector 'v'. Returns: 0 if
 * there was no error, 1 if the vector is NIL, 2 if the
 * element is NIL, and 3 if grow fails to allocate new memory. */
int dvector_append(dvector *v, void *e)
{
    if (!v) return 1;
    if (!e) return 2;
    if (v->length == v->capacity) {
        if (grow(v) == 2) return 3;
    }

    v->elements[v->length] = e;
    v->length++;

    return 0;
}

int dvector_length(const dvector *v)
{
    if (!v) return -1;
    return v->length;
}

int dvector_capacity(const dvector *v)
{
    if (!v) return -1;
    return v->capacity;
}

int dvector_empty(const dvector *v)
{
    if (!v) return 2;
    return v->length == 0;
}

void *dvector_get_element(const dvector *v, size_t i)
{
    if (!v || dvector_empty(v) || i > dvector_length(v)) return NULL;
    return v->elements[i];
}

/* dvector_ptr.c ends here */
