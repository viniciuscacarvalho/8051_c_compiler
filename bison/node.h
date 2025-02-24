#ifndef NODE_H
#define NODE_H

#include <stddef.h>

typedef struct loc {
    long begin;
    long end;
} loc_t;

typedef struct node {
    const char *type;
    const char *value;
    struct node **children;
    size_t num_children;
    loc_t loc;
} node_t;

// Function prototypes
loc_t node_loc_merge(const loc_t *start, const loc_t *end);
loc_t node_loc_init(long position);
node_t *new_node_value(loc_t *loc, const char *type, const char *value);
node_t *new_node_tree(loc_t *loc, const char *type, size_t num_children, ...);
node_t *node_concat(node_t *first, node_t *second);
void node_print(node_t *node);

#endif // NODE_H