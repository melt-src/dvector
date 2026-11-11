/* ===============| --------------- | ===============
 *
 * D(ynamic) Vector
 *
 * This header file provides the declaration of both the structured data and
 * functions implementing basic operations on a dynamic vector, such as:
 *
 *   - insert(x, i): inserts the key 'x' in position 'i'.
 *   - delete(x)   : removes the key 'x' from the vector.
 *   - search(x)   : searches for the key 'x' in the vector and
 *                   returns its position.
 *
 * And also:
 *
 *   - prepend(x)    : head inserts the key 'x'.
 *   - append(x)     : tail inserts the key 'x'.
 *   - delete(x)     : deletes the key 'x'.
 *   - remove(x)     : deletes the key 'x' and returns it.
 *   - empty()       : checks if the vector is empty.
 *
 * ===============| --------------- | =============== */

#ifndef DVECTOR_H
#define DVECTOR_H

#include <stddef.h>

typedef struct dvector dvector;

dvector *dvector_create(void);
int dvector_destroy(dvector *);

int dvector_insert(dvector *, void *, size_t);
// int dvector_delete(dvector *, size_t);
// int dvector_search(const dvector *, void *);

// int dvector_prepend(dvector *, void *);
int dvector_append(dvector *, void *);
// void *dvector_remove(dvector *, size_t);
int dvector_empty(const dvector *);
int dvector_length(const dvector *);
int dvector_capacity(const dvector *);
void *dvector_get_element(const dvector *, size_t);

#endif /* DVECTOR_H */

/* dvector.h ends here */
