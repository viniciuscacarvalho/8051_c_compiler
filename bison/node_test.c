
#include "node.h"
#include <stdio.h>

int main(int argc, char **argv) {
    // Initialize locations
    loc_t loc1 = node_loc_init(1);
    loc_t loc2 = node_loc_init(2);
    loc_t loc3 = node_loc_init(3);

    // Create some nodes
    node_t *node1 = new_node_value(&loc1, "ID", "x");
    node_t *node2 = new_node_value(&loc2, "INTEGER", "42");
    node_t *node3 = new_node_value(&loc3, "STRING", "\"hello\"");

    // Create a tree node with children
    loc_t loc4 = node_loc_merge(&loc1, &loc3);
    node_t *treeNode = new_node_tree(&loc4, "EXPRESSION", 2, node1, node2);

    // Create a concatenated node
    node_t *concatNode = node_concat(treeNode, node3);

    // Print the nodes
    printf("Node 1:\n");
    node_print(node1);
    printf("\nNode 2:\n");
    node_print(node2);
    printf("\nNode 3:\n");
    node_print(node3);
    printf("\nTree Node:\n");
    node_print(treeNode);
    printf("\nConcatenated Node:\n");
    node_print(concatNode);

    // Free the nodes (optional, but recommended to avoid memory leaks)
    // You would need to implement a `node_free` function for this.
    // For now, we'll skip it for simplicity.

    return 0;
}