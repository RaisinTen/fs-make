#pragma once

#ifdef _cplusplus
extern "C"
{
#endif

struct Node
{
    struct Node* children; // pointer to a singly linked list of subdirectories and files
    struct Node* next; // stores a pointer to the next node in the current directory
    char* name; // name of the file or directory
};

extern void clear(struct Node* node); // clears the memory allocated for node and its children

#ifdef _cplusplus
}
#endif
