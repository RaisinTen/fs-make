#include <cstdio>

#include "commons.h"
#include "script_generator.h"
#include "node.h"
#include "util.h"

void generate_script(const struct Node* node)
{
    if(node->children)
    {
        generate_script_node(node->children);
    }
}

void generate_script_node(struct Node* node)
{
    while(node)
    {
        if(node->children)
        {
            // directory
            mkdir_p(node->name);
            cd(node->name);
            generate_script(node->children);
            cd("..");
        }
        else
        {
            // file
            touch(node->name);
        }

        node = node->next;
    }
}

void cd(const char* str)
{
    log_outfile("cd \"%s\"\n", str);
}

void mkdir_p(const char* str)
{
    log_outfile("mkdir -p \"%s\"\n", str);
}

void touch(const char* str)
{
    log_outfile("touch \"%s\"\n", str);
}
