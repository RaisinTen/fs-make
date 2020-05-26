#include <stdio.h>
#include <stdlib.h>

#include "commons.h"
#include "node.h"

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
