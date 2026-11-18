/* ============================ | --------------- | ============================
 *
 * D(ynamic)Vector
 *
 * This header file provides the prototipes of structured data and
 * functions implementing basic operations on a dynamic vector, such as:
 *
 * |--------------+----------------------------------------------------------|
 * | Operation    | Description                                              |
 * |--------------+----------------------------------------------------------|
 * | insert(x, i) | inserts the key 'x' in position 'i'.                     |
 * | delete(x)    | removes the key 'x' from the vector.                     |
 * | search(x)    | searches key 'x' in the vector and returns its position. |
 * |--------------+----------------------------------------------------------|
 *
 * See doc files for more.
 *
 * ============================ | --------------- | ========================== */


#ifndef DVECTOR_H
#define DVECTOR_H

#include <stddef.h>

typedef struct dvector dvector;

dvector *dvector_create(void);
void dvector_destroy(dvector *);

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
void **dvector_get_elements(const dvector *);

#endif /* DVECTOR_H */

/* dvector.h ends here */
