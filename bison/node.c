#include "node.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

loc_t node_loc_merge(const loc_t *start, const loc_t *end) {
    loc_t loc;
    loc.begin = start->begin;
    loc.end = end->end;
    return loc;
}

loc_t node_loc_init(long position) {
    loc_t loc;
    loc.begin = loc.end = position;
    return loc;
}

node_t *new_node_value(loc_t *loc, const char *type, const char *value) {
    node_t *node = malloc(sizeof(node_t));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->num_children = 0;
    node->loc = *loc;
    return node;
}

node_t *new_node_tree(loc_t *loc, const char *type, size_t num_children, ...) {
    node_t *node = malloc(sizeof(node_t));
    node->type = strdup(type);
    node->value = NULL;
    node->num_children = num_children;
    node->children = malloc(num_children * sizeof(node_t *));

    va_list args;
    va_start(args, num_children);
    for (size_t i = 0; i < num_children; i++) {
        node->children[i] = va_arg(args, node_t *);
    }
    va_end(args);

    node->loc = *loc;
    return node;
}

node_t *node_concat(node_t *first, node_t *second) {
    if (!first) return second;
    if (!second) return first;

    node_t *node = malloc(sizeof(node_t));
    node->type = strdup("CONCAT");
    node->value = NULL;
    node->num_children = 2;
    node->children = malloc(2 * sizeof(node_t *));
    node->children[0] = first;
    node->children[1] = second;
    node->loc.begin = first->loc.begin;
    node->loc.end = second->loc.end;
    return node;
}

void node_print(node_t *node) {
    if (!node) return;
    printf("Node type: %s, value: %s\n", node->type, node->value);
    for (size_t i = 0; i < node->num_children; i++) {
        node_print(node->children[i]);
    }
}