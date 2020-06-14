#include <cstdio>
#include <cstdlib>

#include "node.hpp"

void clear(struct Node* node)
{
    if(node)
    {
        clear(node->next);
        clear(node->children);

        free(node->name);

        node->next = nullptr;
        node->children = nullptr;
        node->name = nullptr;

        free(node);
    }
}
