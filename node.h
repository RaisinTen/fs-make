#pragma once

#ifdef _cplusplus
extern "C"
{
#endif

struct Node
{
    struct Node* children;
    struct Node* next;
    char* name;
};

void clear(struct Node*);

#ifdef _cplusplus
}
#endif
