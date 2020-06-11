#include <stdio.h>
#include <stdlib.h>

#include "node.hpp"

void clear(struct Node* node)
{
    if(node)
    {
        clear(node->next);
        clear(node->children);

        free(node->name);

        node->next = NULL;
        node->children = NULL;
        node->name = NULL;

        free(node);
    }
}
